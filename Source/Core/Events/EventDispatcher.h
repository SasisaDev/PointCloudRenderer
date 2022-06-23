#pragma once

#include "Event.h"
#include <functional>

class EventDispatcher
{
protected:
	std::vector<std::function<void(const Event&)>> Subscribers;

public:
	void Subscribe(const std::function<void(const Event&)>& sub);
	
	void Dispatch(const Event& event);
};