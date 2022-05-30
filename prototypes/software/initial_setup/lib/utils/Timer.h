//
// Created by luke on 04-12-21.
//

#ifndef TIMER_TIMER_H
#define TIMER_TIMER_H

#include <chrono>
#include <functional>
#include <thread>

namespace Utils
{
    typedef std::chrono::time_point<std::chrono::system_clock> TimePoint;

    class Time
    {
    public:
        static bool Timer(TimePoint & timer, uint64_t interval);
        static TimePoint Now();

        template<class callable, class... arguments>
        static uint64_t ExecutionTime(callable&& func, arguments&&... args)
        {
            std::function<typename std::result_of<callable(arguments...)>::type()> task(
                    std::bind(std::forward<callable>(func), std::forward<arguments>(args)...));

            auto start = std::chrono::high_resolution_clock::now();
            task();
            auto stop = std::chrono::high_resolution_clock::now();

            int64_t time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
            return static_cast<uint64_t>(time);
        }

        template<class callable, class... arguments>
        static void Callback(uint64_t after, bool async, callable&& f, arguments&&... args)
        {
            std::function<typename std::result_of<callable(arguments...)>::type()> task(
                    std::bind(std::forward<callable>(f), std::forward<arguments>(args)...));

            if (async)
            {
                std::thread([after, task]() {
                    std::this_thread::sleep_for(std::chrono::milliseconds(after));
                    task();
                }).detach();
            }
            else
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(after));
                task();
            }
        }
    };
}// namespace Utils

#endif//TIMER_TIMER_H
