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
	//std::cout << player->velocity << std::endl;
	player->velocity += player->gravity * deltaTime;
	player->position += player->velocity;
	if (player->velocity.y > 0.4)
	{
		player->velocity.y = 0.4;
	}
	if (player->velocity.y < -2)
	{
		player->velocity.y = -2;
	}
	//##Borders##
	if (player->position.x < 35) 
	{
		player->position.x = 35;
	}
	if (player->position.x > 1245) 
	{
		player->position.x = 1245;
	}
	if (player->position.y < 40)
	{
		player->position.y = 40;
	}
	if (player->position.y > 700)
	{
		this->stop();
	}
	//##collision##//
	if (Collider::SquareIsColliding(platform, player) && player->velocity.y > 0)
	{
		player->position.y = platform->position.y;
	}
	//##Inputs##//
	//quit game
	if (input()->getKey(KeyCode::Escape)) 
	{
		this->stop();
	}
	//move right
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
		player->velocity += player->acceleration * deltaTime;
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