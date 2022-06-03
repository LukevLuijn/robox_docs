//
// Created by luke on 15-05-22.
//

#ifndef ROBOX_USER_INTERFACE_LOGGER_H
#define ROBOX_USER_INTERFACE_LOGGER_H

#include <memory>
#include <mutex>

#include "LoggerInterface.h"
#include "String.h"

// https://cppcodetips.wordpress.com/2020/10/25/different-ways-to-get-the-name-of-the-calling-function-in-c/
// https://stackoverflow.com/questions/353180/how-do-i-find-the-name-of-the-calling-function


namespace Utils
{
    enum class LogType_e : uint8_t
    {
        CONSOLE = 0,
        WX_PANEL = 1,
    };
    enum class LogText_e : uint8_t
    {
        MESSAGE = 0,
        STACKTRACE = 1,
        VAR_STRING = 2,
    };

    typedef std::array<std::string, 3> LogText;

    class Logger
    {
    public:
        Logger(const Logger& other) = delete;
        Logger& operator=(const Logger& other) = delete;
        virtual ~Logger() = default;

        static Logger& GetInstance()
        {
            static Logger instance;
            return instance;
        }

    private:
        Logger();

    public:
        static void SetLogType(LogType_e type);
        static LogType_e GetLogType();

        static void UseTimeStamp(bool enable);
        static void UseStackTrace(bool enable);

        static void SetVerbosityError(bool enable);
        static void SetVerbosityWarning(bool enable);
        static void SetVerbosityInfo(bool enable);
        static void SetVerbosityDebug(bool enable);

        void LogExternal(const std::string& message);

