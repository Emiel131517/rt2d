#include "JumpBar.h"

JumpBar::JumpBar() : GameEntity()
{
	border = new GameEntity();
	fill = new GameEntity();
	
	fill->addSprite("Assets/Jumpbarfill.tga", 0, 0);
	border->addSprite("Assets/Jumpbarborder.tga");

	this->addChild(fill);
	this->addChild(border);

	fillWidthScale = 0;

	borderHeight = 64;
	borderWidth = 512;

	fillHeight = 64;
	fillWidth = 512;

	border->position = Point2(SWIDTH / 2, SHEIGHT - borderHeight / 2);
	fill->position = Point2(SWIDTH / 2 - fillWidth / 2, SHEIGHT - fillHeight);
}
void JumpBar::update(float deltaTime)
{
	fill->scale = Point2(fillWidthScale, 1);
}
JumpBar::~JumpBar()
{
	delete border;
	delete fill;
}