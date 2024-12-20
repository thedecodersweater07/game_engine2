#include "event_manager.h"
#include <iostream>

namespace Events {

    EventManager& EventManager::getInstance() {
        static EventManager instance;
        return instance;
    }

    void EventManager::registerEvent(const std::string& eventName, EventCallback callback) {
        eventMap[eventName].push_back(callback);
    }

    void EventManager::triggerEvent(const std::string& eventName) {
        auto it = eventMap.find(eventName);
        if (it != eventMap.end()) {
            for (const auto& callback : it->second) {
                try {
                    callback();
                } catch (const std::exception& e) {
                    std::cerr << "Event callback error: " << e.what() << std::endl;
                }
            }
        } else {
            std::cerr << "Event \"" << eventName << "\" not found!" << std::endl;
        }
    }

    void EventManager::removeEvent(const std::string& eventName) {
        auto it = eventMap.find(eventName);
        if (it != eventMap.end()) {
            eventMap.erase(it);
        } else {
            std::cerr << "Event \"" << eventName << "\" not found to remove!" << std::endl;
        }
    }

} // namespace Events
