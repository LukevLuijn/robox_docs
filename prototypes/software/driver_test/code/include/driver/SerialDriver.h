//
// Created by luke on 15-05-22.
//

#ifndef ROBOX_USER_INTERFACE_SERIALDRIVER_H
#define ROBOX_USER_INTERFACE_SERIALDRIVER_H

#include <queue>

#include "AsyncSerial.h"

namespace Driver
{
    class SerialDriver : public boost::noncopyable
    {
    private:
        struct Writer {
            void AddToQueue(const std::string& message);
            void WriteSerial(const std::string& port, uint16_t baud, const std::function<void(const char*, size_t)>& callback);
            void StopWriter();

        private:
            void ReadSerial(const char* data, size_t len);

        private:
            std::queue<std::string> m_messageQueue;
            std::function<void(const char*, size_t)> m_callback;
            bool m_isRunning = true;
        };

    public:
        SerialDriver(std::string  port, uint16_t baud);
        virtual ~SerialDriver();

    protected:
        void Start(const std::function<void(const char*, size_t)>& callback);
        void Stop();
        void Write(const std::string& message);

    private:
        Writer m_writer;
        std::string m_port;
        uint16_t m_baud;
    };
}// namespace Driver

#endif//ROBOX_USER_INTERFACE_SERIALDRIVER_H
