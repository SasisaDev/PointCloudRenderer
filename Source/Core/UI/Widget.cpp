#include "Widget.h"

#include <glm/gtc/matrix_transform.hpp>

Transform2D UWidget::CalculateTransformOnScreenspace()
{
	Window* window = (Window*)glfwGetWindowUserPointer(glfwGetCurrentContext());
	if (window)
	{
		float SizeFactorX, SizeFactorY, aspect;
		int width, height;
		glfwGetWindowSize(window->GetHandle(), &width, &height);
		SizeFactorX = width / WIDGETSPACE_X;
		SizeFactorY = height / WIDGETSPACE_Y;
		aspect = (float)width/(float)height;

		Transform2D final = WidgetDetails.transform;
#define _bit(a, b )(WidgetDetails.alignment. a & b) == b

		if (_bit(stretch, STRETCH_VERTICAL))
		{
			final.cx = WidgetDetails.transform.cx;
			final.cy = (WidgetDetails.transform.cy * SizeFactorY);
		}
		else if (_bit(stretch, STRETCH_HORIZONTAL))
		{
			final.cx = (WidgetDetails.transform.cx * SizeFactorX);
			final.cy = WidgetDetails.transform.cy;
		}
		else
		{
			final.cx = WidgetDetails.transform.cx;
			final.cy = WidgetDetails.transform.cy;
		}

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
			final.y = ((WidgetDetails.transform.y * SizeFactorY) - height) * -1 - final.cy;
		}
		else if (_bit(align, ALIGN_LEFT))
		{
			if (!_bit(align, ALIGN_TOP))
			{
				if (_bit(align, ALIGN_BOTTOM))
				{
					final.y = (WidgetDetails.transform.y / height * SizeFactorY);
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

#undef _bit

		return final;
	}
	return Transform2D();
}

Transform2D UWidget::CalculateTransformOnWindow()
{
	Window* window = (Window*)glfwGetWindowUserPointer(glfwGetCurrentContext());
	if (window)
	{
		float SizeFactorX, SizeFactorY, aspect;
		int width, height;
		glfwGetWindowSize(window->GetHandle(), &width, &height);
		SizeFactorX = width / WIDGETSPACE_X;
		SizeFactorY = height / WIDGETSPACE_Y;
		aspect = (float)width / (float)height;

		Transform2D final = WidgetDetails.transform;
#define _bit(a, b )(WidgetDetails.alignment. a & b) == b

		if (_bit(stretch, STRETCH_VERTICAL))
		{
			final.cx = WidgetDetails.transform.cx;
			final.cy = (WidgetDetails.transform.cy * SizeFactorY);
		}
		else if (_bit(stretch, STRETCH_HORIZONTAL))
		{
			final.cx = (WidgetDetails.transform.cx * SizeFactorX);
			final.cy = WidgetDetails.transform.cy;
		}
		else
		{
			final.cx = WidgetDetails.transform.cx;
			final.cy = WidgetDetails.transform.cy;
		}

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
			final.y = (WidgetDetails.transform.y * SizeFactorY);
		}
		else if (_bit(align, ALIGN_LEFT))
		{
			if (!_bit(align, ALIGN_TOP))
			{
				if (_bit(align, ALIGN_BOTTOM))
				{
					final.y = (WidgetDetails.transform.y / height * SizeFactorY);
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
	for (auto child : Children)
	{
		child->Update(DeltaTime);
	}

	// TO-DO: Memoize
	Transform2D rect = CalculateTransformOnScreenspace();
	Model = glm::translate(glm::mat4(1), glm::vec3(rect.x, rect.y, /*Z-Depth*/ 0));
	Model = glm::scale(Model, glm::vec3(rect.cx, rect.cy, 1));
}

void UWidget::OnPaint()
{
}

bool UWidget::OnEvent(const Event& event)
{
	int x;
	int y;
	Transform2D screenspace;

	bool handled = false;

	for (auto child : Children)
	{
		handled |= child->OnEvent(event);
	}

	switch (event.EventAction)
	{
	case EVENT_MOUSEBUTTON_DOWN:
		x = reinterpret_cast<int>(event.Parameters[0]);
		y = reinterpret_cast<int>(event.Parameters[1]);

		screenspace = CalculateTransformOnWindow();

		if (x >= screenspace.x && x <= screenspace.x + screenspace.cx
			&& y >= screenspace.y && y <= screenspace.y + screenspace.cy)
		{
			Logger::Log("Click");
			this->OnButtonDown();
			return true;
		}
		break;
	case EVENT_MOUSEBUTTON_UP:
		x = reinterpret_cast<int>(event.Parameters[0]);
		y = reinterpret_cast<int>(event.Parameters[1]); 

		screenspace = CalculateTransformOnWindow();

		if (x >= screenspace.x && x <= screenspace.x + screenspace.cx
			&& y >= screenspace.y && y <= screenspace.y + screenspace.cy)
		{
			this->OnButtonUp();
			return true;
		}
		break;
	case EVENT_CURSOR_POSITION:
		x = reinterpret_cast<int>(event.Parameters[0]);
		y = reinterpret_cast<int>(event.Parameters[1]);

		screenspace = CalculateTransformOnWindow();

		if (x >= screenspace.x && x <= screenspace.x + screenspace.cx
			&& y >= screenspace.y && y <= screenspace.y + screenspace.cy)
		{
			bIsOverlaping = true;
			this->OnOverlapBegin();
		}
		else if(bIsOverlaping == true)
		{
			bIsOverlaping = false;
			this->OnOverlapEnd();
		}
		break;
	}

	return handled;
}

void UWidget::DrawBrush(Mesh* mesh, SBrush* brush)
{
	brush->Bind(0);

	glBindVertexArray(vao);

	mesh->Bind();

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,  // attribute
		3,                  // number of elements per vertex, here (x,y)
		GL_FLOAT,           // the type of each element
		GL_FALSE,           // take our values as-is
		0,                  // no extra data between each position
		0                   // offset of first element
	);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
