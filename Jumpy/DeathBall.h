#ifndef DEATHBALL_H
#define DEATHBALL_H

#include "GameEntity.h"

class DeathBall : public GameEntity {
public:
	DeathBall();
	void update(float deltaTime);
	void UsePhysics(float deltaTime);
	virtual ~DeathBall();

private:
	float moveSpeed;

	float velocityY;
	float gravity;
};

#endif // !DEATHBALL_H
