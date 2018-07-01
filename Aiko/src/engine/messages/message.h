#pragma once

#include <string>

namespace aiko
{

    class Message
    {
    public:
        Message();
        virtual ~Message();

        virtual std::string getId() = 0;

    };


}