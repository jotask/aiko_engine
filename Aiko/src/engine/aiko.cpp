#include "aiko.h"

// STL
#include <iostream>
#include <cassert>
#include <chrono>
#include <thread>
#include <future>

#include<GL/glew.h>

// SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

// aiko
#include "../constants.h"
#include "../code_art_lines/code.h"
#include "../labyrinth/labyrinth.h"
#include "../flappy_bird/flappy_bird.h"
#include "../opengl/opengl.h"
#include "../mandelbrot/mandelbrot.h"
#include "../barnsleyfern/barnsleyfern.h"
#include "physics/physics.h"
#include "time.h"

#include "entities/EntityManager.h"

namespace aiko
{

    Aiko::Aiko()
        : m_kimo(nullptr)
        , m_state(START_STATE)
        , m_renderWindow(nullptr)
        , m_isOpengl(true)
    {

    }

    Aiko::~Aiko()
    {
        if (m_renderWindow->isOpen() == true) m_renderWindow->close();
        delete m_renderWindow;
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
        case STATE::MANDELBROT:
            m_kimo.reset(new mandelbrot::Mandelbrot());
            break;
        case STATE::BARNSLEYFERN:
            m_kimo.reset(new barnsleyfern::BarnsleyFern());
            break;
        case STATE::OPENGL:
            m_kimo.reset(new opengl::Opengl());
            break;
        default:
            assert(false);
        }

    }

    void Aiko::run()
    {

        sf::Event event;
        sf::Clock clock;

        float delta = 0.0f;

        static constexpr auto title = "Aiko Engine  Demo";

        m_renderWindow = new sf::RenderWindow();

        // renderWindow.create(sf::VideoMode(WIDTH, HEIGHT), title, sf::Style::None);

        sf::ContextSettings settings;
        settings.depthBits = 24;
        settings.stencilBits = 8;
        settings.majorVersion = 3;
        settings.minorVersion = 3;
        settings.attributeFlags = sf::ContextSettings::Core;

        m_renderWindow->create(sf::VideoMode(WIDTH, HEIGHT), title, sf::Style::Default, settings);
        m_renderWindow->setActive(true);

        if (m_isOpengl == true)
        {
            glewExperimental = GL_TRUE;

            if (GLEW_OK != glewInit())
            {
                std::cout << " Failed To initialize GLEW" << std::endl;
                return;
            }
        }

        init();

        auto& physics = aiko::physics::Physics::get();
        physics.init(*m_renderWindow);

        // f.get();

        TimeStamp timeStamp;

        while (m_renderWindow->isOpen()) {
            // Check for all the events that occured since the last frame.
            while (m_renderWindow->pollEvent(event)) {
                //Handle events here
                if (event.type == sf::Event::EventType::Closed)
                {
                    m_renderWindow->close();
                }
                else if (event.type == sf::Event::Resized)
                {
                    // adjust the viewport when the window is resized
                    glViewport(0, 0, event.size.width, event.size.height);
                }

                physics.input(event);
            }

            // A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
            timeStamp.delta = clock.getElapsedTime().asSeconds();
            //std::cout << "Elapsed time since previous frame(microseconds): " << delta << std::endl;

            // Start the countdown over.  Think of laps on a stop watch.
            clock.restart();
            // update start
            // printLater.join();
            // EntityManager::get()->update(timeStamp);

            physics.update(timeStamp);
            m_kimo->update(timeStamp);
            // update end
            // m_renderWindow->clear(sf::Color::Black);
            // clear the buffers
            glClearColor(0.2f,  0.3f, 0.2f,1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            // renderstar
            m_kimo->render(*m_renderWindow);
            // debug
            // physics.render(renderWindow);
            // render end
            m_renderWindow->display();
        }

    }

}