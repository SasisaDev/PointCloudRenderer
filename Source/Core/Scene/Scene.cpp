#include "Scene.h"


void SScene::Update(float DeltaTime)
{
	for (auto actor : Actors)
	{
		actor->Update(DeltaTime);
	}
}

void SScene::DispatchEvent(const Event& event)
{
	for (auto actor : Actors)
	{
		actor->OnEvent(event);
	}
}

void SScene::LoadResources()
{
	for (auto actor : Actors)
	{
		//actor->LoadResources();
	}
}
