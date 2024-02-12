#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Player.h"

class Level
{
public:
	Level();
	~Level();
	void loadFromFile(std::ifstream, std::string);
	void loadLevel();
	bool checkCollision(Player);
private:
	std::vector<char> levelArrVec[25];
};

