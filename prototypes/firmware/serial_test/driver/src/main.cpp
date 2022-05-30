
#include "AsyncSerial.h"
#include "Console.h"

#include <chrono>
#include <vector>

void ReceiveData(const char* data, unsigned int len);
void SendData(CallbackAsyncSerial& serial, const std::string& msg);

int main(int argc, char** argv)
{
    (void) argc;
    (void) argv;

    const std::vector<uint32_t> INTERVAL = {800,400,200,100,50,25,12,6,3,1};
    const uint8_t AMOUNT = 10;

    CallbackAsyncSerial serial("/dev/ttyACM0", 9600);
    serial.setCallback(ReceiveData);

    const std::string MSG = "[123.00,-123.00,+123.00,0.123]";

    Utils::Console::info("program start");

    for(uint32_t interval : INTERVAL)
    {
        SendData(serial, "A0[INTERVAL " + std::to_string(interval) + "]");

        Utils::Console::info("Interval start", interval);
        for(std::size_t i = 0; i < AMOUNT; ++i)
        {
            SendData(serial, 'M' + std::to_string(i) + MSG);
            Utils::Console::debug("attempt", i);
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        }
        Utils::Console::info("Interval complete");
    }

    return 0;
}

void SendData(CallbackAsyncSerial& serial, const std::string& msg)
{
    try
    {
        serial.writeString("<" + msg + ">");
    }
    catch (std::exception& e)
    {
        Utils::Console::error("Exception caught", e.what());
    }
}

void ReceiveData(const char* data, unsigned int len)
{
    (void) data; (void) len;
}
