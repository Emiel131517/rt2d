#include "MainScene.h"
#include "Collider.h"

MainScene::MainScene() : Scene() {

	player = new Player();
	scoreText = new Text();
	this->addChild(player);
	this->addChild(scoreText);
	timer.start();

	srand(time(NULL));

	SpawnPlatform(SWIDTH / 2, SHEIGHT / 2);
	SpawnPlatform(SWIDTH / 3, SHEIGHT / 4);
	SpawnPlatform(SWIDTH / 2, SHEIGHT / 16);
	SpawnPlatform(SWIDTH - 128, SHEIGHT / 2);
	player->position = Point2(SWIDTH / 2, SHEIGHT / 2);
}
void MainScene::update(float deltaTime) 
{	
	std::cout << player->score << std::endl;

	//##Physics##//
	UsePhysics(deltaTime);
	//##Borders##
	UseScreenBorders();
	//##Movement##//
	UseMovement(deltaTime);
	//##SpawnPlatforms##//
	UseRandomPlatformSpawn();
	//##Colliding##//
	UseColliders();
	//##Text##//
	UseText();
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
	if (player->isGrounded == false)
	{
		player->velocityY += player->gravity;
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
		player->velocityY = -500;
	}
}
void MainScene::UseRandomPlatformSpawn()
{
	int max = SWIDTH - 128;
	int min = 0 + 128;
	random = rand() % (max - min) + min;
	if (timer.seconds() >= 2)
	{
		SpawnPlatform(random, 0);
		timer.start();
	}
}
void MainScene::UseColliders()
{
	player->isGrounded = false;
	int size = platforms.size();
	for (int i = 0; i < size; i++)
	{
		if (Collider::SquareIsColliding(platforms[i], player) && player->velocityY > 0 && player->position.y < platforms[i]->position.y - 0.5f)
		{
			player->position.y = platforms[i]->position.y - platforms[i]->height / 2 - player->height / 2;
			player->isGrounded = true;
			if (platforms[i]->giveScore == false)
			{
				player->score++;
				platforms[i]->giveScore = true;
			}
		}
	}
}
void MainScene::UseScreenBorders()
{
	if (player->position.x < 0 + player->width / 2)
	{
		player->position.x = 0 + player->width / 2;
	}
	if (player->position.x > SWIDTH - player->width / 2)
	{
		player->position.x = SWIDTH - player->width / 2;
	}
	if (player->position.y > SHEIGHT + player->height / 2)
	{
		this->stop();
	}
}
void MainScene::UseText()
{
	std::string scoreT = "Score: ";
	scoreT += std::to_string(player->score);
	scoreText->message(scoreT);
	scoreText->position = Point2(25, 25);
}
MainScene::~MainScene() {
	this->removeChild(player);
	this->removeChild(scoreText);
	delete player;
	delete scoreText;
	int size = platforms.size();
	for (int i = 0; i < size; i++)
	{
		this->removeChild(platforms[i]);
		delete platforms[i];
	}
}