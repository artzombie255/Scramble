#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Player.h"
#include <SFML/Graphics.hpp>

class Level
{
public:
	Level();
	~Level();
	void readFromFile(std::string);
	void loadLevel(sf::RenderWindow&);
	void colorSwap(int);
	bool checkCollision(Player);
private:
	int k = 0;
	std::vector<char> levelArrVec[28];
	sf::Sprite levelSprite[33];
	sf::Texture levelTexture[33][7];
	sf::Clock spriteClock, levelClock;
};

