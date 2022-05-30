//
// Created by luke on 15-05-22.
//

#ifndef ROBOX_USER_INTERFACE_LOGGERINTERFACE_H
#define ROBOX_USER_INTERFACE_LOGGERINTERFACE_H

#define USING_WIDGETS true

#include <array>
#include <string>

#include "msg_protocol.h"
#include "LogMessage.h"

namespace Utils
{
    class ILogger
    {
    public:
        ILogger() = default;
        virtual ~ILogger() = default;

        virtual void Log(const LogMessage& message) = 0;
    };
}// namespace Interfaces

#endif//ROBOX_USER_INTERFACE_LOGGERINTERFACE_H
