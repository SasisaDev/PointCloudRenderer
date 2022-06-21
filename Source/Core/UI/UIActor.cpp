#include "UIActor.h"

int SUIActor::Render()
{
	if (Widget)
	{
		Widget->Render();
	}
	return 1;
}
