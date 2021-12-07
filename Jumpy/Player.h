#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>

class Player : public Entity {
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
