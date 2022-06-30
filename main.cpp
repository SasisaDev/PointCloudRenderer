#include "Source/Core/Application.h"

#include "Source/PointCloud/PointCloudActor.h"

#include "Source/Core/Object/Pipeline/Material.h"
#include "Source/Core/Debug/DebugActor.h"
#include "Source/PointCloud/Camera/PointCloudCamera.h"

#include "Source/PointCloud/UI/MenubarWidget.h"

#define VERSION "0.0.1"

int main(int argc, char* argv[])
{
	Logger::Log("Point Cloud Renderer Ver " + std::string(VERSION) + " (OpenGL)");

	Application* App = new Application();

	Engine* PCREngine = App->CreateEngine("Cloud Point Renderer", 1280, 720);

	SScene* MainScene = NewObject<SScene>("MainScene");
	SPointCloudActor* PointCloud = MainScene->SpawnActor<SPointCloudActor>(ActorCreateInfo("PointCloudActor"));
	PointCloud->RebuildMesh();
	SDebugActor* DbgActor = MainScene->SpawnActor<SDebugActor>(ActorCreateInfo("DebugActor"));
	{
		DbgActor->ActorConfig.transform.Location.z = -4;
		DbgActor->ActorConfig.transform.Scale = glm::vec3(1);
	}
	SDebugActor* DbgActor2 = MainScene->SpawnActor<SDebugActor>(ActorCreateInfo("DebugActor2"));
	{
		DbgActor2->ActorConfig.transform.Location.z = -8;
		DbgActor2->ActorConfig.transform.Location.x = 4;
		DbgActor2->ActorConfig.transform.Scale = glm::vec3(2);
	}
	SDebugActor* DbgActor3 = MainScene->SpawnActor<SDebugActor>(ActorCreateInfo("DebugActor3"));
	{
		DbgActor3->ActorConfig.transform.Location.z = -4;
		DbgActor3->ActorConfig.transform.Location.x = -7;
		DbgActor3->ActorConfig.transform.Scale = glm::vec3(0.25);
	}
	SPointCloudCameraActor* Camera = MainScene->SpawnActor<SPointCloudCameraActor>(ActorCreateInfo("Camera"));

	UMenubarWidget* TestWidget = CreateWidget(UMenubarWidget, "MainWidget", WidgetCreateInfo());
	PCREngine->AddWidget(TestWidget);

	PCREngine->SetScene(MainScene);

	App->Loop();
	// Cleanup process

	delete App;
	return 0;
}