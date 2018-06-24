#pragma once

#include <SFML/Graphics.hpp>

#include "../engine/kimo.h"

namespace barnsleyfern
{

    class BarnsleyFern : public aiko::Kimo
    {
    public:
        BarnsleyFern();
        ~BarnsleyFern();

        virtual void update(const aiko::TimeStamp& delta) final override;
        virtual void render(sf::RenderWindow&) final override;

    private:

        struct Coefficients
        {

            Coefficients()
                : a (0.0f)
                , b (0.0f)
                , c (0.0f)
                , d (0.0f)
                , e (0.0f)
                , f (0.0f)
                , p (0.0f)
            { }

            void setNormal()
            {

            }

            float a;
            float b;
            float c;
            float d;
            float e;
            float f;
            float p;
        };

        void generate();

        sf::VertexArray vertices;

        sf::Vector2f last;

    };

}