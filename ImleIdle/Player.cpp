#include "Player.h"

Player::Player() : GameEntity()
{
	level = 0;
	xp = 0;
	xpNeed = 100;
	money = 0;
}
void Player::update(float deltaTime)
{
	if (xp > xpNeed)
	{
		xp = xpNeed;
	}
	if (input()->getKeyDown(KeyCode::L))
	{
		LevelUp();
	}
	if (input()->getKeyDown(KeyCode::S))
	{
		BuySmelter();
	}
	std::cout << money << std::endl;
}
void Player::LevelUp()
{
	level++;
	xp = 0;
	xpNeed += xpNeed / 10;
	std::cout << level << std::endl;
	std::cout << xpNeed << std::endl;
}
void Player::BuySmelter()
{
	Smelter* smelter = new Smelter();
	smelters.push_back(smelter);
	this->addChild(smelter);
}
Player::~Player()
{
	int sizeSmelters = smelters.size();
	for (int i = 0; i < sizeSmelters; i++)
	{
		this->removeChild(smelters[i]);
		delete smelters[i];
	}
}