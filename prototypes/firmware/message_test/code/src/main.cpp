#include <Arduino.h>
#include "Message.h"

void PrintMessage(const Comm::Message& msg, const String& title)
{
    Serial.print(title);
    Serial.print(" ");
    Serial.print(msg.m_header.m_index);
    Serial.print("\t");

    uint8_t size = 0;
    Comm::Buffer buffer;
    msg.m_body.GetBuffer(buffer, size);

    Serial.print("buffer size: ");
    Serial.print(size);
    Serial.print("\t");

    for (uint8_t i = 0; i < size; ++i)
    {
        Serial.print(i);
        Serial.print(": ");
        Serial.print(buffer[i].c_str());
        Serial.print("\t");
    }
    Serial.println();
}

void setup()
{
    Serial.begin(9600);

    while (digitalRead(8) == LOW)
    {
        delay(50);
    }

    Comm::Message messages[13] = {
            Comm::Message("M0[123,123,12.3,-213]"),
            Comm::Message("M1[123,123,12.3,-213]"),
            Comm::Message("M2[123,123,12.3,-213]"),
            Comm::Message("M3[123,123,12.3,-213]"),
            Comm::Message("M4[true]"),
            Comm::Message("E0[1000]"),
            Comm::Message("E1[]"),
            Comm::Message("E2[]"),
            Comm::Message("D0[]"),
            Comm::Message("D1[]"),
            Comm::Message("C0[4000,4000]"),
            Comm::Message("C1[123.123]"),
            Comm::Message("C2[456.456]"),
    };


    for (Comm::Message msg : messages)
    {
        switch (msg.m_header.m_type)
        {
            case MessageType_e::MOVE:
                PrintMessage(msg, "MOVE");
                break;
            case MessageType_e::STOP:
                PrintMessage(msg, "STOP");

                break;
            case MessageType_e::DATA:
                PrintMessage(msg, "DATA");

                break;
            case MessageType_e::CONF:
                PrintMessage(msg, "CONFIG");

                break;
            case MessageType_e::UNDEFINED:
            default:
                Serial.println("UNDEFINED");
                break;
        }
    }
}

void loop()
{
}
