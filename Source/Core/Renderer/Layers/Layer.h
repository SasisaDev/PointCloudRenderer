#pragma once

#include "../../Events/Event.h"

class Layer
{
public:

	// Applied on attachment
	virtual void OnAttach() {}
	// Applied on deattachment
	virtual void OnDetach() {}
	// Applied on state update
	virtual void OnUpdate() {}
	// Called for render
	virtual void Render(unsigned int framebuffer) {}
	// Event dispatcher events
	virtual void OnEvent(const Event& e) {}
};