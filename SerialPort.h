#pragma once

#define COMPATIBLE_FIRMWARE_VERSION "1.0"
#define ARDUINO_BAUDRATE 9600

#include <Windows.h>
#include <string>


class SerialPort
{
    private:
        HANDLE ioHandler;
        COMSTAT comStatus;
        DWORD comErrors;

        std::string connected = "";

    public:
        SerialPort();
        ~SerialPort();

        std::string connect(const std::string& portName);
        bool isConnected();
        std::string deviceName();

        std::string read();
        bool write(const std::string& data_sent);
        bool close();
};
