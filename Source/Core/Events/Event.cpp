#include "Event.h"

Event::Event(unsigned int Action, std::vector<void*> Params)
{
	EventAction = Action;
	Parameters = Params;
}

bool Event::IsKey(int key)
{
	if (EventAction == EVENT_KEY_DOWN || EventAction == EVENT_KEY_UP)
	{
		if (Parameters.size() > 0)
		{
			if (reinterpret_cast<int>(Parameters[0]) == key)
			{
				return false;
			}
		}
	}
	return false;
}
