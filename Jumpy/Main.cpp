#include <rt2d/core.h>
#include "MainScene.h"

int main(void) {

	Core core;

	MainScene* mainScene = new MainScene();
	while (mainScene->isRunning()) {
		core.run(mainScene);
	}
	delete mainScene;

	return 0;
}