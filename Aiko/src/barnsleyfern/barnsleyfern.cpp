#include "barnsleyfern.h"

#include "../engine/utils.h"

namespace barnsleyfern
{

    BarnsleyFern::BarnsleyFern()
        : coeficient(Coefficients())
        , vertices(sf::Points, WIDTH * HEIGHT)
        , last (0.0f, 0.0f)
        , camera()
        , zoom(1.0f)
    {
        for (unsigned int i = 0; i < WIDTH  ; i++)
        for (unsigned int j = 0; j < HEIGHT ; j++)
        {
            const auto index = i * HEIGHT + j;


            sf::Vertex v;
            v.position = sf::Vector2f(i*1.0f, j*1.0f);
            v.color = sf::Color::Transparent;

            vertices[index] = v;
        }
    }

    BarnsleyFern::~BarnsleyFern()
    {

    }

    void BarnsleyFern::generate()
    {
        static auto count = 0u;

        float nextX;
        float nextY;

        float r = Utils::random1D(0.0f, 1.0f);

        if (r < 0.01f)
        {
            // 1
            nextX = 0.0f;
            nextY = 0.16f * last.y;
        }
        else if (r < 0.86f)
        {
            // 2
            nextX =  0.85f * last.x + 0.04f * last.y;
            nextY = -0.04f * last.x + 0.85f * last.y + 1.6f;
        }
        else if (r < 0.93f) {
            // 3
            nextX = 0.20f * last.x + -0.26f * last.y;
            nextY = 0.23f * last.x +  0.22f * last.y + 1.6f;
        }
        else {
            // 4
            nextX = -0.15f * last.x + 0.28f * last.y;
            nextY =  0.26f * last.x + 0.24f * last.y + 0.44f;
        }

        last.x = nextX;
        last.y = nextY;

        // generate the color
        float px = Utils::map<float>(last.x, -2.1820f, 2.6558f, 0.0f, WIDTH);
        float py = Utils::map<float>(last.y, 0, 9.9983f, HEIGHT, 0.0f);

        const auto index = static_cast<unsigned int>( py * WIDTH + px );
        vertices[index].position = sf::Vector2f(px, py);
        //vertices[index].color = sf::Color::Green;

    }

    void BarnsleyFern::update(const aiko::TimeStamp& delta)
    {
        for(unsigned int i = 0 ; i < 500; i++)
            generate();

        zoom -= 0.000001f;// *delta.delta;

        camera.setZoom(zoom);
    }

    void BarnsleyFern::render(sf::RenderWindow& window)
    {
        camera.render(window);
        window.draw(vertices);
    }

}