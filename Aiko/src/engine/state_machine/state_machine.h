#pragma once

#include "../kimo.h"
#include "../../constants.h"

namespace aiko
{

    class StateMachine : public Kimo
    {
    public:
        StateMachine();
        ~StateMachine();

        virtual void init() final override;

        virtual void preUpdate(const aiko::TimeStamp& delta) final override;
        virtual void update(const aiko::TimeStamp& delta) final override;
        virtual void postUpdate(const aiko::TimeStamp& delta) final override;

        virtual void preRender(sf::RenderWindow&) final override;
        virtual void render(sf::RenderWindow&) final override;
        virtual void postRender(sf::RenderWindow&) final override;

        virtual void preDebug(sf::RenderWindow&) final override;
        virtual void debug(sf::RenderWindow&) final override;
        virtual void postDebug(sf::RenderWindow&) final override;

        void changeState(const STATE state);

    private:

        STATE                   m_currentState;

        std::unique_ptr<Kimo>   m_kimo;

    };

}