#pragma once

#include "../Scene/Actor/Actor.h"
#include "Widget.h"

class SUIActor : public SActor
{
public:
	SUIActor(std::string objectName) : SActor(objectName)
	{
		// Force to render last
		RenderPriority = -99;
	}

public:
	UWidget* Widget;

	virtual int Render(const CameraModel& camera) override;
};