#include "Player.h"

Player::Player() : GameEntity()
{
	width = 64;
	height = 128;
	moveSpeed = 500;

	isGrounded = false;
	isJumping = false;

	gravity = 0.4f;
	velocityY = 0;
	velocityX = 0;

	this->addSprite("Assets/Player.tga");
}

Player::~Player()
{

}

void Player::update(float deltaTime) 
{

}