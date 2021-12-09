#include "Platform.h"

Platform::Platform() : GameEntity()
{
	width = 512;
	height = 64;
	speed = 50;
	scale = Point2(0.5f, 0.5f);
	position = Point2(400, 500);
	this->addSprite("Assets/Platform.tga");
}

Platform::~Platform()
{

}
void Platform::update(float deltaTime)
{
	position.y += speed * deltaTime;
}