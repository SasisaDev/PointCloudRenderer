#include "Scene.h"

void SScene::AddActor(SActor* Actor)
{
	if (Actor)
	{
		Actors.push_back(Actor);
	}
}
