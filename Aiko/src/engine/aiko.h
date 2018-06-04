#pragma once

#include "../constants.h"

// STL
#include <memory>

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

    private:

        void                         init();

        static std::shared_ptr<Aiko> m_singleton;

        std::unique_ptr<Kimo>   m_kimo;
        STATE                   m_state;

    };

}