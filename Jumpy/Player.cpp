#include "Player.h"

Player::Player() : Entity()
{
	isGrounded = true;
	moveSpeed = 500;
	velocity = Vector2(0, 0);
	gravity = Vector2(0, 0.25f);
	acceleration = Vector2(0, -250);
	this->addSprite("Assets/Playermodel.tga");
}

Player::~Player()
{

}

void Player::update(float deltaTime) 
{

}