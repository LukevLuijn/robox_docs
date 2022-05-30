
#include "Reader.h"

void Reader::Start()
{
    if (!Serial)
    {
        Serial.begin(BAUDRATE);
        delay(1000);

        Serial.println("Hello world!");
    }
}
void Reader::Run()
{
    ReadSerial();
}
Comm::Message Reader::GetMessage()
{
    Comm::Message message("00[]");

    if (!m_messageQueue.empty())
    {
        message = m_messageQueue.front();
        m_messageQueue.pop();
    }
    return message;
}
void Reader::WriteMessage(const String& msgString)
{
    String message = MESSAGE_START_CHAR + msgString + MESSAGE_STOP_CHAR;
    Serial.write(message.c_str());
    Serial.send_now();
}
bool Reader::QueueEmpty()
{
    return m_messageQueue.empty();
}
void Reader::SortMessages(const String& string)
{
    Comm::Message message(string);

    if (message.m_header.m_type == MessageType_e::STOP && message.m_header.m_index == (uint8_t) StopType_e::ESTOP)
    {
        // Base::Robot::GetInstance().DisableRobot();
        Serial.println("E-STOP requested");
    }
    else
    {
        m_messageQueue.push(message);
    }
}
void Reader::ReadSerial()
{
    bool newMessage = false;
    static bool inProgress = false;
    static byte ndx = 0;

    char readChar;

    while ((Serial.available() > 0) && !newMessage)
    {
        readChar = Serial.read();

        if (inProgress)
        {
            if (readChar != MESSAGE_STOP_CHAR)
            {
                m_reading[ndx] = readChar;
                ++ndx;

                if (ndx >= MESSAGE_SIZE)
                {
                    ndx = MESSAGE_SIZE - 1;
                }
            }
            else
            {
                m_reading[ndx] = '\0';
                inProgress = false;
                ndx = 0;

                SortMessages(m_reading);
            }
        }
        else if (readChar == MESSAGE_START_CHAR)
        {
            inProgress = true;
        }
    }
}