#include "Player.h"

Player::Player() : GameEntity()
{
	Sprite().pivot = Point2(1, 0);
	width = 64;
	height = 128;
	isGrounded = true;
	moveSpeed = 500;
	velocity = Vector2(0, 0);
	gravity = Vector2(0, 0);
	acceleration = Vector2(0, 0);
	position = Point2(0, -10);
	this->addSprite("Assets/Player.tga");
}

Player::~Player()
{

}

void Player::update(float deltaTime) 
{

}