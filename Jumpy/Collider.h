#ifndef COLLIDER_H
#define COLLIDER_H

#include "GameEntity.h"
class Collider
{
public:
	static bool isColliding(GameEntity* entity, GameEntity* obj2)
	{
		if (obj1->position.x < obj2->position.x +	obj2->width &&
			obj1->position.x + obj1->width >		obj2->position.x &&
			obj1->position.y < obj2->position.y +	obj2->height &&
			obj1->position.y + obj1->height >		obj2->position.y)
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