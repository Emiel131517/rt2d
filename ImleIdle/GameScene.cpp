#include "GameScene.h"

GameScene::GameScene() : Scene()
{
	//for (int i = 0; i < 5; i++)
	//{
	//	LayerEntity* layer = new LayerEntity();
	//	layers.push_back(layer);
	//	this->addChild(layer);
	//}

	player = new Player();
	this->addChild(player);
}
void GameScene::update(float deltaTime)
{

	if (input()->getKeyDown(KeyCode::Escape))
	{
		this->stop();
	}
}
GameScene::~GameScene()
{
	delete player;
	int sizeLayers = layers.size();
	for (int i = 0; i < sizeLayers; i++)
	{
		this->removeChild(layers[i]);
		delete layers[i];
	}
}