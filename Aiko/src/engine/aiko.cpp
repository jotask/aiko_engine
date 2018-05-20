#include "aiko.h"

// STL
#include <iostream>
#include <cassert>

// SFML
#include <SFML/Graphics.hpp>

// aiko
#include "../constants.h"
#include "../code.h"
#include "../lab.h"
#include "time.h"

Aiko::Aiko()
    : m_kimo(nullptr)
    , m_state(STATE::LABYRINTH)
{
    DBOUT("The value of x is " << 10);
}

Aiko::~Aiko()
{

}

void Aiko::init()
{

    switch (m_state)
    {
    case STATE::LABYRINTH:
        m_kimo.reset(new Lab());
        break;
    case STATE::CODE:
        m_kimo.reset(new Code());
        break;
    default:
        assert(false);
    }

}

void Aiko::run()
{

    // assert(m_kimo != nullptr);

    sf::RenderWindow renderWindow;
    sf::Event event;
    sf::Clock clock;

    float delta = 0.0f;

    renderWindow.create(sf::VideoMode(WIDTH, HEIGHT), "SFML Demo");

    init();

    TimeStamp timeStamp;

    while (renderWindow.isOpen()) {
        // Check for all the events that occured since the last frame.
        while (renderWindow.pollEvent(event)) {
            //Handle events here
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();
        }

        // A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
        timeStamp.delta = clock.getElapsedTime().asSeconds();
        //std::cout << "Elapsed time since previous frame(microseconds): " << delta << std::endl;

        // Start the countdown over.  Think of laps on a stop watch.
        clock.restart();
        // update start
        m_kimo->update(timeStamp);
        // update end
        renderWindow.clear();
        // renderstar
        m_kimo->render(renderWindow);
        // render end
        renderWindow.display();
    }

}