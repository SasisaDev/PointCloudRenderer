#pragma once
#include "./Actor/Actor.h"
#include <vector>

class SScene : public SObject
{
protected:
	std::vector<SActor*> Actors;

public:
	SScene(std::string objectName) : SObject(objectName){}

	template <typename _ActorClass>
	_ActorClass* SpawnActor(const ActorCreateInfo& Info);

	std::vector<SActor*> GetActors() { return Actors; }

	void LoadResources();
};

template<typename _ActorClass>
_ActorClass* SScene::SpawnActor(const ActorCreateInfo& Info)
{
	_ActorClass* Actor = new _ActorClass(Info.objectName);

	// Initialize

	Actors.push_back(Actor);
	return Actor;
}
