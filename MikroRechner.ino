#define FIRMWARE_VERSION "1.0\n"

#define PLUS_OPERATION  1
#define MINUS_OPERATION 2
#define MULT_OPERATION  3
#define DIV_OPERATION   4

#include "time.h"

String expression;
char receivedByte;

void setup()
{
    // Initial setup.
    Serial.begin( 9600 );
}


void loop()
{
    // Main loop.

    // Wait for serial communication.
    // Append incoming bytes to the expression string.
    if( Serial.available() )
    {
        receivedByte = Serial.read();
        expression.concat( receivedByte );
    }

    // Complete expressions or commands always end with the '\n' character as terminator.
    if( expression.endsWith("\n") )
    {
        // Alow the users PC to prepare to receive.
        delay(10);

        // Device identifier and firmware info if requested by user.
        if( expression == "VERSION\n" )
            Serial.write( FIRMWARE_VERSION );
        else
        {
            // --- INPUT PARSING ---
            // Remove '\n' from the end.
            expression = expression.substring( 0, expression.length() - 1 );

            // Variables "reset" for every new received expression.
            String term1, term2 = "";
            int operation = 0;

            // Expected expression format:
            // "[term][operator][term]"

            // Expression can only contain numbers {0...9} and operators {+-*/} to be valid.
            // Only specific syntax errors can occur by user input because of the limited options
            // of the graphical UI of the control software.

            // Iterate through the expression char by char.
            // Fill the first and second term according to the
            // expected format and set the operation.
            for( int i = 0; i < expression.length(); i++ )
            {
                // Character is a number in {0...9} or a leading minus sign for negative numbers.
                if( isDigit( expression[i] ) || (i == 0 && expression[i] == '-') )
                {
                    // If the operator was not yet received the number
                    // is appended to the first term otherwise to the second term.
                    if( operation == 0 )
                        term1 += expression[i];
                    else
                        term2 += expression[i];
                }
                else
                {
                    // Character is an operator in {+-*/} (except leading minus sign).
                    // Possible syntax errors can be:
                    // A: Two operators are given. In this case operator > 0.
                    //      "45+-50" or "40+50+60"
                    // B: Operator at beginning/end or missing term. Determined by the value of i.
                    //      "*40+50" or "50+"
                    // C: Floating point numbers or error message transmitted back. Character at i is a period.
                    //      "Error: Syntaxfehler.", "4.000+50"
                    if( operation > 0 || i == 0 || i == expression.length() - 1 || expression[i] == '.' )
                    {
                        Serial.print( "Error: Sytnaxfehler." );
                        Serial.write( '\n' );
                        expression = "";
                        return;
                    }

                    switch( expression[i] )
                    {
                        case '+':
                            operation = PLUS_OPERATION; break;
                        case '-':
                            operation = MINUS_OPERATION; break;
                        case '*':
                            operation = MULT_OPERATION; break;
                        case '/':
                            operation = DIV_OPERATION; break;
                    }
                }
            }

            // --- RESULT CALCULATION ---
            // Main concern from here on is datatype overflow.
            // If an overflow occurs the behaviour is undefined.

            // The Arduino R4 chip has a 32 bit architecture.
            // int and long in this case are both 4 bytes in size.
            // First bit is the "sign" bit showing a negative number.
            // This results in a number range of
            // -(2^31)...0...(2^31)-1
            // -2,147,483,648...2,147,483,647

            // toInt() will return the maximum value of the datatype if the
            // number represented by the String is greater than the maximum
            // number that can be stored with the int datatype.
            int number1 = term1.toInt();
            int number2 = term2.toInt();

            // Check if one of the numbers exceeds the datatype limit.
            // Convert the numbers back to Strings and compare them to the original.
            // This already prevents some overflow scenarios before the calculation.
            if(!(String(number1) == term1) || (term2 != "" && !(String(number2) == term2)) )
            {
                Serial.print( "Error: Zu wenig Speicher." );
                Serial.write( '\n' );
                expression = "";
                return;
            }

            // The actual calculation is done in 64 bit.
            // The result is then validated by bit wise comparison
            // to detect a possible overflow.
            // If the operation is safe the result will be converted
            // and transmitted.
            uint_fast64_t iRes;
            String result;

            switch( operation )
            {
                case PLUS_OPERATION:
                    iRes = number1 + number2;

                    // Overflow if the result needs more than 31 bits.
                    if( iRes & 0x100000000 )
                        result = "Error. Zu wenig Speicher.";
                    else
                        result = String((int)iRes);
                    break;

                case MINUS_OPERATION:
                    iRes = number1 - number2;

                    // The minus operation here can only overflow below the negative maximum.
                    // In this case the sign bit shifts to the left into the 64 bit number.
                    if( number1 < 0 && !(iRes & 0x100000000) )
                        result = "Error. Zu wenig Speicher.";
                    else
                        result = String((int)iRes);
                    break;

                case MULT_OPERATION:
                    iRes = number1 * number2;

                    // If the result needs more than 31 bits it would overflow.
                    if( number1 > 0 && iRes & 0x100000000 )
                        result = "Error. Zu wenig Speicher.";
                    else
                        result = String((int)iRes);
                    break;

                case DIV_OPERATION:
                    // No overflow possible but check for zero division.
                    if( number2 == 0 )
                        result = "Error. Division durch 0.";
                    else
                        result = String( (double)number1 / (double)number2, 8 );
                    break;

                case 0:
                    result = String( number1 );
                    break;
            }

            Serial.print( result.c_str() );
            Serial.write( '\n' );
            
            
        }

        expression = "";
    }
}
