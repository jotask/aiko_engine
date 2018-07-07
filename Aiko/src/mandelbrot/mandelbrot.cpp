#include "mandelbrot.h"

namespace mandelbrot
{

    Mandelbrot::Mandelbrot()
        : points(sf::Points, WIDTH * HEIGHT)
        , isDirty(true)
        , zoom(300.0f)
        , precision(100)
        , xShift(WIDTH  / 2)
        , yShift(HEIGHT / 2)
    {
        reset();
    }

    Mandelbrot::~Mandelbrot()
    {

    }

    void Mandelbrot::update(const aiko::TimeStamp& delta)
    {

        if (isDirty == true)
        {
            isDirty = false;
            reset();
            generateMandelbrotSet();
        }
    }

    void Mandelbrot::reset()
    {
#pragma omp parallel for
        for (unsigned int i = 0 ; i < WIDTH * HEIGHT; i++)
        {
            points[i].color = sf::Color::Black;
        }
    }

    void Mandelbrot::init()
    {
#pragma omp parallel for
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                points[i * WIDTH + j].position = sf::Vector2f(j * 1.0f, i * 1.0f);
                points[i * WIDTH + j].color = sf::Color::Red;
            }
        }

    }

    void Mandelbrot::generateMandelbrotSet()
    {
        std::cout << "Generating" << std::endl;
#pragma omp parallel for
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                //scale the pixel location to the complex plane for calculations
                long double x = ((long double)j - xShift) / zoom;
                long double y = ((long double)i - yShift) / zoom;
                ComplexNumber c;
                c.real = x;
                c.imaginary = y;
                ComplexNumber z = c;
                int iterations = 0; //keep track of the number of iterations
                for (int k = 0; k < precision; k++)
                {
                    ComplexNumber z2;
                    z2.real = z.real * z.real - z.imaginary * z.imaginary;
                    z2.imaginary = 2 * z.real * z.imaginary;
                    z2.real += c.real;
                    z2.imaginary += c.imaginary;
                    z = z2;
                    iterations++;
                    if (z.real * z.real + z.imaginary * z.imaginary > 4)
                        break;
                }
                //color pixel based on the number of iterations
                if (iterations < precision / 4.0f)
                {
                    points[i*WIDTH + j].position = sf::Vector2f(j * 1.f, i*1.0f);
                    sf::Color color(static_cast<sf::Uint8>(iterations * 255.0f / (precision / 4.0f)), 0, 0);
                    points[i*WIDTH + j].color = color;
                }
                else if (iterations < precision / 2.0f)
                {
                    points[i*WIDTH + j].position = sf::Vector2f(j * 1.0f, i * 1.0f);
                    sf::Color color(0, static_cast<sf::Uint8>(iterations * 255.0f / (precision / 2.0f)), 0);
                    points[i*WIDTH + j].color = color;
                }
                else if (iterations < precision)
                {
                    points[i*WIDTH + j].position = sf::Vector2f(j * 1.0f, i * 1.0f);
                    sf::Color color(0, 0, static_cast<sf::Uint8>(iterations * 255.0f / precision));
                    points[i*WIDTH + j].color = color;
                }
            }
        }
        std::cout << "end" << std::endl;
    }

    void Mandelbrot::render(sf::RenderWindow& window)
    {

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
        {
            sf::Vector2i p = sf::Mouse::getPosition(window);
            xShift -= p.x - xShift;
            yShift -= p.y - yShift;
            zoom *= 2;
            precision += 200;
            isDirty = true;
        }

        window.draw(points);
    }

}