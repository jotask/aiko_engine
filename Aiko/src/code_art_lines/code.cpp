#include "code.h"

#include <cassert>

namespace code
{

    const sf::Color Code::bg = sf::Color::White;

    Code::Code()
        : c(sf::Color::Red)
    {
        img.create(WIDTH, HEIGHT, bg);
        randomEverything();
    }

    void Code::update(const aiko::TimeStamp& delta)
    {

        assert((pos.x < 0 || pos.x >= WIDTH) == false);
        assert((pos.y < 0 || pos.y >= HEIGHT) == false);

        static constexpr int MAX_ATTEMPS = 10;
        int counter = 0;
        while (img.getPixel(pos.x, pos.y) != bg)
        {
            if (counter >= MAX_ATTEMPS)
            {
                return;
            }

            randomEverything();

            counter++;
        }

        img.setPixel(pos.x, pos.y, c);

        if (vel.x != 0)
        {
            if (vel.x > 0)
            {
                pos.x++;
            }
            else
            {
                pos.x--;
            }
        }
        if (vel.y != 0)
        {
            if (vel.y > 0)
            {
                pos.y++;
            }
            else
            {
                pos.y--;
            }
        }

        if (pos.x < 0 || pos.x >= WIDTH || pos.y < 0 || pos.y >= HEIGHT)
        {
            randomEverything();
        }

    }

    void Code::render(sf::RenderWindow& window)
    {
        sf::Texture text;
        text.create(img.getSize().x, img.getSize().y);
        text.setSmooth(true);
        text.update(img);
        sf::Sprite sprite;
        sprite.setTexture(text);
        window.draw(sprite);
    }

    void Code::randomPos(const bool x, const bool y)
    {
        pos.x = random(0, WIDTH - 1);
        pos.y = random(0, HEIGHT - 1);
    }

    void Code::randomVel(const bool x, const bool y)
    {
        vel.x = random(-1, 1);
        vel.y = random(-1, 1);
    }

    void Code::randomCol()
    {
        c.r = random(0, 255);
        c.g = random(0, 255);
        c.b = random(0, 255);
    }


    void Code::randomEverything()
    {

        randomCol();

        const auto aL = random(0, 1) == 0;
        const auto aR = random(0, 1) == 0;

        const auto bL = random(0, 1) == 0;
        const auto bR = random(0, 1) == 0;

        randomPos(aL, aR);
        randomVel(bL, bR);

    }

}