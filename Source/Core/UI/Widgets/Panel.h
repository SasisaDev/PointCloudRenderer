#pragma once
#include "../Widget.h"
#include "../Brush.h"

class UPanel : public UWidget
{
public:
	unsigned int vao;
	GENERATED_WIDGET_BODY(UPanel, UWidget)
	{
		mesh = new Mesh(Mesh::Plane());

		WidgetDetails.transform.x = 100;
		WidgetDetails.transform.y = 350;
		WidgetDetails.transform.cx = 350;
		WidgetDetails.transform.cy = 100;

		WidgetDetails.alignment.align = ALIGN_LEFT | ALIGN_TOP;
		
		brush = NewObject(
			SBrush, 
			"PanelBrush",
			NewObject(STexture2D, "PanelBrushTexture", "Textures/UI/Panel")
			);

		glGenVertexArrays(1, &vao);
	}
public:
	SBrush* brush;
	Mesh* mesh;

	virtual void Update(float dt) override;
	virtual void OnPaint() override;
};

