#include "EntityManager.h"

#include <functional>

namespace aiko
{

    EntityManager::EntityManager()
    {
    }


    EntityManager::~EntityManager()
    {
    }

    void EntityManager::update(TimeStamp timestamp)
    {
        /*
        for (auto& e : m_entities)
        {
            e.update(timestamp);
        }
        */

        static auto history = std::vector<float>();
        static auto historyB = std::vector<float>();

        sf::Clock clock;
        std::vector<unsigned int> numbers;
        for (unsigned int i = 0; i < 1000; i++)
        {
            numbers.push_back(rand() % 1000);
        }
        const auto time = clock.getElapsedTime().asSeconds();;

        std::vector<unsigned int> v(10000, 1);

        auto r = parallel_sum(v.begin(), v.end());
        
        // record history
        history.push_back(time);
        historyB.push_back(time);

        std::cout << "The sum is " << r << " and toke: { " << time << " }." << std::endl;

        float i;
        i = 0.0f;
        {
            for (float h : history) i += h;
            auto tmp = (i / static_cast<float>(history.size()));
            static constexpr const auto z = 1000000.0f;
            tmp = (int)(tmp * z) / z;
            std::cout << "The mean is: { " << tmp << " }." << std::endl;
        }
        i = 0.0f;
        {
            for (float h : historyB) i += h;
            auto tmp = (i / static_cast<float>(historyB.size()));
            static constexpr const auto z = 1000000.0f;
            tmp = (int)(tmp * z) / z;
            std::cout << "The mean is: { " << tmp << " }." << std::endl;
        }

        std::cout << "Bye" << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(5));

    }

}