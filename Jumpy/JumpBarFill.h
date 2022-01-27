#ifndef JUMPBARFILL_H
#define JUMPBARFILL_H

#include "GameEntity.h"
#include "Player.h"

class JumpBarFill : public GameEntity
{
public:
	JumpBarFill();
	void update(float deltaTime);
	~JumpBarFill();

	float widthScale;
private:

};

#endif // !JUMPBARFILL_H
