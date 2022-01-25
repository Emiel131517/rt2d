#ifndef PLAYER_H
#define PLAYER_H

#include "GameEntity.h"

class Player : public GameEntity {
public:
	bool isGrounded;

	float moveSpeed;
	float velocityY;
	float gravity;
	float jumpCharge;

	int score;
	int highScore;

	Player();
	virtual ~Player();

private:

	virtual void update(float deltaTime);
	void UseMovement(float deltaTime);
	void UsePhysics(float deltaTime);

	float minJumpForce;
	float maxJumpForce;
	float jumpForce;

};

#endif // !PLAYER_H
