#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Enemy.h"
#include "Entity.h"
#include "Level.h"

class Player: public Entity
{
public:
	Player();
	~Player();
	void shootMissiles(sf::RectangleShape[]);
	void shootBlaster(sf::RectangleShape[]);
	void addPoints(int);
	void setPoints(int);
	void crash(std::vector<Enemy*>&, int, Level*, sf::View&, int, int&);
	void crash(std::vector<char>[25], sf::Sprite, int, Level*, sf::View&, std::vector <Enemy*>&, int, int&);
	int hit(std::vector<Enemy*>, sf::RectangleShape[], sf::RectangleShape[]);
	void animateBoom(std::string);
	void moveCheck();
	void move(sf::RectangleShape[], sf::RectangleShape[], sf::View);
	void changeSprite(sf::Clock&, sf::Sprite&);
	void fuelLoss(sf::Clock&, sf::RenderWindow&, sf::View);
	void addFuel(int);
	int getScore();
	int getLives();

private:
	bool usableMissiles[2] = { 1, 1 }, usableShots[4] = { 1, 1, 1, 1 };
	int lives = 0, points = 0, fuelUseSpeed = 10, fuel = 128, yMove = 0, 
		xMove = 1, sTimer = 0, mTimer = 0, mxMove[2] = {}, myMove[2] = {}, 
		spriteNum = 0, boomNum = 0, tempPoints = 0;
	sf::Texture image; 
};

