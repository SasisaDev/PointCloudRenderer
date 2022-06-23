#pragma once

#include "../Object/Subsystem.h"
#include "Camera.h"

class SCameraSubsystem : public SSubsystem
{
public:
	SCameraSubsystem() : SSubsystem("CameraSubsystem") {}

	SCameraActor* Camera;
public:
	void SetCamera(SCameraActor* cam) { Camera = cam; }
};