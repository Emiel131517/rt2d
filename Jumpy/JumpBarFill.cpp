#include "JumpBarFill.h"

JumpBarFill::JumpBarFill()
{
	this->addSprite("Assets/Jumpbarfill.tga", 0, 0);
	height = 64;
	width = 512;
	widthScale = 0;
}
void JumpBarFill::update(float deltaTime)
{
	this->scale = Point2(widthScale, 1);
}
JumpBarFill::~JumpBarFill()
{

}