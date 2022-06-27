#pragma once
#include "../Widget.h"
#include "../Brush.h"

class UPanel : public UWidget
{
public:
	GENERATED_WIDGET_BODY(UPanel, UWidget)
	{
		mesh = new Mesh(Mesh::Plane());

		WidgetDetails.transform.x = 0;
		WidgetDetails.transform.y = 1;
		WidgetDetails.transform.cx = 350;
		WidgetDetails.transform.cy = 100;

		WidgetDetails.alignment.align = ALIGN_LEFT | ALIGN_TOP;
		
		brush = NewObject(
			SBrush, 
			"PanelBrush",
			NewObject(STexture2D, "PanelBrushTexture", "Textures/UI/Panel")
			);
	}
public:
	SBrush* brush;
	Mesh* mesh;

	virtual void OnPaint() override;
};

