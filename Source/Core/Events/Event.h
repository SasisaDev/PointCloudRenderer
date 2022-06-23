#pragma once

#include <functional>
#include <vector>

#define EVENT_MOUSEBUTTON_DOWN 1
#define EVENT_MOUSEBUTTON_UP 2
#define EVENT_KEY_DOWN 3
#define EVENT_KEY_UP 4
#define EVENT_CURSOR_POSITION 5
#define EVENT_WINDOW_RESIZE 6
#define EVENT_QUIT 7

class Event
{
public:
	unsigned int EventAction;
	std::vector<void*> Parameters;

	Event(unsigned int Action, std::vector<void*> Params);

	bool IsKey(int key);
};