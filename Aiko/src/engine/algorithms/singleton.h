#pragma once

#include <memory>

namespace aiko
{

    template<class T>
    class Singleton
    {
    public:
        static T* get()
        {
            static std::unique_ptr<T> instance (std::make_unique<T>());
            return instance.get();
        }
    protected:
        Singleton()
        {

        }

        virtual inline ~Singleton()
        {

        }

    };

}