#pragma once

// STL
#include <memory>
#include <stdlib.h>

// aiko
#include "../constants.h"
#include "state_machine/state_machine.h"

namespace sf
{
    class RenderWindow;
}

namespace aiko
{

    class Kimo;

    class Aiko
    {
    public:
        Aiko();
        ~Aiko();

        void                    run();

        static std::shared_ptr<Aiko> get() {
            if (m_singleton != nullptr)
            {
                m_singleton.reset(new Aiko);
            }
            return m_singleton;
        }

        sf::RenderWindow* const getWindow() { return m_renderWindow; }

        void setIsOpengl(bool isOpengl = false) { m_isOpengl = isOpengl; };

    private:

        void                         init();

        StateMachine                m_state;

        static std::shared_ptr<Aiko> m_singleton;

        sf::RenderWindow* m_renderWindow;

        bool m_isOpengl;


    };

}