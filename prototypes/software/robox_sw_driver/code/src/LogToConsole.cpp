//
// Created by luke on 15-05-22.
//

#include "LogToConsole.h"
#include "String.h"

namespace Utils
{
    void LogToConsole::Log(const Interfaces::LogMessage& message)
    {
        std::string source = (message.m_sourceType == Interfaces::SourceType_e::USER_INTERFACE) ? "[INT]" : "[EXT]";
        std::string timestamp = message.m_timestamp;
        std::string threadId = message.m_threadId;
        std::string stackTrace = message.m_stackTrace;

        std::string type = CreateTypeString(message.m_verbosityType, message.m_useColorOutput);
        std::string text = message.m_message;
        std::string varString = message.m_varString;

        if (message.m_useColorOutput)
        {
            source = String::Color(source,(message.m_sourceType == Interfaces::SourceType_e::USER_INTERFACE) ? Color_e::NORMAL_GREEN : Color_e::NORMAL_BLUE);
            timestamp = String::Color(timestamp, Color_e::BRIGHT_BLACK);
            threadId = String::Color(threadId, Color_e::BRIGHT_BLACK);
            stackTrace = String::Color(stackTrace, Color_e::BRIGHT_BLACK);
            if (!varString.empty())
            {
                varString = String::Color(varString, Color_e::BRIGHT_WHITE);
            }

            text = String::Color(text, Color_e::BRIGHT_WHITE);
        }
        Utils::String::Encase(timestamp, '[', ']', Color_e::BRIGHT_WHITE);
        Utils::String::Encase(threadId, '[', ']', Color_e::BRIGHT_WHITE);
        Utils::String::Encase(stackTrace, '[', ']', Color_e::BRIGHT_WHITE);

        if (!varString.empty())
        {
            String::Encase(varString, '(', ')', (message.m_useColorOutput) ? Color_e::BRIGHT_CYAN : Color_e::NONE);
        }

        std::string logString;
        if (message.m_useTimestamp)
        {
            logString += timestamp;
        }
        if (message.m_useThreadId)
        {
            logString += threadId;
        }
        if (message.m_useStackTrace)
        {
            logString += stackTrace;
        }

        if (!logString.empty())
        {
            logString += "\n";
        }

        logString += source;
        logString += type + "\t";
        logString += text + " ";
        logString += varString;

        std::cout << logString << std::endl;
    }
    std::string LogToConsole::CreateTypeString(VerbosityType_e type, bool useColor)
    {
        std::string typeString;
        Color_e color = Color_e::NONE;

        switch (type)
        {
            case VerbosityType_e::ERROR:
                typeString = "[ERROR]";
                color = Color_e::BRIGHT_RED;
                break;
            case VerbosityType_e::WARNING:
                typeString = "[WARN]";
                color = Color_e::BRIGHT_YELLOW;
                break;
            case VerbosityType_e::INFO:
                typeString = "[INFO]";
                color = Color_e::BRIGHT_GREEN;
                break;
            case VerbosityType_e::DEBUG:
                typeString = "[DEBUG]";
                color = Color_e::BRIGHT_MAGENTA;
                break;
            default:
                // TODO error
                typeString = "[UNDEFINED]";
                break;
        }

        if (useColor)
        {
            typeString = String::Color(typeString, color);
        }
        return typeString;
    }
}// namespace Utils