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

    static Physics& get()
    {
        static Physics instance; // Guaranteed to be destroyed. Instantiated on first use.
        return instance;
    }

    void update(const TimeStamp& delta);
    void render(sf::RenderWindow&);


    static b2Body* createCircle(sf::Vector2f pos, float radius);

    void init(sf::RenderWindow& window);

    void input(sf::Event evnt);

private:

    template<typename T >
    static b2Vec2 sfVecToB2Vec(sf::Vector2<T> vector) { return b2Vec2(vector.x / sfdd::SCALE, vector.y / sfdd::SCALE); }
    
    template<typename T >
    static sf::Vector2<T> B2VecTosfVec(b2Vec2 vector) { return sf::Vector2<T>(vector.x * sfdd::SCALE, vector.y * sfdd::SCALE); }

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

    std::thread m_thread;
    std::atomic_bool m_run{ true };

    // BOX2D
    b2Vec2  m_gravity;
    b2World m_world;


};