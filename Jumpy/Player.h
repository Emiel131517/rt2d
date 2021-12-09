#ifndef PLAYER_H
#define PLAYER_H

#include "GameEntity.h"

class Player : public GameEntity {
public:
	bool isGrounded;
	float moveSpeed;
	Vector2 velocity;
	Vector2 acceleration;
	Vector2 gravity;

	Player();
	virtual ~Player();
	virtual void update(float deltaTime);

private:

};

#endif // !PLAYER_H
