#include "Background.h"

Background::Background() : Entity()
{
	this->addSprite("Assets/Background.tga", 0, 0);
	this->sprite()->size = Point2(SWIDTH, SHEIGHT);
}
void Background::update(float deltaTime)
{

}
Background::~Background()
{

}