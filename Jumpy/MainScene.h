#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <rt2d/scene.h>
#include "Player.h"
#include "Platform.h"

class MainScene : public Scene
{
public:
	MainScene();
	void Physics(float deltaTime);
	virtual ~MainScene();
	void update(float deltaTime);

private:
	Player* player;
	//std::vector<Platform*> platforms;
	Platform* platform;
};

#endif //MAINSCENE_H
