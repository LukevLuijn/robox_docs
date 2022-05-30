// ======================================
// Filename:
//   Time.h
//
// Product or product-subsystem:
//   State machine test
//
// Original author:
//   Luke van Luijn
//
// Description:
//   Utility timer.
// ======================================

#ifndef ROBOX_STATE_MACHINE_TEST_UTILS_UTILS_H
#define ROBOX_STATE_MACHINE_TEST_UTILS_UTILS_H

#include <Arduino.h>

namespace Utils
{
    /**
     * @brief Checks if timer variable has reached it's interval.
     * 
     * @param time      Timer variable.
     * @param interval  Interval to check for.
     * @return true     If interval is reached.
     * @return false    if interval is not yet reached.
     */
    static bool Timer(uint32_t& time, uint32_t interval)
    {
        if (millis() - time >= interval)
        {
            time = millis();
            return true;
        }
        return false;
    }
}

#endif// ROBOX_STATE_MACHINE_TEST_UTILS_H