#pragma once
#include "../Widget.h"
#include "../Brush.h"

class UPanel : public UWidget
{
public:
	GENERATED_WIDGET_BODY(UPanel, UWidget)
	{
		mesh = new Mesh(Mesh::Plane(0, 0, 100, 100));
		
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

