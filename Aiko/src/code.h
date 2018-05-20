#pragma once

#include "constants.h"

#include <SFML/Graphics.hpp>

#include <vector>

#include "engine/kimo.h"

// forward declarations
namespace sf
{
    class RenderWindow;
}

class Code : public Kimo
{
public:

    Code();
    ~Code();

    virtual void update(const TimeStamp& delta) final override;
    virtual void render(sf::RenderWindow&) final override;

private:

    void randomPos(const bool x = false, const bool y = false);
    void randomVel(const bool x = false, const bool y = false);
    void randomCol();

    void randomEverything();

    static const sf::Color bg;

    sf::Image img;

    sf::Vector2i vel;
    sf::Vector2i pos;

    sf::Color c;

};