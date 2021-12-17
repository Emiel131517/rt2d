#ifndef PLAYER_H
#define PLAYER_H

#include "GameEntity.h"

class Player : public GameEntity {
public:
	bool isGrounded;
	bool isJumping;

	float moveSpeed;
	float velocityY, velocityX;
	float gravity;

	Player();
	virtual ~Player();
	virtual void update(float deltaTime);  

private:

};

#endif // !PLAYER_H
