#pragma once

#include "time.h"
#include <SFML/Graphics.hpp>

#include "entities/body_entity.h"

namespace aiko
{

    class Camera : public Entity
    {
    public:
        Camera();
        ~Camera();

        void update(const TimeStamp& delta);
        void render(sf::RenderWindow&);

        bool isOnCamera(const BodyEntity& entity) const;

    private:

        static sf::FloatRect getViewBounds(const sf::View &view);

        sf::Vector2f    m_pos;
        float           m_rotation;
        float           m_zoom;

        sf::Vector2f    m_bound;

        sf::View        m_view;

    };

}