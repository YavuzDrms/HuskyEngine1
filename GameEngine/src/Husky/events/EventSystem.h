#ifndef EVENTSYSTEM_H
#define EVENTSYSTEM_H

#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
#include <string>

namespace Husky
{
	class EventManager
	{
	public:
		using EventCallBack = std::function<void()>;

		// Add event to listeners
		// event_type = event name
		// callback = function
		void subscribe(std::string& event_type, EventCallBack callback);

		// Find the event by name
		// and run (function in the subscribe
		// event_type = event name
		void publish(const std::string& event_type);
	private:
		std::unordered_map<std::string, std::vector<EventCallBack>> listeners;

	};
}

#endif // EVENTSYSTEM_H