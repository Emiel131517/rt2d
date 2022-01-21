#include "HudContainer.h"

HudContainer::HudContainer() : Entity()
{
	scoreText = new Text();
	jumpText = new Text();
	highScoreText = new Text();

	this->addChild(scoreText);
	this->addChild(jumpText);
	this->addChild(highScoreText);
}
void HudContainer::update(float deltaTime)
{

}
HudContainer::~HudContainer()
{
	delete scoreText;
	delete jumpText;
	delete highScoreText;
}
