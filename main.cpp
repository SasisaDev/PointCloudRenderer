#include "src/Engine.h"

#define VERSION "0.0.1"

int main(int argc, char* argv[])
{
	Logger::Log("Point Cloud Renderer Ver " + LTEXT(VERSION));

	Engine* PCREngine = new Engine();

	Window* MainWindow = new Window("Test", 1280, 720);

	PCREngine->AddWindow(MainWindow);

	PCREngine->RenderLoop();
	// Cleanup process

	delete PCREngine;
	return 0;
}