#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <functional>
#include <unordered_map>
#include <vector>
#include <string>

namespace Events {

    // Event types kunnen als strings worden geïdentificeerd
    using EventCallback = std::function<void()>;

    class EventManager {
    public:
        // Singleton pattern om één instance van EventManager te beheren
        static EventManager& getInstance();

        // Gebeurtenisregistratie
        void registerEvent(const std::string& eventName, EventCallback callback);

        // Gebeurtenisuitvoering
        void triggerEvent(const std::string& eventName);

        // Gebeurtenisverwijdering
        void removeEvent(const std::string& eventName);

    private:
        EventManager() = default;
        ~EventManager() = default;

        // Verbied kopiëren en toewijzen om singleton te beschermen
        EventManager(const EventManager&) = delete;
        EventManager& operator=(const EventManager&) = delete;

        std::unordered_map<std::string, std::vector<EventCallback>> eventMap;
    };

} // namespace Events

#endif // EVENT_MANAGER_H
