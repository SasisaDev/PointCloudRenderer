#pragma once
#include "./Actor/Actor.h"
#include <vector>

class SScene : public SObject
{
protected:
	std::vector<SActor*> Actors;

public:
	template <typename _ActorClass>
	SActor* SpawnActor(ActorCreateInfo Info);
};
