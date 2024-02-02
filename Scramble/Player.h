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
	int getUsableMissiles();
	int getUsableShots();
	void shootMissiles();
	void shootBlaster();
	void addPoints(int);
	void crash(Enemy);
	void hit(Enemy);
	void moveCheck();
	void move();

private:
	int usableMissiles = 2, usableShots = 4, lives = 3, points = 0, fuelUseSpeed = 10, fuel = 128, yMove = 0, xMove = 0;
};

