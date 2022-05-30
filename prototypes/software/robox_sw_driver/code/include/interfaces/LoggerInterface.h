//
// Created by luke on 15-05-22.
//

#ifndef ROBOX_USER_INTERFACE_LOGGERINTERFACE_H
#define ROBOX_USER_INTERFACE_LOGGERINTERFACE_H

#include <array>
#include <string>
#include "msg_protocol.h"

namespace Interfaces
{
    enum class SourceType_e : uint8_t
    {
        FIRMWARE = 0,
        USER_INTERFACE = 1,
    };
    struct LogMessage {
        bool m_useTimestamp;
        bool m_useThreadId;
        bool m_useStackTrace;
        bool m_useColorOutput;

        std::string m_timestamp;
        std::string m_threadId;

        std::string m_stackTrace;
        std::string m_message;
        std::string m_varString;

        VerbosityType_e m_verbosityType;
        SourceType_e m_sourceType;
    };


    class ILogger
    {
    public:
        ILogger() = default;
        virtual ~ILogger() = default;

        virtual void Log(const LogMessage& message) = 0;
    };
}// namespace Interfaces

#endif//ROBOX_USER_INTERFACE_LOGGERINTERFACE_H
