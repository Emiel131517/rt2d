#include "MainScene.h"
#include "Collider.h"

MainScene::MainScene() : Scene() {

	CreateBackground(0, 0);
	CreateBackground(0, -SHEIGHT);
	
	hudContainer = new HudContainer();
	player = new Player();

	this->addChild(player);
	this->addChild(hudContainer);

	GameData::ReadData(player);
	timer.start();
	srand(time(NULL));

	SpawnPlatform(SWIDTH / 2, SHEIGHT / 2);
	SpawnPlatform(SWIDTH / 3, SHEIGHT / 4);
	SpawnPlatform(SWIDTH / 2, SHEIGHT / 100);

	player->position = Point2(SWIDTH / 2, SHEIGHT / 2 - player->height);
}
void MainScene::update(float deltaTime) 
{	
	//##SpawnPlatforms##//
	UseRandomPlatformSpawn();
	//##Colliding##//
	UseColliders();
	//##Text##//
	UseScreenBorders();
	//##Movement##//
	UseText();
	//quit game
	if (input()->getKey(KeyCode::Escape))
	{
		SaveAndQuit();
	}
}
//creates a background
void MainScene::CreateBackground(int Xposition, int Yposition)
{
	Background* background = new Background();
	background->position = Point2(Xposition, Yposition);
	backgrounds.push_back(background);
	this->addChild(background);
}
//spawns a platform
void MainScene::SpawnPlatform(int Xposition, int Yposition)
{
	Platform* platform = new Platform();
	platform->position = Point2(Xposition, Yposition);
	platforms.push_back(platform);
	this->addChild(platform);
}
//spawns a platform at a random location between the screen borders
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
//checks collision
void MainScene::UseColliders()
{
	player->isGrounded = false;
	int size = platforms.size();
	for (int i = 0; i < size; i++)
	{
		if (Collider::SquareIsColliding(platforms[i], player) && player->velocityY > 0 && player->position.y < platforms[i]->position.y - player->height / 2)
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
//make the borders of the screen impassable except top border
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
		SaveAndQuit();
	}
}
void MainScene::UseText()
{
	//jump text
	std::string jumpT = "Jump charge:";
	jumpT += std::to_string((int)player->jumpCharge);
	jumpT += std::string("%");
	hudContainer->jumpText->message(jumpT);
	hudContainer->jumpText->scale = Point2(0.45f, 0.45f);
	hudContainer->jumpText->position = Point2(20, 75);

	//score text
	std::string scoreT = "Score: ";
	scoreT += std::to_string(player->score);
	hudContainer->scoreText->message(scoreT);
	hudContainer->scoreText->position = Point2(25, 25);

	//High score text
	std::string highScoreT = "High score: ";
	highScoreT += std::to_string(player->highScore);
	hudContainer->highScoreText->message(highScoreT);
	hudContainer->highScoreText->scale = Point2(0.45f, 0.45f);
	hudContainer->highScoreText->position = Point2(20, 100);
}
void MainScene::SaveAndQuit()
{
	if (player->score >= player->highScore)
	{
		GameData::WriteData(player);
	}
	this->stop();
}
//destructor
MainScene::~MainScene() {
	this->removeChild(player);
	this->removeChild(hudContainer);
	delete player;
	delete hudContainer;
	int sizePlatforms = platforms.size();
	for (int i = 0; i < sizePlatforms; i++)
	{
		this->removeChild(platforms[i]);
		delete platforms[i];
	}
	int sizeBackgrounds = backgrounds.size();
	for (int i = 0; i < sizeBackgrounds; i++)
	{
		this->removeChild(backgrounds[i]);
		delete backgrounds[i];
	}
}