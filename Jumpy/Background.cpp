#include "Background.h"

Background::Background() : Entity()
{
	speed = 25;

	this->addSprite("Assets/Background.tga", 0, 0);
	this->sprite()->size = Point2(SWIDTH, SHEIGHT);
}
void Background::update(float deltaTime)
{
	if (position.y > SHEIGHT)
	{
		position.y = -SHEIGHT;
	}
	position.y += speed * deltaTime;
}
Background::~Background()
{

}