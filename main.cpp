#include "src/Engine.h"

int main(int argc, char* argv[])
{
	Engine* PCREngine = new Engine();

	Window* MainWindow = new Window("Test", 1280, 720);

	PCREngine->AddWindow(MainWindow);

	PCREngine->RenderLoop();
	// Cleanup process

	delete PCREngine;
	return 0;
}