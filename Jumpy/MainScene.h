#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <rt2d/scene.h>
#include "Player.h"
#include "Platform.h"
#include "timer.h"
#include "text.h"

class MainScene : public Scene
{
public:
	int random;

	MainScene();
	virtual ~MainScene();
	void UsePhysics(float deltaTime);
	void SpawnPlatform(int Xposition, int Yposition);
	void update(float deltaTime);
	void UseMovement(float deltaTime);
	void UseRandomPlatformSpawn();
	void UseColliders();
	void UseScreenBorders();
	void UseText();

private:
	Player* player;
	Platform* startPlatform;
	std::vector<Platform*> platforms;
	Timer timer;
	Text* scoreText;
};

#endif //MAINSCENE_H
