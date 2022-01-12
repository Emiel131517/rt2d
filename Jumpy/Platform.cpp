#include "Platform.h"

Platform::Platform() : GameEntity()
{
	giveScore = false;

	width = 256;
	height = 32;
	speed = 90;
	this->addSprite("Assets/Platform.tga");
}

Platform::~Platform()
{

}
void Platform::update(float deltaTime)
{
	position.y += speed * deltaTime;
}