#pragma once

#include <Box2D/Box2D.h>
#include "physics.h"

namespace aiko
{
    namespace physics
    {

        class PhysicsUtils
        {
        public:

            static float sfToB2(float32 n) { return n * sfdd::SCALE; }
            static float B2Tosf(float32 n) { return n / sfdd::SCALE; }

            template<typename T >
            static b2Vec2 sfVecToB2Vec(sf::Vector2<T> vector) { return b2Vec2(vector.x / sfdd::SCALE, vector.y / sfdd::SCALE); }

            template<typename T >
            static sf::Vector2<T> B2VecTosfVec(b2Vec2 vector) { return sf::Vector2<T>(vector.x * sfdd::SCALE, vector.y * sfdd::SCALE); }

            static b2Body* createCircle(sf::Vector2f pos, float radius = 1.0f);
            static b2Body* createRectangle(sf::Vector2f pos, sf::Vector2f size = sf::Vector2f(1.0f, 1.0f));
            static b2Body* createPolygon(sf::Vector2f poss, std::vector<sf::Vector2f> vertices = { { 0.0f, 1.0f },{ -0.5f, 0.0f },{ 0.0f, 0.0f } });

        private:
            PhysicsUtils() = delete;

        };
    }
}