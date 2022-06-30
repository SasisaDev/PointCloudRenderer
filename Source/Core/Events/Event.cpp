#include "Event.h"

Event::Event(unsigned int Action, std::vector<void*> Params)
{
	EventAction = Action;
	Parameters = Params;
}

bool Event::IsKey(int key) const
{
	if (EventAction == EVENT_KEY_DOWN || EventAction == EVENT_KEY_UP || EventAction == EVENT_KEY)
	{
		if (Parameters.size() > 0)
		{
			if (reinterpret_cast<int>(Parameters[0]) == key)
			{
				return true;
			}
		}
	}
	return false;
}

bool Event::IsMouseButton(int btn) const
{
	if (EventAction == EVENT_MOUSEBUTTON_DOWN || EventAction == EVENT_MOUSEBUTTON_UP || EventAction == EVENT_MOUSEBUTTON)
	{
		if (Parameters.size() >= 3)
		{
			if (reinterpret_cast<int>(Parameters[2]) == btn)
			{
				return true;
			}
		}
	}
	return false;
}
