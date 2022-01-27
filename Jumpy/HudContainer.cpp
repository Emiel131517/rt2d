#include "HudContainer.h"

HudContainer::HudContainer() : Entity()
{
	scoreText = new Text();
	highScoreText = new Text();
	jumpBarFill = new JumpBarFill();
	jumpBarBorder = new JumpBarBorder();

	this->addChild(scoreText);
	this->addChild(highScoreText);
	this->addChild(jumpBarFill);
	this->addChild(jumpBarBorder);

	jumpBarFill->position = Point2(SWIDTH / 2 - 512 / 2, SHEIGHT - jumpBarFill->height);
	jumpBarBorder->position = Point2(SWIDTH / 2, SHEIGHT - jumpBarBorder->height / 2);
}
void HudContainer::update(float deltaTime)
{

}
HudContainer::~HudContainer()
{
	delete scoreText;
	delete highScoreText;
	delete jumpBarBorder;
	delete jumpBarFill;
}
