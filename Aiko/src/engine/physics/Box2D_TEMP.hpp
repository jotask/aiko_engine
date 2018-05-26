#pragma once

/*

namespace b2World
{

    class b2Vec2;
    class b2World;
    class b2BodyDef;
    class b2FixtureDef;
    class b2PolygonShape;

    using int32     = int;
    using float32   = float;

    class b2Vec2
    {
    public:
        b2Vec2(float _x = 0, float _y = 0) ;
        void set(float _x = 0.0f, float _y = -10.0f);
        float x;
        float y;
    };

    class b2World
    {
    public:
        b2World(b2Vec2 _gravity);
        b2Body* createBody(b2BodyDef* groundBodyDef);
        void step(float delta = 0.0f, int a = 6, int b = 2);
        b2Vec2 gravity;
    };

    static const b2Body b2_dynamicBody;

    class b2BodyDef
    {
    public:
        b2BodyDef();
        b2Vec2 position;
        b2Body type;
    };

    class b2Body
    {
    public:
        b2Body();
        void createFixture(b2FixtureDef* groundBox);
        void createFixture(b2PolygonShape* groundBox, float a = 0.0f);
    };

    class b2PolygonShape
    {
    public:
        b2PolygonShape();
        void setAsBox(float a = 1.0f, float b = 1.0f);
    };

    class b2FixtureDef
    {
    public:
        b2FixtureDef();
        float density;
        float friction;
        b2PolygonShape* shape;
    };
    

}

*/