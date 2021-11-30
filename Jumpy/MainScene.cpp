#include "MainScene.h"

MainScene::MainScene() : Scene() {
	
	player = new Player();

	this->addChild(player);
}
MainScene::~MainScene() {
	this->removeChild(player);
	delete player;
}