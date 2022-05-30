//
// Created by luke on 15-05-22.
//

#include "LogToConsole.h"
#include "Logger.h"
#include "String.h"

namespace Utils
{
    void LogToConsole::Log(const LogMessage& message)
    {
        std::string source = "["  + message.m_externalTitle + "]";
        std::string timestamp = message.m_timestamp;
        std::string stackTrace = message.m_filename + ":" + message.m_lineNumber +" "+ message.m_func;

        std::string type = CreateTypeString(message.m_verbosityType);
        std::string text = message.m_message;
        std::string varString = message.m_varString;

        source = String::Color(source,Color_e::BRIGHT_BLUE);
        timestamp = String::Color(timestamp, Color_e::BRIGHT_BLACK);
        stackTrace = String::Color(stackTrace, Color_e::BRIGHT_BLACK);
        if (!varString.empty())
        {
            varString = String::Color(varString, Color_e::BRIGHT_WHITE);
        }

        text = String::Color(text, Color_e::BRIGHT_WHITE);


        Utils::String::Encase(timestamp, '[', ']', Color_e::BRIGHT_WHITE);
        Utils::String::Encase(stackTrace, '[', ']', Color_e::BRIGHT_WHITE);

        if (!varString.empty())
        {
            String::Encase(varString, '(', ')', Color_e::BRIGHT_CYAN);
        }

        std::string logString;

        logString += (message.m_sourceType == SourceType_e::EXTERNAL) ? source : "";
        logString += timestamp;
        logString += stackTrace;

        logString += type + "\t";
        logString += text + " ";
        logString += varString;

        std::cout << logString << std::endl;
    }
    std::string LogToConsole::CreateTypeString(VerbosityType_e type)
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
                typeString = "[WARNING]";
                color = Color_e::BRIGHT_YELLOW;
                break;
            case VerbosityType_e::INFO:
                typeString = "[INFO] ";
                color = Color_e::BRIGHT_GREEN;
                break;
            case VerbosityType_e::DEBUG:
                typeString = "[DEBUG]";
                color = Color_e::BRIGHT_MAGENTA;
                break;
            default:
                ERROR("Undefined severity", static_cast<uint16_t>(type));
                typeString = "[UNDEFINED]";
                break;
        }
        typeString = String::Color(typeString, color);
        return typeString;
    }
}// namespace Utils