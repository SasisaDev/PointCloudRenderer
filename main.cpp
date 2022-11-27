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

	//TEST
	SPointCloudAsset* asset = NewObject(SPointCloudAsset, "cloud");
	std::vector<CloudPoint> points = {
		CloudPoint(glm::vec3(0, 2, 0), glm::vec3(1, 0, 1)),
		CloudPoint(glm::vec3(1, 3, 0), glm::vec3(0, 0, 1)),
		CloudPoint(glm::vec3(2, 1, 1), glm::vec3(0, 1, 0))
	};
	asset->SetPoints(points);
	//

	SScene* MainScene = NewObject<SScene>("MainScene");
	SPointCloudActor* PointCloud = MainScene->SpawnActor<SPointCloudActor>(ActorCreateInfo("PointCloudActor"));
	PointCloud->PointCloud = asset;
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