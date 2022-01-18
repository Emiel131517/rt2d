#include "Player.h"

Player::Player() : GameEntity()
{
	width = 64;
	height = 128;
	moveSpeed = 600;

	isGrounded = false;
	isJumping = false;

	gravity = 1500;
	velocityY = 0;

	score = 0;

	this->addSprite("Assets/Player.tga");
}
void Player::update(float deltaTime)
{
	std::cout << velocityY << std::endl;
	UseMovement(deltaTime);
	UsePhysics(deltaTime);
}
void Player::UseMovement(float deltaTime)
{
	////move right
	if (input()->getKey(KeyCode::D))
	{
		position.x += moveSpeed * deltaTime;
	}
	//move left
	if (input()->getKey(KeyCode::A))
	{
		position.x -= moveSpeed * deltaTime;
	}
	//jump
	if (isGrounded && input()->getKeyDown(KeyCode::Space))
	{
		velocityY = -750;
	}
}
void Player::UsePhysics(float deltaTime)
{
	position.y += velocityY * deltaTime;
	if (isGrounded == false)
	{
		velocityY += gravity * deltaTime;
	}
}
Player::~Player()
{

}