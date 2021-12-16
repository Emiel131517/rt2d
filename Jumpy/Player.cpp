#include "Player.h"

Player::Player() : GameEntity()
{
	width = 64;
	height = 128;
	moveSpeed = 500;

	isGrounded = false;

	gravity = 0.75f;
	velocityX = 0;
	velocityY = 0;

	position = Point2(0, -10);

	this->addSprite("Assets/Player.tga");
}

Player::~Player()
{

}

void Player::update(float deltaTime) 
{

}