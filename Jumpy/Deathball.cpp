#include "DeathBall.h"

DeathBall::DeathBall() : GameEntity()
{
	width = 64;
	height = 64;
	moveSpeed = 150;

	velocityY = 0;
	gravity = 500;

	this->addSprite("Assets/Deathball.tga");
}
void DeathBall::update(float deltaTime)
{
	position.y += moveSpeed * deltaTime;
	UsePhysics(deltaTime);
}
void DeathBall::UsePhysics(float deltaTime)
{
	position.y += velocityY * deltaTime;
	velocityY += gravity * deltaTime;
}
DeathBall::~DeathBall()
{

}