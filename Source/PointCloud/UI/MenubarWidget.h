#pragma once
#include "../../Core/UI/Widget.h"
#include "../../Core/Renderer/Mesh/Mesh.h"

class UMenubarWidget : public UWidget
{
public:
	GENERATED_WIDGET_BODY(UMenubarWidget, UWidget)
	{


		mesh = new Mesh();
	}

	Mesh* mesh;
public:

	virtual void OnPaint() override;
};