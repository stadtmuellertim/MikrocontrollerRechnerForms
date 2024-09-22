#include "pch.h"
#include "SerialPort.h"

SerialPort::SerialPort()
{
    
}

SerialPort::~SerialPort()
{
    this->close();
}


std::string SerialPort::connect(const std::string& portName)
{
    // If the new device is the same as the old device the
    // port will implicitly be closed.
    if (connected == portName)
    {
        this->close();
        return "Nicht verbunden.";
    }

    // Close the port connection if it was already connected to
    // another device.
    if (this->connected != "")
        this->close();

    // Serial COM port is represented by a file-like object.
    // Try to obtain a handle by opening the file object
    // with the required parameters.
    // ioHandler is of type HANDLE which is a win-api data type.
    //
    // In order to access higher value COM ports the format has to
    // be given like "\\\\.\\COM6".
    ioHandler = CreateFileA(("\\\\.\\" + portName).c_str(),
        GENERIC_READ | GENERIC_WRITE,
        0,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr);

    // Failed to obtain a valid handle to the device.
    if (ioHandler == INVALID_HANDLE_VALUE)
    {
        DWORD error = GetLastError();

        // May occur if device was disconnected after it was found
        // to be a available COM port.
        if (error == ERROR_FILE_NOT_FOUND)
            return "Error: Gerät nicht gefunden.";
        // May occur if another application is using the device.
        else if (error == ERROR_ACCESS_DENIED)
            return "Error: Zugriff verweigert. Gerät wird womöglich bereits verwendet.";
        // All other error codes. Check winerror.h to resolve.
        else
            return "Error: Fehlercode " + std::to_string(error);
    }

    // Device control blocks hold the communication settings.
    DCB dcbSerialParams = { 0 };

    // Get the current configuration of the device.
    // Exit if that is not possible.
    if (!GetCommState(ioHandler, &dcbSerialParams))
    {
        CloseHandle(ioHandler);
        return "Error: Konfiguration konnte nicht gefunden werden.";
    }
    
    // Overwrite configuration to standard arduino usb config.
    dcbSerialParams.BaudRate = ARDUINO_BAUDRATE;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;
    dcbSerialParams.fDtrControl = DTR_CONTROL_ENABLE;

    if (!SetCommState(ioHandler, &dcbSerialParams))
    {
        CloseHandle(ioHandler);
        return "Error: Gerätekonfiguration konnte nicht gesetzt werden.";
    }

    // Instuct OS to not wait for serial communication input
    // from the device longer than 500 ms.
    COMMTIMEOUTS timeouts = {0};
    timeouts.ReadIntervalTimeout = 0;
    timeouts.ReadTotalTimeoutConstant = 0;
    timeouts.ReadTotalTimeoutMultiplier = 500;
    timeouts.WriteTotalTimeoutConstant = 0;
    timeouts.WriteTotalTimeoutMultiplier = 0;
    
    if (!SetCommTimeouts(ioHandler, &timeouts))
    {
        CloseHandle(ioHandler);
        return "Error. Timeout konnte nicht gesetzt werden.";
    }

    // The communications setup was successful.
    // Clear any old data from the ports tx/rx buffer.
    PurgeComm(ioHandler, PURGE_RXCLEAR | PURGE_TXCLEAR);

    // Obtain firmware version to find out if the connected
    // device is valid. Device should respond with the firmware version
    // or timout.
    this->write("VERSION\n");

    if (!(this->read() == COMPATIBLE_FIRMWARE_VERSION))
    {
        CloseHandle(ioHandler);
        return "Error: Unbekanntes Gerät.";
    }

    this->connected = portName;
    return "Verbunden mit " + portName + " Firmwareversion: " + COMPATIBLE_FIRMWARE_VERSION;
}

std::string SerialPort::read()
{
    DWORD bytesRead;
    char receivedByte[1];
    std::string expression = "";

    time_t startTime = time(nullptr);

    ClearCommError(ioHandler, &comErrors, &comStatus);

    // Try reading the file for 1 second.
    // Open the file in every loop cycle and read a single character from it.
    // This will act as a timeout in case the device sends to many bytes.
    // If the device doesnt send anything ReadFile() will lock up
    // and the COMMTIMEOUTS setup will force the function to return.
    while ((time(nullptr) - startTime) < 1)
    {
        if (ReadFile(ioHandler, receivedByte, 1, &bytesRead, nullptr))
        {
            if (receivedByte[0] == '\n')
                return expression;
            else
                expression.push_back(receivedByte[0]);
        }
        else
            return "Error. Keine Daten empfangen.";
    }

    return "Error. Timeout.";
}

bool SerialPort::write(const std::string& expression)
{
    DWORD bytesSent;

    if (!WriteFile(ioHandler, expression.c_str(), (DWORD)expression.length(), &bytesSent, nullptr))
    {
        ClearCommError(ioHandler, &comErrors, &comStatus);
        return false;
    }
    else
        return true;
}

bool SerialPort::close()
{
    if (connected != "")
    {
        connected = "";
        CloseHandle(this->ioHandler);

        return true;
    }
    else
        return false;
}

bool SerialPort::isConnected()
{
    if (this->connected != "")
        return true;

    return false;
}

std::string SerialPort::deviceName()
{
    return this->connected;
}