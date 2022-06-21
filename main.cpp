#include "Source/Core/Engine.h"

#define VERSION "0.0.1"

int main(int argc, char* argv[])
{
	Logger::Log("Point Cloud Renderer Ver " + STEXT(VERSION) + " (OpenGL)");

	Engine* PCREngine = new Engine();

	Window* MainWindow = new Window("Point Cloud Renderer", 1280, 720);

	SScene* MainScene = new SScene();
	SActor* TestActor = MainScene->SpawnActor<SActor>(ActorCreateInfo("TestActor"));
	MainWindow->SetScene(MainScene);

	PCREngine->AddWindow(MainWindow);

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