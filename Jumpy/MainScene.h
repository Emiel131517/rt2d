#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <rt2d/scene.h>
#include "Player.h"
#include "Platform.h"
#include "timer.h"

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
	void UseScreenBorders();
	void UseColliders();

private:
	Player* player;
	Platform* startPlatform;
	std::vector<Platform*> platforms;
	Timer timer;
};

#endif //MAINSCENE_H
