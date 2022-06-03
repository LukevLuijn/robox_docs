#include "Reader.h"
#include <Arduino.h>

void setup()
{
    Serial.begin(9600);
    delay(1000);

    Serial.println("Hello world");

    Reader::GetInstance().Start();
}

void loop()
{
    Reader::GetInstance().Run();

    if (!Reader::GetInstance().QueueEmpty())
    {
        Serial.print("RECIEVED: ");
        Comm::Message msg = Reader::GetInstance().GetMessage();

        Serial.print((char) msg.m_header.m_type);
        Serial.print(msg.m_header.m_index);
        Serial.print(" ");

        Comm::Buffer buffer;
        uint8_t bufferSize;

        msg.m_body.GetBuffer(buffer, bufferSize);

        Serial.print("SIZE: ");
        Serial.print(bufferSize);

        for (uint8_t i = 0; i < bufferSize; ++i)
        {
          Serial.print(" [");
          Serial.print(buffer[i]);
          Serial.print("]");

          Serial.print("(");
          Serial.print(buffer[i].length());
          Serial.print(")");
        }

        Serial.print("\n");
    }
}