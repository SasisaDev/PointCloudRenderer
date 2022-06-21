#include "src/Engine.h"
#include "src/PointCloud/PointCloudActor.h"

#define VERSION "0.0.1"

int main(int argc, char* argv[])
{
	Logger::Log("Point Cloud Renderer Ver " + LTEXT(VERSION));

	Engine* PCREngine = new Engine();

	Window* MainWindow = new Window("Point Cloud Renderer", 1280, 720);

	SScene* MainScene = new SScene();
	SPointCloudActor* PCA = new SPointCloudActor();
	PCA->ObjectName = "PointCloudActor";
	MainScene->AddActor(PCA);

	PCREngine->AddWindow(MainWindow);

	//UI
	SWidget* TestWidget = new SWidget();
	TestWidget->ObjectName = "TestUI";
	PCREngine->AddWidget(TestWidget);

	PCREngine->LoadScene(MainScene);

	PCREngine->RenderLoop();
	// Cleanup process

	delete PCREngine;
	return 0;
}