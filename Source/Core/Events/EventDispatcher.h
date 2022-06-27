#pragma once

#include "Event.h"
#include <functional>

enum class InputMode : uint8_t
{
	// Hides and locks cursor, click events go into UI first, and only then to scene
	INPUT_CONSUME,
	// Forces UI Layer to consume events and ignore game
	INPUT_UI_CONSUME,
	// Forces game to consume events and ignore UI
	INPUT_GAME_CONSUME,
	// Cursor is visible and not locked, events go into UI first, and only then to scene
	INPUT_DEFAULT
};

class EventDispatcher
{
protected:
	std::vector<std::function<void(const Event&)>> Subscribers;

public:
	void Subscribe(const std::function<void(const Event&)>& sub);
	
	void Dispatch(const Event& event);
};