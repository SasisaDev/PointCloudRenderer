#pragma once

#include "../Layer.h"
#include "../../../UI/Widget.h"

class WidgetLayer : public Layer
{
	std::vector<SWidget*> _widgets;
public:
	void SetWidgets(const std::vector<SWidget*>& widgets) { _widgets = widgets; }
};