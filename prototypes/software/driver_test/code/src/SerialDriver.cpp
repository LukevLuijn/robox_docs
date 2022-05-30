//
// Created by luke on 15-05-22.
//

#include "SerialDriver.h"

#include <utility>

#include "global_config.h"
#include "Logger.h"

namespace Driver
{
    void SerialDriver::Writer::AddToQueue(const std::string& message)
    {
        m_messageQueue.push(message);
    }
    void SerialDriver::Writer::WriteSerial(const std::string& port, uint16_t baud,
                                   const std::function<void(const char*, size_t)>& callback)
    {
        CallbackAsyncSerial serial(port, baud);
        serial.setCallback(callback);

        while (m_isRunning)
        {
            if (!m_messageQueue.empty())
            {
                try
                {
                    const std::string messageString =
                            REQUEST_START_CHAR + m_messageQueue.front() + REQUEST_STOP_CHAR;
                    serial.writeString(messageString);

                    Utils::Logger::GetInstance().Debug("Message send", messageString, __PRETTY_FUNCTION__);

                    m_messageQueue.pop();
                }
                catch (std::exception& e)
                {
                    Utils::Logger::GetInstance().Error("Error during serial write", e.what(), __PRETTY_FUNCTION__);
                }
                catch (...)
                {
                    Utils::Logger::GetInstance().Error("Error during serial write", "undefined", __PRETTY_FUNCTION__);
                }
                std::this_thread::sleep_for(std::chrono::microseconds (WRITE_DELAY_US));
            }
        }
    }
    void SerialDriver::Writer::StopWriter()
    {
        m_isRunning = false;
    }
    void SerialDriver::Writer::ReadSerial(const char* data, size_t len)
    {
        m_callback(data, len);
    }
    SerialDriver::SerialDriver(std::string  port, uint16_t baud) : m_port(std::move(port)), m_baud(baud)
    {
    }
    SerialDriver::~SerialDriver()
    {
        m_writer.StopWriter();
    }
    void SerialDriver::Start(const std::function<void(const char*, size_t)>& callback)
    {
        std::thread thread(&Writer::WriteSerial, &m_writer, m_port, m_baud, callback);
        thread.detach();
    }
    void SerialDriver::Stop()
    {
        m_writer.StopWriter();
    }
    void SerialDriver::Write(const std::string& message)
    {
        m_writer.AddToQueue(message);
    }
}// namespace Driver