#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Level
{
public:
	Level();
	Level(int);
	~Level();
	void readFromFile(std::string);
	void setEntities(std::vector<Enemy*>&);
	void loadLevel(sf::RenderWindow&, sf::View&, std::vector<Enemy*>&);
	void colorSwap(int);
	bool checkCollision(Player);
	sf::Sprite getSprite();
	void setLevelArrVec(std::vector<char>[25]);
	int currentLevel(sf::View&);
	int getOffset();

private:
	int levelOffset;
	std::vector<char> levelArrVec[25];
	sf::Sprite levelSprite[34];
	sf::Texture levelTexture[34][7];
	sf::Clock spriteClock, levelClock;
};

