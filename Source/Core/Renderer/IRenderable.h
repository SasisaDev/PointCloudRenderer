#pragma once

class IRenderable
{
public:
	int RenderPriority = 0;

	virtual int Render() { return 0; }
};