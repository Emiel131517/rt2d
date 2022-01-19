#include "Player.h"

Player::Player() : GameEntity()
{
	width = 64;
	height = 128;
	moveSpeed = 600;

	minJumpForce = -600;
	maxJumpForce = -1000;
	jumpForce = minJumpForce;

	isGrounded = false;
	isJumping = false;

	gravity = 1500;
	velocityY = 0;

	score = 0;

	this->addSprite("Assets/Player.tga");
}
void Player::update(float deltaTime)
{
	jumpCharge = ((jumpForce - minJumpForce) / (maxJumpForce - minJumpForce)) * 100;
	std::cout << jumpCharge << std::endl;
	UseMovement(deltaTime);
	UsePhysics(deltaTime);
}
void Player::UseMovement(float deltaTime)
{
	//move right
	if (input()->getKey(KeyCode::D))
	{
		position.x += moveSpeed * deltaTime;
	}
	//move left
	if (input()->getKey(KeyCode::A))
	{
		position.x -= moveSpeed * deltaTime;
	}
	if (isGrounded && input()->getKey(KeyCode::Space))
	{
		jumpForce -= 650 * deltaTime;
		if (jumpForce < maxJumpForce)
		{
			jumpForce = maxJumpForce;
		}
	}
	if (isGrounded)
	{
		if (input()->getKeyUp(KeyCode::Space))
		{
			velocityY = jumpForce;
			jumpForce = minJumpForce;
		}
	}
	else
	{
		jumpForce = minJumpForce;
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