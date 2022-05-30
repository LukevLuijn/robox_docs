// ======================================
// Filename:
//   Logger.h
//
// Product or product-subsystem:
//   State machine test
//
// Original author:
//   Luke van Luijn
//
// Description:
//   Utility logger.
// ======================================

#ifndef ROBOX_STATE_MACHINE_TEST_LOGGER_H
#define ROBOX_STATE_MACHINE_TEST_LOGGER_H

#include <Arduino.h>

namespace Utils
{
    class Logger
    {
    public:
        /**
     * @brief Print state transition.
     * 
     * @param id    State ID.
     * @param from  Name of source state.
     * @param to    Name of target state.
     */
        static void PrintTransition(uint16_t id, const String& from, const String& to)
        {
            Serial.print("State transition (");
            Serial.print(id);
            Serial.print(")\t[");
            Serial.print(from);
            Serial.print("]->[");
            Serial.print(to);
            Serial.println("]");
        }
    };
}// namespace Utils


#endif// ROBOX_STATE_MACHINE_TEST_LOGGER_H