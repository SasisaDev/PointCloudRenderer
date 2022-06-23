#include "EventDispatcher.h"

void EventDispatcher::Subscribe(const std::function<void(const Event&)>& sub)
{
	Subscribers.push_back(sub);
}

void EventDispatcher::Dispatch(const Event& event)
{
	for (auto func : Subscribers)
	{
		if (func)
		{
			func(event);
		}
	}
}
