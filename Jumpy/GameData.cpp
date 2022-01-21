#include "GameData.h"

GameData::GameData()
{

}
void GameData::WriteData(Player* player)
{
    FILE* data;
    data = fopen("Data.save", "w");
    putc(player->highScore, data);
    fclose(data);
}
void GameData::ReadData(Player* player)
{
    FILE* data;
    if (data = fopen("Data.save", "r"))
    {
        player->highScore = getc(data);
        std::cout << player->highScore << std::endl;
        fclose(data);
    }
}
//std::ofstream data;
//data.open("Data.txt");
//if (data.is_open())
//{
//    data << player->highScore;
//    data.close();
//}
GameData::~GameData()
{

}