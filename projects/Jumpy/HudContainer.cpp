#include "HudContainer.h"

HudContainer::HudContainer() : Entity()
{
	scoreText = new Text();
	highScoreText = new Text();
	jumpBar = new JumpBar();

	this->addChild(scoreText);
	this->addChild(highScoreText);
	this->addChild(jumpBar);
}
void HudContainer::update(float deltaTime)
{

}
HudContainer::~HudContainer()
{
	delete scoreText;
	delete highScoreText;
	delete jumpBar;
}
