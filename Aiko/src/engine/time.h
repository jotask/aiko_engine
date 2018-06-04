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

}