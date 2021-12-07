#include "MainScene.h"

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
	player->velocity += player->gravity * deltaTime;
	player->position += player->velocity;
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