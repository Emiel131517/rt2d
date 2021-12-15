#include "MainScene.h"
#include "Collider.h"

MainScene::MainScene() : Scene() {

	platform = new Platform();
	player = new Player();
	this->addChild(player);
	this->addChild(platform);
	//for (int i = 0; i < 5; i++) 
	//{
	//	Platform* platform = new Platform();
	//	platform->position.y = rand() % SWIDTH;
	//	platforms.push_back(platform);
	//	this->addChild(platform);
	//}
}
void MainScene::update(float deltaTime) 
{	
	std::cout << player->isGrounded << std::endl;
	ddClear();
	ddSquare(player->position.x - player->width/2, player->position.y - player->height/2, player->width, player->height, RED);
	ddSquare(platform->position.x - platform->width/2, platform->position.y - platform->height/2, platform->width, platform->height, RED);
	//std::cout << player->velocity << std::endl;
	player->velocity += player->gravity * deltaTime;
	player->velocity += player->acceleration * deltaTime;
	player->position += player->velocity;
	player->acceleration = Vector2(0, 0);
	if (player->isGrounded == true)
	{
		player->gravity = Vector2(0, 0);
	}
	//Physics(deltaTime);
	//##Borders##
	if (player->position.x < 35) 
	{
		player->position.x = 35;
	}
	if (player->position.x > 1245) 
	{
		player->position.x = 1245;
	}
	if (player->position.y < 50)
	{
		player->position.y = 50;
	}
	if (player->position.y > 700)
	{
		this->stop();
	}
	//##Inputs##//
	//quit game
	if (input()->getKey(KeyCode::Escape)) 
	{
		this->stop();
	}
	////move right
	if (input()->getKey(KeyCode::D))
	{
		player->position.x += player->moveSpeed * deltaTime;
	}
	//move left
	if (input()->getKey(KeyCode::A))
	{
		player->position.x -= player->moveSpeed * deltaTime;
	}
	//jump
	if (player->isGrounded && input()->getKeyDown(KeyCode::Space))
	{
		player->acceleration = Vector2(0, -250);
	}
	//##collision##//
	if (Collider::SquareIsColliding(platform, player) && player->velocity.y > 0)
	{
		player->position.y = platform->position.y - platform->height/2 - player->height/2;
		player->isGrounded = true;
	}
	else 
	{
		player->isGrounded = false;
	}
}
void MainScene::Physics(float deltaTime) 
{
	player->velocity += player->gravity * deltaTime;
	player->velocity += player->acceleration * deltaTime;
	player->position += player->velocity;
	player->acceleration = Vector2(0, 0);
	if (player->isGrounded == true)
	{
		player->gravity = Vector2(0, 0);
	}
	else
	{
		//player->gravity = Vector2(0, 0.4f);
	}
}
MainScene::~MainScene() {
	this->removeChild(player);
	this->removeChild(platform);
	delete player;
	delete platform;
	//int size = platforms.size();
	//for (int i = 0; i < size; i++)
	//{
	//	this->removeChild(platforms[i]);
	//	delete platforms[i];
	//}
}