        void Error(const std::string& text, const std::string& caller)
        {
            LogText message;
            message[static_cast<size_t>(LogText_e::STACKTRACE)] = caller;
            message[static_cast<size_t>(LogText_e::MESSAGE)] = text;
            message[static_cast<size_t>(LogText_e::VAR_STRING)] = "";
            CreateMessage(message, VerbosityType_e::ERROR);
        }
        template<typename T>
        void Error(const std::string& text, T var, const std::string& caller)
        {
            LogText message;
            message[static_cast<size_t>(LogText_e::STACKTRACE)] = caller;
            message[static_cast<size_t>(LogText_e::MESSAGE)] = text;
            message[static_cast<size_t>(LogText_e::VAR_STRING)] = CreateVarString(var);

            CreateMessage(message, VerbosityType_e::ERROR);
        }
        template<typename T>
        void Error(const std::string& text, std::vector<T>& vars, const std::string& caller)
        {
            LogText message;
            message[static_cast<size_t>(LogText_e::STACKTRACE)] = caller;
            message[static_cast<size_t>(LogText_e::MESSAGE)] = text;
            message[static_cast<size_t>(LogText_e::VAR_STRING)] = CreateVarString(vars);
            CreateMessage(message, VerbosityType_e::ERROR);
        }
        void Warning(const std::string& text, const std::string& caller)
        {
            LogText message;
            message[static_cast<size_t>(LogText_e::STACKTRACE)] = caller;
            message[static_cast<size_t>(LogText_e::MESSAGE)] = text;
            message[static_cast<size_t>(LogText_e::VAR_STRING)] = "";
            CreateMessage(message, VerbosityType_e::WARNING);
        }
        template<typename T>
        void Warning(const std::string& text, T var, const std::string& caller)
        {
            LogText message;
            message[static_cast<size_t>(LogText_e::STACKTRACE)] = caller;
            message[static_cast<size_t>(LogText_e::MESSAGE)] = text;
            message[static_cast<size_t>(LogText_e::VAR_STRING)] = CreateVarString(var);
            CreateMessage(message, VerbosityType_e::WARNING);
        }
        template<typename T>
        void Warning(const std::string& text, std::vector<T>& vars, const std::string& caller)
        {
            LogText message;
            message[static_cast<size_t>(LogText_e::STACKTRACE)] = caller;
            message[static_cast<size_t>(LogText_e::MESSAGE)] = text;
            message[static_cast<size_t>(LogText_e::VAR_STRING)] = CreateVarString(vars);
            CreateMessage(message, VerbosityType_e::WARNING);
        }
        void Info(const std::string& text, const std::string& caller)
        {
            LogText message;
            message[static_cast<size_t>(LogText_e::STACKTRACE)] = caller;
            message[static_cast<size_t>(LogText_e::MESSAGE)] = text;
            message[static_cast<size_t>(LogText_e::VAR_STRING)] = "";
            CreateMessage(message, VerbosityType_e::INFO);
        }
        template<typename T>
        void Info(const std::string& text, T var, const std::string& caller)
        {
            LogText message;
            message[static_cast<size_t>(LogText_e::STACKTRACE)] = caller;
            message[static_cast<size_t>(LogText_e::MESSAGE)] = text;
            message[static_cast<size_t>(LogText_e::VAR_STRING)] = CreateVarString(var);
            CreateMessage(message, VerbosityType_e::INFO);
        }
        template<typename T>
        void Info(const std::string& text, std::vector<T>& vars, const std::string& caller)
        {
            LogText message;
            message[static_cast<size_t>(LogText_e::STACKTRACE)] = caller;
            message[static_cast<size_t>(LogText_e::MESSAGE)] = text;
            message[static_cast<size_t>(LogText_e::VAR_STRING)] = CreateVarString(vars);
            CreateMessage(message, VerbosityType_e::INFO);
        }
        void Debug(const std::string& text, const std::string& caller)
        {
            LogText message;
            message[static_cast<size_t>(LogText_e::STACKTRACE)] = caller;
            message[static_cast<size_t>(LogText_e::MESSAGE)] = text;
            message[static_cast<size_t>(LogText_e::VAR_STRING)] = "";
            CreateMessage(message, VerbosityType_e::DEBUG);
        }
        template<typename T>
        void Debug(const std::string& text, T var, const std::string& caller)
        {
            LogText message;
            message[static_cast<size_t>(LogText_e::STACKTRACE)] = caller;
            message[static_cast<size_t>(LogText_e::MESSAGE)] = text;
            message[static_cast<size_t>(LogText_e::VAR_STRING)] = CreateVarString(var);
            CreateMessage(message, VerbosityType_e::DEBUG);
        }
        template<typename T>
        void Debug(const std::string& text, std::vector<T>& vars, const std::string& caller)
        {
            LogText message;
            message[static_cast<size_t>(LogText_e::STACKTRACE)] = caller;
            message[static_cast<size_t>(LogText_e::MESSAGE)] = text;
            message[static_cast<size_t>(LogText_e::VAR_STRING)] = CreateVarString(vars);
            CreateMessage(message, VerbosityType_e::DEBUG);
        }

    private:
        template<typename T>
        std::string CreateVarString(T var)
        {
            return Utils::String::ToString(var);
        }

        template<typename T>
        std::string CreateVarString(const std::vector<T>& vars)
        {
            std::vector<std::string> strVars = Utils::String::ToString(vars);
            std::string varString;

            for (auto it = strVars.begin(); it != strVars.end(); ++it)
            {
                varString += *it + ((std::next(it) != strVars.end()) ? "," : "");
            }
            return varString;
        }

        void CreateMessage(LogText& text, VerbosityType_e verbosityType,
                           Interfaces::SourceType_e source = Interfaces::SourceType_e::USER_INTERFACE);
        void Log(const Interfaces::LogMessage& message);

    private:
        const uint8_t VERB_HEADER_SIZE = 5 + 2;// largest verb size + brackets.

        std::mutex m_logMutex;
        std::unique_ptr<Interfaces::ILogger> m_logObject;

        static LogType_e m_type;
        static bool m_useStackTrace;
        static bool m_useTimestamp;
        static bool m_useColorOutput;
        static bool m_useThreadId;

        static bool m_whiteList[4];
    };
}// namespace Utils

#endif//ROBOX_USER_INTERFACE_LOGGER_H
