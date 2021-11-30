#include "MainScene.h"

MainScene::MainScene() : Scene() {
	
	player = new Player();
	this->addChild(player);
	player->position.x = 500;
	player->position.y = 500;
	player->rotation.x = 180;
	player->scale = Point(2, 2);
}
MainScene::~MainScene() {
	this->removeChild(player);
	delete player;
}
void MainScene::update(float deltaTime) {
	if (input()->getKey(KeyCode::Escape)) {
		this->stop();
	}
}