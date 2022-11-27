#include "DropMenu.h"

void UDropMenu::AddChild(UWidget* child)
{
	child->WidgetDetails.transform.cx = WidgetDetails.transform.cx;
	child->WidgetDetails.transform.x = WidgetDetails.transform.x;
	child->WidgetDetails.transform.y = (Children.size() > 0) ? Children[Children.size() - 1]->WidgetDetails.transform.y + Children[Children.size() - 1]->WidgetDetails.transform.cy : WidgetDetails.transform.y;

	child->WidgetDetails.alignment.align = WidgetDetails.alignment.align;
	child->WidgetDetails.alignment.stretch = 0;

	UPanel::AddChild(child);
}

void UDropMenu::Update(float DeltaTime)
{
	UPanel::Update(DeltaTime);
}
