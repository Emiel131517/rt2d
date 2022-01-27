#include "MainScene.h"
#include "Collider.h"

MainScene::MainScene() : Scene() {

	for (int i = 0; i < 5; i++)
	{
		LayerEntity* layer = new LayerEntity();
		layers.push_back(layer);
		this->addChild(layer);
	}

	CreateBackground(0, 0);
	CreateBackground(0, -SHEIGHT);

	player = new Player();
	hudContainer = new HudContainer();

	layers[1]->addChild(player);
	layers[4]->addChild(hudContainer);

	GameData::ReadData(player);
	platformTimer.start();
	deathballTimer.start();
	srand(time(NULL));

	SpawnPlatform(SWIDTH / 2, SHEIGHT / 2);
	SpawnPlatform(SWIDTH / 3, SHEIGHT / 4);
	SpawnPlatform(SWIDTH / 2, SHEIGHT / 100);
}
void MainScene::update(float deltaTime) 
{	
	//##SpawnPlatforms##//
	SpawnPlatformRandomLoc();
	//##SpawnDeathballs##//
	SpawnDeathballRandomLoc();
	//##Colliding##//
	UseColliders();
	//##Text##//
	UseScreenBorders();
	//##Movement##//
	UseText();
	hudContainer->jumpBarFill->widthScale = player->jumpCharge; 
	//quit game
	if (input()->getKey(KeyCode::Escape))
	{
		SaveAndQuit();
	}
}
//########################################
//creates a background
//########################################
void MainScene::CreateBackground(int Xposition, int Yposition)
{
	Background* background = new Background();
	background->position = Point2(Xposition, Yposition);
	backgrounds.push_back(background);
	layers[0]->addChild(background);
}
//########################################
//spawns one platform
//########################################
void MainScene::SpawnPlatform(int Xposition, int Yposition)
{
	Platform* platform = new Platform();
	platform->position = Point2(Xposition, Yposition);
	platforms.push_back(platform);
	layers[2]->addChild(platform);
}
//########################################
//spawns one platform at a random x pos
//########################################
void MainScene::SpawnPlatformRandomLoc()
{
	int max = SWIDTH - 128;
	int min = 0 + 128;
	random = rand() % (max - min) + min;
	if (platformTimer.seconds() >= 2)
	{
		SpawnPlatform(random, 0);
		platformTimer.start();
	}
}
//########################################
//spawns one deathball
//########################################
void MainScene::SpawnDeathball(int Xposition, int Yposition)
{
	DeathBall* deathBall = new DeathBall();
	deathBall->position = Point2(Xposition, Yposition);
	deathBalls.push_back(deathBall);
	layers[3]->addChild(deathBall);
}
//########################################
//spawns one deathball at a random x pos
//########################################
void MainScene::SpawnDeathballRandomLoc()
{
	int max = SWIDTH - 128;
	int min = 0 + 128;
	random = rand() % (max - min) + min;
	if (deathballTimer.seconds() >= 2.5f)
	{
		SpawnDeathball(random, -64);
		deathballTimer.start();
	}
}
//########################################
//checks if entities are colliding
//########################################
void MainScene::UseColliders()
{
	player->isGrounded = false;
	int sizePlatform = platforms.size();
	for (int i = 0; i < sizePlatform; i++)
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
	int sizeDeathball = deathBalls.size();
	for (int i = 0; i < sizeDeathball; i++)
	{
		if (Collider::SquareIsColliding(deathBalls[i], player))
		{
			SaveAndQuit();
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
	hudContainer->highScoreText->position = Point2(20, 75);
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
	int sizeDeathballs = deathBalls.size();
	for (int i = 0; i < sizeDeathballs; i++)
	{
		this->removeChild(deathBalls[i]);
		delete deathBalls[i];
	}
	int sizeLayers = layers.size();
	for (int i = 0; i < sizeLayers; i++)
	{
		this->removeChild(layers[i]);
		delete layers[i];
	}
}