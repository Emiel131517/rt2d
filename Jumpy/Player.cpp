#include "Player.h"

Player::Player() : Entity()
{
	isGrounded = true;
	moveSpeed = 500;
	velocity = Vector2(0, 0);
	gravity = Vector2(0, 0.25f);
	acceleration = Vector2(0, -250);
	position = Point2(500, 500);
	rotation.x = 180;
	this->addSprite("Assets/Player.tga");
}

Player::~Player()
{

}

void Player::update(float deltaTime) 
{

}