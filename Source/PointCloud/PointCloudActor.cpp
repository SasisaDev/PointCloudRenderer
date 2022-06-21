#include "PointCloudActor.h"

int SPointCloudActor::Render()
{
	glBegin(GL_TRIANGLES);

	glVertex3f(-0.5f, -0.5f, 0);
	glVertex3f(0, 0.5f, 0);
	glVertex3f(0.5f, -0.5f, 0);

	glEnd();
	return 1;
}
