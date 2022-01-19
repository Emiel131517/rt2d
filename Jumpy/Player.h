#ifndef PLAYER_H
#define PLAYER_H

#include "GameEntity.h"

class Player : public GameEntity {
public:
	bool isGrounded;
	bool isJumping;

	int minJumpForce;
	int maxJumpForce;
	int jumpForce;
	int jumpCharge;

	int moveSpeed;
	float velocityY;
	int gravity;

	int score;

	Player();
	virtual ~Player();
	virtual void update(float deltaTime); 
	void UseMovement(float deltaTime);
	void UsePhysics(float deltaTime);

private:

};

#endif // !PLAYER_H
