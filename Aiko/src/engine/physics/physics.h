#pragma once

#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

#include <Box2D\Box2D.h>
#include "SFMLDebugDraw.h"

#include "../time.h"

namespace aiko
{
    namespace physics
    {

        class PhysicsComponent;

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

            void init(sf::RenderWindow& window);

            void input(sf::Event evnt);

            b2Vec2&     getGravity();
            b2World&    getWorld();

        private:

            Physics();
            ~Physics();
            Physics(Physics const&) = delete;
            void operator=(Physics const&) = delete;

            void run();

            void registerComponents();

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

            std::vector<std::unique_ptr<PhysicsComponent>> m_components;

            friend class PhysicComponent;
            friend class PhysicsUtils;

        };

    }
}