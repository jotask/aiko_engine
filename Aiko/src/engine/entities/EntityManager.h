#pragma once

#include <iostream>
#include <cassert>
#include <thread>
#include <future>
#include <vector>
#include <chrono>
#include <vector>
#include <SFML/System.hpp>

#include "../algorithms/singleton.h"
#include "entity.h"
#include "../time.h"

namespace aiko
{

    class EntityManager : public Singleton<EntityManager>
    {
    public:
        void update(TimeStamp);

        static int parallel_sum(std::vector<unsigned int>::iterator beg, std::vector<unsigned int>::iterator end)
        {
            auto len = end - beg;
            if (len < 1000)
            {
                unsigned int result = 0u;
                for (auto i = 0; i < len; i++)
                {
                    result += *beg;
                    beg++;
                }
                return result;
            }

            auto mid = beg + len / 2;
            auto handle = std::async(std::launch::async, parallel_sum, mid, end);
            int sum = parallel_sum(beg, mid);
            return sum + handle.get();
        }

        EntityManager();
        ~EntityManager();


        std::vector<Entity> m_entities;

    };

}