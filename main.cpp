#include "Source/Core/Engine.h"

#include "Source/PointCloud/PointCloudActor.h"
#include "Source/Core/UI/UIActor.h"

#include "Source/Core/Object/Pipeline/Material.h"
#include "Source/Core/Debug/DebugActor.h"

#define VERSION "0.0.1"

int main(int argc, char* argv[])
{
	Logger::Log("Point Cloud Renderer Ver " + std::string(VERSION) + " (OpenGL)");

	Engine* PCREngine = new Engine();

	Window* MainWindow = new Window("Point Cloud Renderer", 1280, 720);

	SScene* MainScene = NewObject<SScene>("MainScene");
	SPointCloudActor* PointCloud = MainScene->SpawnActor<SPointCloudActor>(ActorCreateInfo("PointCloudActor"));
	SUIActor* UI = MainScene->SpawnActor<SUIActor>(ActorCreateInfo("UserInterfaceSubsystem"));
	SDebugActor* DbgActor = MainScene->SpawnActor<SDebugActor>(ActorCreateInfo("DebugActor"));

	UWidget* TestWidget = CreateWidget<UWidget>("MainWidget", WidgetCreateInfo());
	UI->Widget = TestWidget;

	PCREngine->AddWindow(MainWindow);

	MainWindow->SetScene(MainScene);

	Window* HelpWindow = new Window("Help", 500, 250);
	PCREngine->AddWindow(HelpWindow);

	Shader PostProcessShader("Shaders/PostProcessing");
	((OpenGLRenderer*)MainWindow->GetRenderer())->SetPostProcessShader(&PostProcessShader);

	PCREngine->EngineLoop();
	// Cleanup process

	delete PCREngine;
	return 0;
}