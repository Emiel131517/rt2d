#include "MainScene.h"
#include "Collider.h"

MainScene::MainScene() : Scene() {

	player = new Player();
	startPlatform = new Platform();
	this->addChild(startPlatform);
	this->addChild(player);
	timer.start();

	srand(time(NULL));

	player->position = Point2(SWIDTH / 2, 0);
	startPlatform->position = Point2(SWIDTH / 2, 0);
}
void MainScene::update(float deltaTime) 
{	
	std::cout << player->isGrounded << std::endl;
	random = rand() % SWIDTH;
	if (timer.seconds() >= 2)
	{
		SpawnPlatform(random, 0);
		timer.start();
	}
	//##Physics##//
	UsePhysics(deltaTime);
	//##Borders##
	UseScreenBorders();
	//##Movement##//
	UseMovement(deltaTime);
	//##Colliding##//
	UseColliders();
	//quit game
	if (input()->getKey(KeyCode::Escape))
	{
		this->stop();
	}
}
void MainScene::SpawnPlatform(int Xposition, int Yposition)
{
	Platform* platform = new Platform();
	platform->position = Point2(Xposition, Yposition);
	platforms.push_back(platform);
	this->addChild(platform);
}
void MainScene::UsePhysics(float deltaTime)
{
	player->position.x += player->velocityX * deltaTime;
	player->position.y += player->velocityY * deltaTime;
	player->velocityY += player->gravity;
	if (player->velocityY > 0)
	{
		player->isJumping = true;
	}
	else
	{
		player->isJumping = false;
	}
	if (player->isGrounded)
	{
		player->gravity = 0;
	}
	else
	{
		player->gravity = 0.4f;
	}
	if (player->isJumping == true)
	{
		player->gravity = 0.75f;
	}
	if (player->isJumping == false && player->isGrounded == false)
	{
		player->gravity = 0.4f;
	}
}
void MainScene::UseMovement(float deltaTime)
{
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
		player->velocityY = -300;
	}
}
void MainScene::UseColliders()
{
	player->isGrounded = false;
	int size = platforms.size();
	for (int i = 0; i < size; i++)
	{
		if (Collider::SquareIsColliding(platforms[i], player) && player->velocityY > 0)
		{
			player->position.y = platforms[i]->position.y - platforms[i]->height / 2 - player->height / 2;
			player->isGrounded = true;
		}
	}
	if (Collider::SquareIsColliding(startPlatform, player) && player->velocityY > 0)
	{
		player->position.y = startPlatform->position.y - startPlatform->height / 2 - player->height / 2;
		player->isGrounded = true;
	}
}
void MainScene::UseScreenBorders()
{
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
}
MainScene::~MainScene() {
	this->removeChild(player);
	this->removeChild(startPlatform);
	delete startPlatform;
	delete player;
	int size = platforms.size();
	for (int i = 0; i < size; i++)
	{
		this->removeChild(platforms[i]);
		delete platforms[i];
	}
}