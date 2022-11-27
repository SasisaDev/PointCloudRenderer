#pragma once
#include "Panel.h"
class UDropMenu : public UPanel
{
public:
	GENERATED_WIDGET_BODY(UDropMenu, UPanel)
	{
		brush->SetTint(TColor(0.06, 0.06, 0.06, 1));
	}

	virtual void AddChild(UWidget* child) override;

	virtual void Update(float DeltaTime) override;
};

