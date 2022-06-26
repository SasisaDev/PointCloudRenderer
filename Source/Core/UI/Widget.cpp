#include "Widget.h"

Transform2D UWidget::CalculateTransformOnScreenspace()
{
	Window* window = (Window*)glfwGetWindowUserPointer(glfwGetCurrentContext());
	if (window)
	{
		float SizeFactorX, SizeFactorY, aspect;
		int x, y;
		glfwGetWindowSize(window->GetHandle(), &x, &y);
		SizeFactorX = x / WIDGETSPACE_X;
		SizeFactorY = y / WIDGETSPACE_Y;
		aspect = (float)x/(float)y;

		Transform2D final = {};
#define _bit(a, b )(WidgetDetails.alignment. a & b) == b

		if (_bit(align, ALIGN_BOTTOM))
		{
			if (!_bit(align, ALIGN_LEFT))
			{
				if (_bit(align, ALIGN_RIGHT))
				{
					final.x = (WidgetDetails.transform.x * SizeFactorX);
				}
				else
				{
					final.x = (WidgetDetails.transform.x);
				}
			}
			final.y = (WidgetDetails.transform.y * SizeFactorY);
		}
		else if (_bit(align, ALIGN_TOP))
		{
			if (!_bit(align, ALIGN_LEFT))
			{
				if (_bit(align, ALIGN_RIGHT))
				{
					final.x = (WidgetDetails.transform.x * SizeFactorX);
				}
			}
			final.y = (WidgetDetails.transform.y);
		}
		else if (_bit(align, ALIGN_LEFT))
		{
			if (!_bit(align, ALIGN_TOP))
			{
				if (_bit(align, ALIGN_BOTTOM))
				{
					final.y = (WidgetDetails.transform.y / y * SizeFactorY);
				}
				final.y = (WidgetDetails.transform.y * SizeFactorY);
				final.x = (WidgetDetails.transform.x);
			}
		}
		else if (_bit(align, ALIGN_RIGHT))
		{
			if (!_bit(align, ALIGN_TOP))
			{
				if (_bit(align, ALIGN_BOTTOM))
				{
					final.y = (WidgetDetails.transform.y * SizeFactorX);
				}
				else
				{
					final.y = (WidgetDetails.transform.y);
				}
				final.x = (WidgetDetails.transform.x * SizeFactorX);
			}
		}

		if (_bit(stretch, STRETCH_VERTICAL))
		{
			final.cy = (WidgetDetails.transform.cy * SizeFactorY);
		}
		else if (_bit(stretch, STRETCH_HORIZONTAL))
		{
			final.cx = (WidgetDetails.transform.cx * SizeFactorX);
		}

#undef _bit

		return final;
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

void UWidget::Update(float DeltaTime)
{
}

void UWidget::OnPaint()
{
}

void UWidget::DrawBrush(Mesh* mesh, SBrush* brush)
{
	mesh->Bind();

	brush->Bind(0);

	glDrawElements(GL_TRIANGLES, mesh->meshData.vertices.size() / 3, GL_FLOAT, nullptr);

	brush->Unbind();

	mesh->Unbind();
}
