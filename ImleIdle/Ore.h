#ifndef ORE_H
#define ORE_H

#include "GameEntity.h"

class Ore : public GameEntity
{
public:
	Ore();
	void update(float deltaTime);
	virtual ~Ore();
private:

};

#endif // !ORE_H