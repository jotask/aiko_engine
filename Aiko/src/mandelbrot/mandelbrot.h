#pragma once

#include <SFML/Graphics.hpp>

#include "../engine/kimo.h"

namespace mandelbrot
{

    class Mandelbrot : public aiko::Kimo
    {
    public:
        Mandelbrot();
        ~Mandelbrot();

        virtual void update(const aiko::TimeStamp& delta) final override;
        virtual void render(sf::RenderWindow&) final override;

    private:

        struct ComplexNumber
        {
            long double real;
            long double imaginary;
        };

        void init();
        void reset();
        void generateMandelbrotSet();

        sf::VertexArray points;

        bool isDirty;

        float zoom;
        int precision;
        int xShift;
        int yShift;

    };

}