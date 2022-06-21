#include "Source/Core/Engine.h"

#include "Source/PointCloud/PointCloudActor.h"

#define VERSION "0.0.1"

int main(int argc, char* argv[])
{
	Logger::Log("Point Cloud Renderer Ver " + STEXT(VERSION) + " (OpenGL)");

	Engine* PCREngine = new Engine();

	Window* MainWindow = new Window("Point Cloud Renderer", 1280, 720);

	SScene* MainScene = NewObject<SScene>("MainScene");
	MainScene->ObjectName = "PointCloudScene";
	SPointCloudActor* TestActor = MainScene->SpawnActor<SPointCloudActor>(ActorCreateInfo("PointCloudActor"));

	PCREngine->AddWindow(MainWindow);

	MainWindow->SetScene(MainScene);

	Window* HelpWindow = new Window("Help", 500, 250);
	PCREngine->AddWindow(HelpWindow);

	//UI
	//SWidget* TestWidget = new SWidget();
	//TestWidget->ObjectName = "TestUI";
	//PCREngine->AddWidget(TestWidget);

	//PCREngine->LoadScene(MainScene);

	PCREngine->EngineLoop();
	// Cleanup process

	delete PCREngine;
	return 0;
}