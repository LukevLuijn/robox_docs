//
// Created by luke on 15-05-22.
//

#ifndef ROBOX_USER_INTERFACE_LOGTOCONSOLE_H
#define ROBOX_USER_INTERFACE_LOGTOCONSOLE_H

#include "LoggerInterface.h"

namespace Utils
{
    class LogToConsole : public ILogger
    {
    public:
        LogToConsole() = default;
        ~LogToConsole() override = default;

        void Log(const LogMessage& message) override;

    private:
        static std::string CreateTypeString(VerbosityType_e type);
    };
}// namespace Utils

#endif//ROBOX_USER_INTERFACE_LOGTOCONSOLE_H
