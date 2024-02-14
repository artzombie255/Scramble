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
	void colorSwap();
	bool checkCollision(Player);
private:
	std::vector<char> levelArrVec[25];
	Sprite levelSprite[33];
	Texture levelTexture[33][7];
};

