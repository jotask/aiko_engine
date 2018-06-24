#pragma once

#include <SFML/System/Clock.hpp>

namespace aiko
{

    class Timer
    {
    public:
        Timer()
            : clock()
        {

        }

        auto getTimeSinceStart()
        {
            return clock.getElapsedTime();
        }

        auto restart()
        {
            clock.restart();
        }

    private:

        sf::Clock clock;

    };

    // TODO Rename the following class
    class TimeStamp
    {
    public:

        TimeStamp()
            : delta(0.0f)
        {

        };

        float delta;
    };

    class Time
    {
    public:
        auto start(const bool reset = true)
        {
            // std::chrono::time_point<std::chrono::steady_clock>
            // static std::chrono::time_point<std::chrono::steady_clock> time = std::chrono::steady_clock::now();
            // if (reset == true) time = std::chrono::steady_clock::now();
            // return time;
            return false;
        }

        auto getElapsed()
        {
            //auto start = start(false);
            //auto end = stop(false);
            //return std::chrono::duration <double, std::milli>(end - start).count();
            return false;
        }

    private:



    };

}