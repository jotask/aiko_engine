#pragma once

#include <stdlib.h>

#ifdef _WIN32
#define WINPAUSE system("pause")
#endif

#include "../constants.h"

// STL
#include <memory>

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

        static std::shared_ptr<Aiko> m_singleton;

        std::unique_ptr<Kimo>   m_kimo;
        STATE                   m_state;

        sf::RenderWindow* m_renderWindow;

        bool m_isOpengl;


    };

}