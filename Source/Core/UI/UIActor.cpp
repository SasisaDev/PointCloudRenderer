#include "UIActor.h"

int SUIActor::Render(const CameraModel& camera)
{
	if (Widget)
	{
		Widget->Render();
	}
	return 1;
}
