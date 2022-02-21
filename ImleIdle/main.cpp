#include <rt2d/core.h>
#include "GameScene.h"

int main(void) 
{
	Core core;

	GameScene* gameScene = new GameScene();

	while (gameScene->isRunning())
	{
		core.run(gameScene);
	}
	delete gameScene;

	return 0;
}