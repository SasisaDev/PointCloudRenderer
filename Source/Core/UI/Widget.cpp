#include "Widget.h"

Transform2D UWidget::CalculateTransformOnScreenspace()
{
	Window* window = (Window*)glfwGetWindowUserPointer(glfwGetCurrentContext());
	if (window)
	{
		float SizeFactorX, SizeFactorY;
		int x, y;
		glfwGetWindowSize(window->GetHandle(), &x, &y);
		SizeFactorX = x / WIDGETSPACE_X;
		SizeFactorY = y / WIDGETSPACE_Y;
	}
	return Transform2D();
}

void UWidget::AddChild(UWidget* child)
{
	Children.push_back(child);
}

void UWidget::Render()
{
	OnPaint();
	for (auto child : Children)
	{
		child->Render();
	}
}

void UWidget::OnPaint()
{
}
