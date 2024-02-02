#pragma once
#include "Enemy.h"

class Player
{
public:
	int getUsableMissiles();
	int getUsableShots();
	void shootMissiles();
	void shootBlaster();
	void addPoints(int);
	void crash(Enemy);

private:
	int usableMissiles = 2, usableShots = 4, lives = 3, points = 0, fuelUseSpeed = 10, fuel = 128;
};

