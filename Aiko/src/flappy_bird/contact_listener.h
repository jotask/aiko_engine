#pragma once

#include <Box2D/Box2D.h>

#include "bird.h"
#include "pipe.h"

template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

template<class A, class B>
inline bool is(const auto* a, const auto* b)
{
     return (instanceof<flappybird::A>(dataA) == true && instanceof<flappybird::B>(dataB) == true) || (instanceof<flappybird::B>(dataA) == true && instanceof<flappybird::A>(dataB) == true);
}

class MyContactListener : public b2ContactListener
{
    void BeginContact(b2Contact* contact)
    {

        const auto* bodyA = contact->GetFixtureA()->GetBody();
        const auto* bodyB = contact->GetFixtureB()->GetBody();

        const auto* dataA = static_cast<aiko::BodyEntity*>(bodyA->GetUserData());
        const auto* dataB = static_cast<aiko::BodyEntity*>(bodyB->GetUserData());

        if (is<flappybird::Bird, flappybird::Pipe>(dataA, dataB) == true)
        {
            // we know a bird has collide with a pipe
            // let's identify each one

            flappybird::Bird* bird = nullptr;
            flappybird::Pipe* pipe = nullptr;
            
            if (const auto* b = dynamic_cast<const flappybird::Bird*>(dataA))
            {
                bird = const_cast<flappybird::Bird*>(b);
                pipe = const_cast<flappybird::Pipe*>(dynamic_cast<const flappybird::Pipe*>(dataB));
            }
            else
            {
                bird = const_cast<flappybird::Bird*>(dynamic_cast<const flappybird::Bird*>(dataB));
                pipe = const_cast<flappybird::Pipe*>(dynamic_cast<const flappybird::Pipe*>(dataA));
            }

            bird->restart();

        }

    }

};