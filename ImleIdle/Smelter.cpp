#include "Smelter.h"

Smelter::Smelter() : GameEntity()
{
	timer = new Timer();
}
void Smelter::update(float deltaTime)
{
	if (timer->seconds() >= 1)
	{
		
	}
}
Smelter::~Smelter()
{
	delete timer;
}