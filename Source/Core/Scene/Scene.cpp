#include "Scene.h"

template<typename _ActorClass>
inline SActor* SScene::SpawnActor(ActorCreateInfo Info)
{
	SActor* Actor = new _ActorClass();

	// Initialize
	Actor->ObjectName = Info.objectName;

	Actors.push_back(Actor);
	return Actor;
}