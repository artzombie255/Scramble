#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Level
{
public:
	Level();
	Level(int);
	~Level();
	void readFromFile(std::string);
	void clearVec();
	void setEntities(std::vector<Enemy*>&);
	void loadLevel(sf::RenderWindow&, sf::View&, std::vector<Enemy*>&);
	void colorSwap(int);
	sf::Sprite getSprite();
	void setLevelArrVec(std::vector<char>[25]);
	int currentLevel();
	int getOffset();

private:
	int levelOffset, levelOn = 1, levelChangeCounter = 100;
	std::vector<char> levelArrVec[25];
	sf::Sprite levelSprite[34];
	sf::Texture levelTexture[34][7];
	sf::Clock spriteClock, levelClock;
};

