#include "physicscomponent.h"

PhysicsComponent::PhysicsComponent(const bool _drawdebug)
    : m_physics(Physics::get())
    , m_drawDebug(_drawdebug)
{

}

PhysicsComponent::~PhysicsComponent()
{

}