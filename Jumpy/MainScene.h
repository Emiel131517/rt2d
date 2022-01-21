#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <rt2d/scene.h>
#include "Player.h"
#include "Platform.h"
#include "timer.h"
#include "text.h"
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
	Text* scoreText;
	Text* jumpText;
	Text* highScoreText;
	std::vector<Platform*> platforms;
	std::vector<Background*> backgrounds;
	Timer timer;

	int random;
};

#endif //MAINSCENE_H
