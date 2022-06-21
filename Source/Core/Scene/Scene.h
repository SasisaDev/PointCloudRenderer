#pragma once
#include "./Actor/Actor.h"
#include <vector>

class SScene : public SObject
{
protected:
	std::vector<SActor*> Actors;

public:
	template <typename _ActorClass>
	SActor* SpawnActor(const ActorCreateInfo& Info);

	std::vector<SActor*> GetActors() { return Actors; }

	void LoadResources();
};

template<typename _ActorClass>
SActor* SScene::SpawnActor(const ActorCreateInfo& Info)
{
	SActor* Actor = new _ActorClass();

	// Initialize
	Actor->ObjectName = Info.objectName;

	Actors.push_back(Actor);
	return Actor;
}
