#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <rt2d/scene.h>
#include "Player.h"
#include "LayerEntity.h"

class GameScene : public Scene 
{
public:
	GameScene();
	void update(float deltaTime);
	virtual ~GameScene();
private:
	Player* player;
	std::vector<LayerEntity*> layers;
};

#endif // !GAMESCENE_H