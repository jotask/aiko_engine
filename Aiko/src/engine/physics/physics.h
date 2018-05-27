#pragma once

#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

#include <Box2D\Box2D.h>
#include "SFMLDebugDraw.h"

#include "../time.h"

class Physics
{
public:

    static float sfToB2(float32 n) { return n * sfdd::SCALE; }
    static float B2Tosf(float32 n) { return n / sfdd::SCALE; }

    template<typename T >
    static b2Vec2 sfVecToB2Vec(sf::Vector2<T> vector) { return b2Vec2(vector.x / sfdd::SCALE, vector.y / sfdd::SCALE); }

    template<typename T >
    static sf::Vector2<T> B2VecTosfVec(b2Vec2 vector) { return sf::Vector2<T>(vector.x * sfdd::SCALE, vector.y * sfdd::SCALE); }


    static Physics& get()
    {
        static Physics instance; // Guaranteed to be destroyed. Instantiated on first use.
        return instance;
    }

    void update(const TimeStamp& delta);
    void render(sf::RenderWindow&);

    static b2Body* createCircle(sf::Vector2f pos, float radius = 1.0f);
    static b2Body* createRectangle(sf::Vector2f pos, sf::Vector2f size = sf::Vector2f(1.0f, 1.0f));
    static b2Body* createPolygon(sf::Vector2f poss, std::vector<sf::Vector2f> vertices = { {0.0f, 1.0f}, {-0.5f, 0.0f},{0.0f, 0.0f} });

    void init(sf::RenderWindow& window);

    void input(sf::Event evnt);

private:

    Physics();
    ~Physics();
    Physics(Physics const&) = delete;
    void operator=(Physics const&) = delete;

    void run();

    void boundWord(sf::RenderWindow&);

    b2Body* m_ground;

    std::vector<b2Body*> m_bodies;

    sf::RenderWindow*   m_window;
    SFMLDebugDraw*      m_debugDraw;

    b2MouseJoint* m_mouseJoint;

    sf::Vector3f m_delta;

    std::thread m_thread;
    std::atomic_bool m_run{ true };

    // BOX2D
    b2Vec2  m_gravity;
    b2World m_world;


};