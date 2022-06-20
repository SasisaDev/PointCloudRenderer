#pragma once

#include "Actor/Actor.h"

#include <vector>

class SScene : public SObject
{
protected:
	std::vector<SActor*> Actors;

public:

	const std::vector<SActor*>& GetActors() { return Actors; }

	void AddActor(SActor* Actor);
};