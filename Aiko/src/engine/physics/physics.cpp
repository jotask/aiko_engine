#include "physics.h"

#include <SFML/System.hpp>

#include <stdio.h>

//Class copied from http://code.google.com/p/box2d/source/browse/trunk/Box2D/Testbed/Framework/Test.cpp
//Copyright (c) 2011 Erin Catto http://box2d.org
class QueryCallback : public b2QueryCallback
{
public:
    QueryCallback(const b2Vec2& point)
    {
        m_point = point;
        m_fixture = nullptr;
    }

    bool ReportFixture(b2Fixture* fixture)
    {
        b2Body* body = fixture->GetBody();
        if (body->GetType() == b2_dynamicBody)
        {
            bool inside = fixture->TestPoint(m_point);
            if (inside)
            {
                m_fixture = fixture;

                // We are done, terminate the query.
                return false;
            }
        }

        // Continue the query.
        return true;
    }

    b2Vec2 m_point;
    b2Fixture* m_fixture;
};

Physics::Physics()
    : m_run(true)
    , m_thread(&Physics::run, this)
    , m_window(nullptr)
    , m_debugDraw(nullptr)
    // Box2d
    , m_gravity (0.0f, 9.8f)
    , m_world(m_gravity)
    , m_mouseJoint(nullptr)
{

}

void Physics::init(sf::RenderWindow& window)
{
    assert(m_debugDraw == nullptr && m_window == nullptr);
    m_window = &window;
    m_debugDraw = new SFMLDebugDraw(window);

    m_debugDraw->SetFlags(b2Draw::e_shapeBit); //Only draw shapes

    m_world.SetDebugDraw(m_debugDraw);

    boundWord(window);

}

void Physics::input(sf::Event evnt)
{
    if (evnt.type == sf::Event::Closed || (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Escape))
        m_window->close();
    else if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::F1)
    {
        if (m_debugDraw->GetFlags() & b2Draw::e_shapeBit) m_debugDraw->ClearFlags(b2Draw::e_shapeBit);
        else m_debugDraw->AppendFlags(b2Draw::e_shapeBit);
    }
    else if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::F2)
    {
        if (m_debugDraw->GetFlags() & b2Draw::e_aabbBit) m_debugDraw->ClearFlags(b2Draw::e_aabbBit);
        else m_debugDraw->AppendFlags(b2Draw::e_aabbBit);
    }
    else if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::F3)
    {
        if (m_debugDraw->GetFlags() & b2Draw::e_centerOfMassBit) m_debugDraw->ClearFlags(b2Draw::e_centerOfMassBit);
        else m_debugDraw->AppendFlags(b2Draw::e_centerOfMassBit);
    }
    else if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Num1)
    {
        // m_bodies.push_back(createSquare(world, window));
    }
    else if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::Num2)
    {
        // m_bodies.push_back(createCircle(world, window));
    }
    else if (evnt.type == sf::Event::KeyPressed && evnt.key.code == sf::Keyboard::BackSpace)
    {
        if (!m_bodies.empty())
        {
            m_world.DestroyBody(m_bodies.back());
            m_bodies.pop_back();
        }
    }
    // Following three events are copied almost completely from http://code.google.com/p/box2d/source/browse/trunk/Box2D/Testbed/Framework/Test.cpp
    // Copyright (c) 2011 Erin Catto http://box2d.org
    else if (evnt.type == sf::Event::MouseButtonPressed && evnt.mouseButton.button == sf::Mouse::Left && m_mouseJoint == nullptr)
    {
        b2Vec2 mousePos = Physics::sfVecToB2Vec(sf::Mouse::getPosition(*m_window));

        // Make a small box.
        b2AABB aabb;
        b2Vec2 d;
        d.Set(0.001f, 0.001f);
        aabb.lowerBound = mousePos + d;
        aabb.upperBound = mousePos - d;

        // Query the world for overlapping shapes.
        QueryCallback callback(mousePos);
        m_world.QueryAABB(&callback, aabb);

        if (callback.m_fixture)
        {
            b2Body* body = callback.m_fixture->GetBody();
            b2MouseJointDef md;
            md.bodyA = m_ground; //If bounding box body is used instead, the dynamic bodes can be dragged over the bounding box and we don't want that
            md.bodyB = body;
            md.target = mousePos;
            md.maxForce = 1000.0f * body->GetMass();
            m_mouseJoint = static_cast<b2MouseJoint*>(m_world.CreateJoint(&md));
            body->SetAwake(true);
        }
    }
    else if (evnt.type == sf::Event::MouseMoved && m_mouseJoint != nullptr)
    {
        b2Vec2 mousePos = Physics::sfVecToB2Vec(sf::Mouse::getPosition(*m_window));
        m_mouseJoint->SetTarget(mousePos);
    }
    else if (evnt.type == sf::Event::MouseButtonReleased && evnt.mouseButton.button == sf::Mouse::Left && m_mouseJoint != nullptr)
    {
        m_world.DestroyJoint(m_mouseJoint);
        m_mouseJoint = nullptr;
    }
}

