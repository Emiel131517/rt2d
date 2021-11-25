#include "MainScene.h"

MainScene::MainScene() : Scene(){
	
	player = new Player();

	this->addChild(player);
}
MainScene::~MainScene() {
	Delete player;
}
void MainScene::update(float deltatime) {

}