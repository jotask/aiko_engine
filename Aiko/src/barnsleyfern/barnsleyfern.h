#pragma once

#include <SFML/Graphics.hpp>

#include "../engine/kimo.h"

#include "../engine/camera.h"

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

            // w        a       b        c      d        e      f      p
            // ƒ1       0       0        0   0.25        0   −0.4   0.02
            // ƒ2    0.95   0.005   −0.005   0.93   −0.002    0.5   0.84
            // ƒ3   0.035    −0.2     0.16   0.04    −0.09   0.02   0.07
            // ƒ4   −0.04     0.2     0.16   0.04    0.083   0.12   0.07

            void setNormal()
            {
                // static const auto aL = [&]() {  };
            }

            float a;
            float b;
            float c;
            float d;
            float e;
            float f;
            float p;
        };

        Coefficients coeficient;

        void generate();

        sf::VertexArray vertices;

        sf::Vector2f last;

        aiko::Camera camera;

        float zoom;

    };

}