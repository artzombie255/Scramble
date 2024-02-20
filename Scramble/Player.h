#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Enemy.h"
#include "Entity.h"

class Player: public Entity
{
public:
	Player();
	~Player();
	//int getUsableMissiles();
	//int getUsableShots();
	void shootMissiles(sf::RectangleShape[]);
	void shootBlaster(sf::RectangleShape[]);
	void addPoints(int);
	void crash(std::vector<Enemy*>);
	void hit(std::vector<Enemy*>, sf::RectangleShape[], sf::RectangleShape[]);
	void moveCheck();
	void move(sf::RectangleShape[], sf::RectangleShape[]);
	void changeSprite(sf::Clock&, sf::Sprite&);

private:
	bool usableMissiles[2] = { 1, 1 }, usableShots[4] = { 1, 1, 1, 1 };
	int lives = 3, points = 0, fuelUseSpeed = 10, fuel = 128, yMove = 0, xMove = 0, sTimer = 0, mTimer = 0, mxMove[2] = {}, myMove[2] = {}, spriteNum = 0;
	sf::Texture image; 
};

