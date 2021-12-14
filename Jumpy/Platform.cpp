#include "Platform.h"

Platform::Platform() : GameEntity()
{
	Sprite().pivot = Point2(0, 0);
	width = 256;
	height = 32;
	speed = 50;
	position = Point2(100, 300);
	this->addSprite("Assets/Platform.tga");
}

Platform::~Platform()
{

}
void Platform::update(float deltaTime)
{
	int x = 0;
	//position.y += speed * deltaTime;
}