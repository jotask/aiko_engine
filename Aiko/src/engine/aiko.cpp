#include "aiko.h"

// STL
#include <iostream>
#include <cassert>

// SFML
#include <SFML/Graphics.hpp>

// aiko
#include "../constants.h"
#include "../code_art_lines/code.h"
#include "../labyrinth/labyrinth.h"
#include "../flappy_bird/flappy_bird.h"
#include "physics/physics.h"
#include "time.h"

namespace aiko
{

    Aiko::Aiko()
        : m_kimo(nullptr)
        , m_state(START_STATE)
    {

    }

    Aiko::~Aiko()
    {

    }

    void Aiko::init()
    {

        aiko::physics::Physics::get();

        switch (m_state)
        {
        case STATE::LABYRINTH:
            m_kimo.reset(new labyrinth::Lab());
            break;
        case STATE::CODE:
            m_kimo.reset(new code::Code());
            break;
        case STATE::FLAPPYBIRD:
            m_kimo.reset(new flappybird::FlappyBird());
            break;
        default:
            assert(false);
        }

    }

    void Aiko::run()
    {

        sf::RenderWindow renderWindow;
        sf::Event event;
        sf::Clock clock;

        float delta = 0.0f;

        renderWindow.create(sf::VideoMode(WIDTH, HEIGHT), "SFML Demo");

        init();

        auto& physics = aiko::physics::Physics::get();
        physics.init(renderWindow);

        TimeStamp timeStamp;

        while (renderWindow.isOpen()) {
            // Check for all the events that occured since the last frame.
            while (renderWindow.pollEvent(event)) {
                //Handle events here
                if (event.type == sf::Event::EventType::Closed)
                {
                    renderWindow.close();
                }
                physics.input(event);
            }

            // A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
            timeStamp.delta = clock.getElapsedTime().asSeconds();
            //std::cout << "Elapsed time since previous frame(microseconds): " << delta << std::endl;

            // Start the countdown over.  Think of laps on a stop watch.
            clock.restart();
            // update start
            physics.update(timeStamp);
            m_kimo->update(timeStamp);
            // update end
            renderWindow.clear();
            // renderstar
            m_kimo->render(renderWindow);
            // debug
            physics.render(renderWindow);
            // render end
            renderWindow.display();
        }

    }

}