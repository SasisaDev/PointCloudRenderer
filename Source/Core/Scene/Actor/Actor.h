#pragma once

#include "../../Object/Object.h"
#include "../../Renderer/IRenderable.h"
#include "../Events/Event.h"

#include "../../Types/Transform.h"

#define GENERATED_ACTOR_BODY(className) className(std::string objectName) : SActor(objectName) {}  

typedef struct ActorCreateInfo
{
	std::string objectName;
	Transform transform;

	ActorCreateInfo() {}
	ActorCreateInfo(std::string name, Transform trans = Transform())
	{
		objectName = name;
		transform = trans;
	}
} ActorInfo;

class SActor : public SObject, public IRenderable
{
public:
	ActorInfo ActorConfig;

public:
	GENERATED_BODY(SActor)

	virtual void Update(float DeltaTime) {}
	virtual void OnEvent(const Event& event) {}
};