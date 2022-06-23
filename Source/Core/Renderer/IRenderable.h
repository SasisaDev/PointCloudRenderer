#pragma once

struct CameraModel;

class IRenderable
{
public:
	int RenderPriority = 0;

	virtual int Render(const CameraModel& camera) { return 0; }
};