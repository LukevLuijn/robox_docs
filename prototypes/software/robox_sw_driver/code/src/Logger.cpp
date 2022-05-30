//
// Created by luke on 15-05-22.
//

#include "Logger.h"
#include "LogToConsole.h"
#include "global_config.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <thread>

namespace Utils
{
    /*static*/ LogType_e Logger::m_type = LogType_e::CONSOLE;
    /*static*/ bool Logger::m_useStackTrace = false;
    /*static*/ bool Logger::m_useTimestamp = false;
    /*static*/ bool Logger::m_useColorOutput = true;
    /*static*/ bool Logger::m_useThreadId = false;
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
                //            case LogType_e::WX_PANEL:
                //            {
                //                m_logObject = std::make_unique<LogToWXPanel>();
                //            }
                //            break;
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
    void Logger::UseTimeStamp(bool enable)
    {
        m_useTimestamp = enable;
    }
    void Logger::UseStackTrace(bool enable)
    {
        m_useStackTrace = enable;
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
            Utils::Logger::GetInstance().Error("undefined severity", severity, __PRETTY_FUNCTION__ );
            verbosity = VerbosityType_e::ERROR;
        }

        LogText logText;
        logText[static_cast<size_t>(LogText_e::STACKTRACE)] = parts[static_cast<size_t>(LogParts_e::STACKTRACE)];
        logText[static_cast<size_t>(LogText_e::VAR_STRING)] = parts[static_cast<size_t>(LogParts_e::VARIABLE)];
        logText[static_cast<size_t>(LogText_e::MESSAGE)] = parts[static_cast<size_t>(LogParts_e::MESSAGE)];

        CreateMessage(logText, verbosity, Interfaces::SourceType_e::FIRMWARE);
    }
    void Logger::CreateMessage(LogText& text, VerbosityType_e verbosityType, Interfaces::SourceType_e source)
    {
        if (m_whiteList[static_cast<size_t>(verbosityType)])
        {
            Interfaces::LogMessage message;
            {
                auto now = std::chrono::system_clock::now();
                auto in_time_t = std::chrono::system_clock::to_time_t(now);
                std::stringstream ss;
                ss << std::put_time(std::localtime(&in_time_t), "%T");
                std::string timestamp = ss.str();
                message.m_timestamp = timestamp;
            }
            {
                std::ostringstream ss;
                ss << std::this_thread::get_id();
                std::string threadIdString = ss.str();

                message.m_threadId = threadIdString;
            }

            message.m_verbosityType = verbosityType;
            message.m_stackTrace = text[static_cast<size_t>(LogText_e::STACKTRACE)];
            message.m_message = text[static_cast<size_t>(LogText_e::MESSAGE)];
            message.m_varString = text[static_cast<size_t>(LogText_e::VAR_STRING)];

            message.m_useTimestamp = m_useTimestamp;
            message.m_useThreadId = m_useThreadId;
            message.m_useStackTrace = m_useStackTrace;
            message.m_useColorOutput = m_useColorOutput;
            message.m_sourceType = source;

            Log(message);
        }
    }
    void Logger::Log(const Interfaces::LogMessage& message)
    {
        std::lock_guard<std::mutex> locker(m_logMutex);
        m_logObject->Log(message);
    }

}// namespace Utils