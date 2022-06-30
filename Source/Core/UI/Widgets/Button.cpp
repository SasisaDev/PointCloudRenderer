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

void UButton::OnOverlapBegin()
{
	brush->SetTint(SelectedTint);
	brush->UpdateSSBO();
}

void UButton::OnOverlapEnd()
{
	brush->SetTint(NormalTint);
	brush->UpdateSSBO();
}
