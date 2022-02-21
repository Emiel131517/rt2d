#ifndef SMELTER_H
#define SMELTER_H

#include "GameEntity.h"

class Smelter : public GameEntity
{
public:
	Smelter();
	virtual ~Smelter();
private:
	Timer* timer;
	void update(float deltaTime);
};

#endif // !SMELTER_H