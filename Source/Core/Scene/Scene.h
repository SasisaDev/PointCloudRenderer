#pragma once
#include "./Actor/Actor.h"
#include "../Object/Subsystem.h"
#include <vector>
#include <type_traits>

class SScene : public SObject
{
protected:
	std::vector<SActor*> Actors;
	std::vector<SSubsystem*> Subsystems;

public:
	SScene(std::string objectName) : SObject(objectName) {
		Actors = std::vector<SActor*>();
		Subsystems.resize(0);
	}

	void Update(float DeltaTime);

	template <typename _ActorClass>
	_ActorClass* SpawnActor(const ActorCreateInfo& Info);
	template <typename _ActorClass>
	std::vector<_ActorClass*> GetActors();

	template <typename _SysClass>
	_SysClass* CreateSubsystem();

	template <typename _SysClass>
	_SysClass* GetSubsystem();

	//std::vector<SActor*> GetActors() { return Actors; }
	std::vector<SSubsystem*> GetSubsystems() { return Subsystems; }

	void DispatchEvent(const Event& event);

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

template<typename _ActorClass>
inline std::vector<_ActorClass*> SScene::GetActors()
{
	std::vector<_ActorClass*> array;
	for (SActor* actor : Actors)
	{
		if (_ActorClass* typedActor = dynamic_cast<_ActorClass*>(actor))
		{
			array.push_back(typedActor);
		}
	}
	return array;
}

template<typename _SysClass>
_SysClass* SScene::CreateSubsystem()
{
	_SysClass* Subsystem = new _SysClass();
	Subsystems.push_back(Subsystem);
	return Subsystem;
}

template<typename _SysClass>
_SysClass* SScene::GetSubsystem()
{
	try {
		/*if (Subsystems.size() > 0)
		{
			_SysClass* tester = new _SysClass();
			for (SSubsystem* subsystem : Subsystems)
			{
				if (subsystem->ObjectName == tester->ObjectName)
				{
					delete tester;
					return static_cast<_SysClass*>(subsystem);
				}
			}
			delete tester;
		}*/
	}
	catch (std::exception& exc)
	{

	}
	
	return nullptr;
}
