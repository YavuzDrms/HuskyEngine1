#include "EventSystem.h"

namespace Husky
{
	void EventManager::subscribe(std::string& event_type, EventCallBack callback)
	{
		// Find or create event name in map
		// and add function to event
		listeners[event_type].push_back(callback);
	}

	void EventManager::publish(const std::string& event_type)
	{
		// Find the event
		auto it = listeners.find(event_type);
		// Run the function
		if (it != listeners.end())
		{
			for (auto& listener : it->second)
			{
				listener();
			}
		}
	}
}