void Physics::boundWord(sf::RenderWindow& window)
{

    auto size = sfVecToB2Vec(window.getSize());
    auto post = sfVecToB2Vec(window.getPosition());

    b2BodyDef bDef;
    bDef.type = b2_staticBody;
    bDef.position = b2Vec2(0, 0);
    b2Body *body = m_world.CreateBody(&bDef);
    m_ground = body;

    b2PolygonShape shape;
    const float32 density = 10;

    // setAsBox(float32 width, float32 height, const b2Vec2 &center, float32 rotation)

    // top
    shape.SetAsBox(100.0f, 0.1f, b2Vec2(post.x + (size.x * 0.5f), 0.0f), 0.0f);
    body->CreateFixture(&shape, density);

    // bottom
    shape.SetAsBox(100.0f, 0.1f, b2Vec2(post.x + (size.x * 0.5f), size.y), 0.0f);
    body->CreateFixture(&shape, density);

    // left
    shape.SetAsBox(0.1f, 100.0f, b2Vec2(size.x, 0.0f), 0.0f);
    body->CreateFixture(&shape, density);

    // right
    shape.SetAsBox(0.1f, 100.0f, b2Vec2(0.0f, 0.0f), 0.0f);
    body->CreateFixture(&shape, density);

}

b2Body* Physics::createCircle(sf::Vector2f pos, float radius)
{
    auto& physics = Physics::get();
    
    // Define the dynamic body. We set its position and call the body factory.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    //bodyDef.type = b2_staticBody;
    //bodyDef.position.Set(0.0f, 4.0f);
    const auto tmp = sfVecToB2Vec(pos);
    bodyDef.position.Set(tmp.x, tmp.y);
    b2Body* body = physics.m_world.CreateBody(&bodyDef);

    // Define another box shape for our dynamic body.
    b2CircleShape dynamicBox;
    dynamicBox.m_radius = radius;
    //dynamicBox.SetAsBox(1.0f, 1.0f);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;

    // Override the default friction.
    fixtureDef.friction = 0.3f;

    fixtureDef.restitution = 0.6f; // Make it bounce a little bit

                                   // Add the shape to the body.
    body->CreateFixture(&fixtureDef);

    physics.m_bodies.push_back(body);

    return body;
}

Physics::~Physics()
{

    for (auto* b: m_bodies)
    {
        m_world.DestroyBody(b);
    }

    delete m_debugDraw;
    m_run = false;
    m_thread.join();
    std::cout << "Physics Thread stopped" << std::endl;
}

void Physics::update(const TimeStamp& delta)
{
    m_world.Step(delta.delta, 6, 3);
    //std::cout << "Physics::Update();" << std::endl;
}

void Physics::render(sf::RenderWindow&)
{
    m_world.DrawDebugData();
    //std::cout << "Physics::render();" << std::endl;
}

void Physics::run()
{
    sf::Clock clock;

    TimeStamp timeStamp;

    // Define the gravity vector.
    b2Vec2 gravity(0.0f, -10.0f);

    // Construct a world object, which will hold and simulate the rigid bodies.
    b2World world(gravity);

    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(50.0f, 10.0f);

    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Define the dynamic body. We set its position and call the body factory.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    b2Body* body = world.CreateBody(&bodyDef);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;

    // Override the default friction.
    fixtureDef.friction = 0.3f;

    // Add the shape to the body.
    body->CreateFixture(&fixtureDef);

    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    float delta = 0.0f;

    while (m_run)
    {
        timeStamp.delta = clock.getElapsedTime().asSeconds();
        delta = clock.restart().asSeconds();
        // update start

        world.Step(delta, 6, 2);

    }

}