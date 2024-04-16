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
	Level(int);
	~Level();
	void readFromFile(std::string);
	void loadLevel(sf::RenderWindow&, sf::View&);
	void colorSwap(int);
	bool checkCollision(Player);
	sf::Sprite getSprite();
	void setLevelArrVec(std::vector<char>[25]);
	int currentLevel(sf::View&);
	int getOffset();

private:
	int levelOffset;
	std::vector<char> levelArrVec[25];
	sf::Sprite levelSprite[33];
	sf::Texture levelTexture[33][7];
	sf::Clock spriteClock, levelClock;
};

