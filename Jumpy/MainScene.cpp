#include "MainScene.h"

MainScene::MainScene() : Scene() {
	
	player = new Player();
	this->addChild(player);
	player->position.x = 500;
	player->position.y = 500;
	player->rotation.x = 180;
}
MainScene::~MainScene() {
	this->removeChild(player);
	delete player;
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
	if (player->isGrounded && input()->getKeyDown(KeyCode::Space))
	{
		player->velocity += player->acceleration * deltaTime;
	}
}