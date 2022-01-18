#ifndef COLLIDER_H
#define COLLIDER_H

#include "GameEntity.h"
class Collider
{
public:
	static bool SquareIsColliding(const GameEntity* ent1, const GameEntity* ent2)
	{
		if (ent1->position.x - ent1->width	/ 2 < ent2->position.x - ent2->width / 2	+ ent2->width &&
			ent1->position.x - ent1->width	/ 2 + ent1->width > ent2->position.x		- ent2->width / 2 &&
			ent1->position.y - ent1->height / 2 < ent2->position.y - ent2->height / 2	+ ent2->height &&
			ent1->position.y - ent1->height / 2 + ent1->height > ent2->position.y		- ent2->height / 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:

};
#endif // !COLLIDER_H