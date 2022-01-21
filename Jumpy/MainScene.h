#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <rt2d/scene.h>
#include "Player.h"
#include "Platform.h"
#include "timer.h"
#include "HudContainer.h"
#include "Background.h"
#include "GameData.h"

class MainScene : public Scene
{
public:

	MainScene();
	virtual ~MainScene();

private:

	void update(float deltaTime);
	void CreateBackground(int Xposition, int Yposition);
	void SpawnPlatform(int Xposition, int Yposition);
	void UseRandomPlatformSpawn();
	void UseColliders();
	void UseScreenBorders();
	void UseText();
	void SaveAndQuit();

	Player* player;
	std::vector<Platform*> platforms;
	std::vector<Background*> backgrounds;
	HudContainer* hudContainer;
	Timer timer;

	int random;
};

#endif //MAINSCENE_H
