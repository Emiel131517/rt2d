#include "PlayerData.h"

PlayerData::PlayerData()
{

}
void PlayerData::WriteData(Player* player)
{
    FILE* data;
    data = fopen("Data.save", "w");
    putc(player->highScore, data);
    fclose(data);
}
void PlayerData::ReadData(Player* player)
{
    FILE* data;
    if (data = fopen("Data.save", "r"))
    {
        player->highScore = getc(data);
        std::cout << player->highScore << std::endl;
        fclose(data);
    }
}
PlayerData::~PlayerData()
{

}