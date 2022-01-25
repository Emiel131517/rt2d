#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <rt2d/scene.h>
#include "DeathBall.h"
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
	void SpawnPlatformRandomLoc();
	void SpawnDeathball(int Xposition, int Yposition);
	void SpawnDeathballRandomLoc();
	void UseColliders();
	void UseScreenBorders();
	void UseText();
	void SaveAndQuit();

	Player* player;
	std::vector<Platform*> platforms;
	std::vector<Background*> backgrounds;
	std::vector<DeathBall*> deathBalls;
	HudContainer* hudContainer;
	Timer platformTimer;
	Timer deathballTimer;

	int random;
};

#endif //MAINSCENE_H
