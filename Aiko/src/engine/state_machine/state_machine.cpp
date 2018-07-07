#include "state_machine.h"

#include "../../constants.h"
#include "../../code_art_lines/code.h"
#include "../../labyrinth/labyrinth.h"
#include "../../flappy_bird/flappy_bird.h"
#include "../../opengl/opengl.h"
#include "../../mandelbrot/mandelbrot.h"
#include "../../barnsleyfern/barnsleyfern.h"

namespace aiko
{

    StateMachine::StateMachine()
        : m_currentState(START_STATE)
        , m_kimo(nullptr)
    {

    }

    StateMachine::~StateMachine()
    {

    }

    void StateMachine::init()
    {
        changeState(m_currentState);
    }

    void StateMachine::changeState(const STATE state)
    {
        switch (state)
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

    void StateMachine::preUpdate(const aiko::TimeStamp& delta) 
    {
        m_kimo->preUpdate(delta);
    }

    void StateMachine::update(const aiko::TimeStamp& delta)
    {
        m_kimo->update(delta);
    }

    void StateMachine::postUpdate(const aiko::TimeStamp& delta)
    {
        m_kimo->postUpdate(delta);
    }

    void StateMachine::preRender(sf::RenderWindow& window)
    {
        m_kimo->preRender(window);
    }

    void StateMachine::render(sf::RenderWindow& window)
    {
        m_kimo->render(window);
    }

    void StateMachine::postRender(sf::RenderWindow& window)
    {
        m_kimo->postRender(window);
    }

    void StateMachine::preDebug(sf::RenderWindow& window)
    {
        m_kimo->preDebug(window);
    }

    void StateMachine::debug(sf::RenderWindow& window)
    {
        m_kimo->debug(window);
    }

    void StateMachine::postDebug(sf::RenderWindow& window)
    {
        m_kimo->postDebug(window);
    }
    
}