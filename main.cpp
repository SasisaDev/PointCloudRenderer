#include "Source/Core/Application.h"

#include "Source/PointCloud/PointCloudActor.h"

#include "Source/Core/Object/Pipeline/Material.h"
#include "Source/Core/Debug/DebugActor.h"
#include "Source/Core/Camera/CameraSubsystem.h"

#define VERSION "0.0.1"

int main(int argc, char* argv[])
{
	Logger::Log("Point Cloud Renderer Ver " + std::string(VERSION) + " (OpenGL)");

	Application* App = new Application();

	Engine* PCREngine = App->CreateEngine("Cloud Point Renderer", 1280, 720);

	SScene* MainScene = NewObject<SScene>("MainScene");
	SPointCloudActor* PointCloud = MainScene->SpawnActor<SPointCloudActor>(ActorCreateInfo("PointCloudActor"));
	SDebugActor* DbgActor = MainScene->SpawnActor<SDebugActor>(ActorCreateInfo("DebugActor"));
	{
		DbgActor->ActorConfig.transform.Location.z = -2;
		DbgActor->ActorConfig.transform.Scale = glm::vec3(1);
	}
	SCameraActor* Camera = MainScene->SpawnActor<SCameraActor>(ActorCreateInfo("Camera"));

	SCameraSubsystem* CamSystem = MainScene->CreateSubsystem<SCameraSubsystem>();

	UWidget* TestWidget = CreateWidget<UWidget>("MainWidget", WidgetCreateInfo());
	//PCREngine->AddWidget();

	PCREngine->SetScene(MainScene);

	App->Loop();
	// Cleanup process

	delete App;
	return 0;
}