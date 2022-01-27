#include "HudContainer.h"

HudContainer::HudContainer() : Entity()
{
	scoreText = new Text();
	jumpText = new Text();
	highScoreText = new Text();
	jumpBarFill = new JumpBarFill();
	jumpBarBorder = new JumpBarBorder();

	this->addChild(scoreText);
	this->addChild(jumpText);
	this->addChild(highScoreText);
	this->addChild(jumpBarFill);
	this->addChild(jumpBarBorder);

	jumpBarFill->position = Point2(SWIDTH / 2 - jumpBarFill->width / 2, SHEIGHT - jumpBarFill->height);
	jumpBarBorder->position = Point2(SWIDTH / 2, SHEIGHT - jumpBarBorder->height / 2);
}
void HudContainer::update(float deltaTime)
{

}
HudContainer::~HudContainer()
{
	delete scoreText;
	delete jumpText;
	delete highScoreText;
	delete jumpBarBorder;
}
