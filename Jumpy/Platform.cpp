#include "Platform.h"

Platform::Platform() : Entity()
{
	this->addSprite("Assets/Platform.tga");
	scale = Point2(0.5f, 0.5f);
	position = Point2(400, 500);
	speed = 50;
}

Platform::~Platform()
{

}
void Platform::update(float deltaTime)
{
	position.y += speed * deltaTime;
}