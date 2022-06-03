//
// Created by luke on 15-05-22.
//

#include "Logger.h"

#include "LogToConsole.h"
#include "LogToWidget.h"

#include "global_config.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <thread>

namespace Utils
{
#if USING_WIDGETS
    /*static*/ LogType_e Logger::m_type = LogType_e::WX_PANEL;
#else
    /*static*/ LogType_e Logger::m_type = LogType_e::CONSOLE;
#endif

    /*static*/ bool Logger::m_whiteList[4] = {true, true, true, true};

    Logger::Logger()
    {
        switch (m_type)
        {
            case LogType_e::CONSOLE:
            {
                m_logObject = std::make_unique<LogToConsole>();
            }
            break;
#if USING_WIDGETS
            case LogType_e::WX_PANEL:
            {
                m_logObject = std::make_unique<LogToWidget>();
            }
            break;
#endif
            default:
                break;
        }
    }
    void Logger::SetLogType(LogType_e type)
    {
        m_type = type;
    }
    LogType_e Logger::GetLogType()
    {
        return m_type;
    }
    void Logger::SetVerbosityError(bool enable)
    {
        m_whiteList[static_cast<size_t>(VerbosityType_e::ERROR)] = enable;
    }
    void Logger::SetVerbosityWarning(bool enable)
    {
        m_whiteList[static_cast<size_t>(VerbosityType_e::WARNING)] = enable;
    }
    void Logger::SetVerbosityInfo(bool enable)
    {
        m_whiteList[static_cast<size_t>(VerbosityType_e::INFO)] = enable;
    }
    void Logger::SetVerbosityDebug(bool enable)
    {
        m_whiteList[static_cast<size_t>(VerbosityType_e::DEBUG)] = enable;
    }
    void Logger::LogExternal(const std::string& message)
    {
        std::vector<std::string> parts = Utils::String::Divide(message, LOG_PART_SEPARATOR);
        std::string severity = parts[static_cast<size_t>(LogParts_e::SEVERITY)];

        VerbosityType_e verbosity;

        if (severity == "ERROR")
        {
            verbosity = VerbosityType_e::ERROR;
        }
        else if (severity == "WARN")
        {
            verbosity = VerbosityType_e::WARNING;
        }
        else if (severity == "INFO")
        {
            verbosity = VerbosityType_e::INFO;
        }
        else if (severity == "TRANS")
        {
            verbosity = VerbosityType_e::TRANS;
        }
        else if (severity == "DEBUG")
        {
            verbosity = VerbosityType_e::DEBUG;
        }
        else
        {
            ERROR("Undefined severity", severity);
            verbosity = VerbosityType_e::ERROR;
        }

        LogText logText;
        logText[static_cast<size_t>(LogText_e::FUNC)] = parts[static_cast<size_t>(LogParts_e::STACKTRACE)];
        logText[static_cast<size_t>(LogText_e::VAR_STRING)] = parts[static_cast<size_t>(LogParts_e::VARIABLE)];
        logText[static_cast<size_t>(LogText_e::MESSAGE)] = parts[static_cast<size_t>(LogParts_e::MESSAGE)];
        logText[static_cast<size_t>(LogText_e::FILENAME)] = "n/a";
        logText[static_cast<size_t>(LogText_e::LINE_NUMBER)] = "n/a";

        CreateMessage(logText, verbosity, SourceType_e::EXTERNAL);
    }
    void Logger::CreateMessage(LogText& text, VerbosityType_e verbosityType, SourceType_e source, const std::string& externalTitle)
    {
        if (m_whiteList[static_cast<size_t>(verbosityType)])
        {
            LogMessage message;
            {
                auto now = std::chrono::system_clock::now();
                auto in_time_t = std::chrono::system_clock::to_time_t(now);
                std::stringstream ss;
                ss << std::put_time(std::localtime(&in_time_t), "%T");
                std::string timestamp = ss.str();
                message.m_timestamp = timestamp;
            }

            message.m_verbosityType = verbosityType;
            message.m_func = text[static_cast<size_t>(LogText_e::FUNC)];
            message.m_message = text[static_cast<size_t>(LogText_e::MESSAGE)];
            message.m_varString = text[static_cast<size_t>(LogText_e::VAR_STRING)];
            message.m_filename = text[static_cast<size_t>(LogText_e::FILENAME)];
            message.m_lineNumber = text[static_cast<size_t>(LogText_e::LINE_NUMBER)];

            message.m_sourceType = source;
            if (source == SourceType_e::EXTERNAL)
            {
                message.m_externalTitle = externalTitle;
            }

            Log(message);
        }
    }
    void Logger::Log(const LogMessage& message)
    {
        std::lock_guard<std::mutex> locker(m_logMutex);
        m_logObject->Log(message);
    }

}// namespace Utils