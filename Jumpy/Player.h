#ifndef PLAYER_H
#define PLAYER_H

#include "GameEntity.h"

class Player : public GameEntity {
public:
	bool isGrounded;
	bool isJumping;

	float moveSpeed;
	float velocityY;
	float gravity;

	int score;

	Player();
	virtual ~Player();
	virtual void update(float deltaTime);  

private:

};

#endif // !PLAYER_H
