#ifndef PLAYER_H
#define PLAYER_H

#include "GameEntity.h"
#include "Smelter.h"

class Player : public GameEntity
{
public:
	Player();
	virtual ~Player();

	int level;
	int xp;
	int xpNeed;
	int money;

	
private:
	void update(float deltaTime);
	void LevelUp();
	void BuySmelter();

	std::vector<Smelter*> smelters;
	bool smelterUnlock;
};

#endif // !PLAYER_H