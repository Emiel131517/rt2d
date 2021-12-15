#include "Platform.h"

Platform::Platform() : GameEntity()
{
	width = 256;
	height = 32;
	speed = 50;
	position = Point2(300, 300);
	this->addSprite("Assets/Platform.tga");
}

Platform::~Platform()
{

}
void Platform::update(float deltaTime)
{
	position.y += speed * deltaTime;
}