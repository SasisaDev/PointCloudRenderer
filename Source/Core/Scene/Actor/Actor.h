#pragma once

#include "../../Object/Object.h"
#include "../../Renderer/IRenderable.h"

#include "../../Types/Transform.h"

#define GENERATED_ACTOR_BODY(className) className(std::string objectName) : SActor(objectName) {}  

struct ActorCreateInfo
{
	std::string objectName;
	Transform transform;

	ActorCreateInfo(std::string name, Transform trans = Transform())
	{
		objectName = name;
		transform = trans;
	}
};

class SActor : public SObject, public IRenderable
{
public:
	GENERATED_BODY(SActor)
};