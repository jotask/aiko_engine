#pragma once

// stl
#include <map>
#include <functional>

// aiko
#include "../algorithms/singleton.h"
#include "message.h"

namespace aiko
{
    /*
    class MessageSystem : public Singleton<MessageSystem>
    {
    public:

        template<class EventWanted>
        static void bind(const std::function<void(const Event&)>& fn)
        {
            const auto eventMap = MessageSystem::get()->m_eventMap;
            eventMap.emplace(&typeid(EventWanted), fn);
        }

        template<class Message>
        static void unbind(const std::function<void(const Event&)>& fn)
        {
            const auto eventMap = MessageSystem::get()->m_eventMap;
            
            std::pair<iterator, iterator> iterpair = mymap.equal_range('b');
            iterator it = iterpair.first;
            for (; it != iterpair.second; ++it) {
                if (it->second == 15) {
                    mymap.erase(it);
                    break;
                }
            }

        }

        static void sendMessage(const Message& event)
        {
            const auto eventMap = MessageSystem::get()->m_eventMap;
            auto range = eventMap.equal_range(&typeid(event));
            for (auto it = range.first; it != range.second; ++it)
                it->second(event);

        }

    private:

        MessageSystem();
        ~MessageSystem();

        using EventMap = std::multimap<const std::type_info*, const std::function<void(const Message&)>>;
        EventMap        m_eventMap;

    };

    */


}