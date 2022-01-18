#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <rt2d/scene.h>
#include "Player.h"
#include "Platform.h"
#include "timer.h"
#include "text.h"
#include "Background.h"

class MainScene : public Scene
{
public:
	int random;

	MainScene();
	virtual ~MainScene();
	void update(float deltaTime);
	void CreateBackground(int Xposition, int Yposition);
	void SpawnPlatform(int Xposition, int Yposition);
	void UseRandomPlatformSpawn();
	void UseColliders();
	void UseScreenBorders();
	void UseText();

private:
	Player* player;
	Text* scoreText;
	Background* background;
	std::vector<Platform*> platforms;
	std::vector<Background*> backgrounds;
	Timer timer;
};

#endif //MAINSCENE_H
