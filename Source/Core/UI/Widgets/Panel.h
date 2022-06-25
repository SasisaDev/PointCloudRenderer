#pragma once
#include "../Widget.h"
#include "../Brush.h"

class UPanel : public UWidget
{
public:
	GENERATED_WIDGET_BODY(UPanel, UWidget)
	{

	}
public:
	SBrush* brush;
};

