#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "Player.h"
#include <fstream>
#include <iostream>
#include <string>

class GameData {
public:

	GameData();
	virtual ~GameData();
	static void WriteData(Player* player);
	static void ReadData(Player* player);

private:

};

#endif // !GAMEDATA_H
