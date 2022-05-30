#ifndef ROBOX_SERIAL_TEST_READER_H
#define ROBOX_SERIAL_TEST_READER_H

#include <Arduino.h>
#include <queue>

#include "Message.h"
#include "config/config.h"

class Reader
{
public:
    Reader(const Reader& other) = delete;
    Reader& operator=(const Reader& other) = delete;
    virtual ~Reader() = default;

    static Reader& GetInstance()
    {
        static Reader instance;
        return instance;
    }

private:
    Reader()
    {
    }

public:
    void Start();
    void Run();

    Comm::Message GetMessage();
    void WriteMessage(const String& string);
    bool QueueEmpty();

private:
    void SortMessages(const String& string);
    void ReadSerial();

private:
    char m_reading[MESSAGE_SIZE];
    std::queue<Comm::Message> m_messageQueue;
};


#endif// ROBOX_SERIAL_TEST_READER_H