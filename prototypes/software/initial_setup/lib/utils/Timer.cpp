//
// Created by luke on 04-12-21.
//
#include "Timer.h"

namespace Utils
{
    bool Time::Timer(TimePoint& timer, uint64_t interval)
    {
        TimePoint now = Now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(now - timer).count() >= static_cast<int64_t>(interval))
        {
            timer = Now();
            return true;
        }
        return false;
    }

    TimePoint Time::Now()
    {
        return std::chrono::high_resolution_clock::now();
    }
}

