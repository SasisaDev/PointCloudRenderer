#pragma once
#include "../../Core/UI/Widgets/Panel.h"
#include "../../Core/UI/Widgets/Button.h"
#include "../../Core/Renderer/Mesh/Mesh.h"

class UMenubarWidget : public UPanel
{
public:
	GENERATED_WIDGET_BODY(UMenubarWidget, UPanel)
	{
		WidgetDetails.transform.x = 0;
		WidgetDetails.transform.y = 0;
		WidgetDetails.transform.cx = 1920;
		WidgetDetails.transform.cy = 20;

		brush->SetTint(TColor(0.15, 0.15, 0.15, 1));

		WidgetDetails.alignment.align = ALIGN_LEFT | ALIGN_TOP;
		WidgetDetails.alignment.stretch = STRETCH_HORIZONTAL;

		WidgetCreateInfo buttonFile = {};
		buttonFile.transform.x = 0;
		buttonFile.transform.y = 0;
		buttonFile.transform.cx = 50;
		buttonFile.transform.cy = 20;
		buttonFile.alignment.align = ALIGN_LEFT | ALIGN_TOP;

		AddChild(CreateWidget(UButton, "File", buttonFile));
	}
public:

};