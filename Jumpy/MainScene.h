#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <rt2d/scene.h>
#include "Player.h"

class MainScene : public Scene
{
public:
	MainScene();
	virtual ~MainScene();

private:
	Player* player;

};

#endif //MAINSCENE_H
