#include "Panel.h"

void UPanel::Update(float dt)
{
	UWidget::Update(dt);
	if (brush->GetModel() != Model)
	{
		brush->SetModel(Model);
		brush->UpdateSSBO();
	}
}

void UPanel::OnPaint()
{
	glBindVertexArray(vao);
	DrawBrush(mesh, brush);
}
