#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <vector>
#include <list>
#include <iostream>

namespace aiko
{

    class ThreadSystem
    {
    public:
        ThreadSystem(int initialThreadCount = 1 );
        ~ThreadSystem();
        void addWorkItem(std::function<void()> action);
    
    private:

        std::function<void()> getNextWorkItem();
        void workerAction();
        void tellAllThreadsToStop();

        bool                                stopping;
        bool                                finished;
        std::mutex                          lock;
        std::condition_variable             cond;
        std::condition_variable             threadBarrier;
        std::list<std::function<void()>>    work;
        std::vector<std::thread>            workers;

    };

}