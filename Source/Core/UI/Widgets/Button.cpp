#include "Button.h"

void UButton::Update(float dt)
{
	UWidget::Update(dt);
	if (brush->GetModel() != Model)
	{
		brush->SetModel(Model);
	}

	brush->UpdateSSBO();
}

void UButton::OnPaint()
{
	DrawBrush(mesh, brush);
}

bool UButton::OnButtonDown()
{
	Logger::Log("Click");
	brush->SetTint(PressedTint);
	brush->UpdateSSBO();
	return true;
}

bool UButton::OnButtonUp()
{
	if (bIsOverlaping)
	{
		brush->SetTint(SelectedTint);
		brush->UpdateSSBO();
	}
	return true;
}

bool UButton::OnOverlapBegin()
{
	if (!bIsOverlaping)
	{
		brush->SetTint(SelectedTint);
		brush->UpdateSSBO();
	}
	return true;
}

bool UButton::OnOverlapEnd()
{
	brush->SetTint(NormalTint);
	brush->UpdateSSBO();
	return true;
}
