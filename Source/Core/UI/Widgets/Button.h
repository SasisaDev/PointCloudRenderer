#pragma once

#include "../Widget.h"

class UButton : public UWidget
{
protected:
	std::function<void()> clickCallback;
public:
	GENERATED_WIDGET_BODY(UButton, UWidget)
	{
		mesh = new Mesh(Mesh::Plane());

		//WidgetDetails.transform.x = 0;
		//WidgetDetails.transform.y = 0;
		//WidgetDetails.transform.cx = 24*2.5f;
		//WidgetDetails.transform.cy = 24;

		//WidgetDetails.alignment.align = ALIGN_LEFT | ALIGN_TOP;
		//WidgetDetails.alignment.stretch = STRETCH_HORIZONTAL;

		brush = NewObject(
			SBrush,
			"ButtonBrush",
			NewObject(STexture2D, "ButtonBrushTexture", "Textures/UI/Button")
		);

		brush->SetTint(NormalTint);
		brush->UpdateSSBO();
	}

	TColor	NormalTint = TColor(0.1, 0.1, 0.1, 1), 
			SelectedTint = TColor(0.12, 0.12, 0.12, 1), 
			PressedTint = TColor(0.075, 0.075, 0.075, 1);

	SBrush* brush;
	Mesh* mesh;

	UButton* OnClickCallback(const std::function<void()>& callback) { clickCallback = callback; return this; }

	virtual void Update(float dt) override;
	virtual void OnPaint() override;

	virtual bool OnButtonDown() override;
	virtual bool OnButtonUp() override;
			
	virtual bool OnOverlapBegin() override;
	virtual bool OnOverlapEnd() override;
};

