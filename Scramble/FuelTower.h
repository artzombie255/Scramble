#pragma once
#include "Enemy.h"


class FuelTower: public Enemy
{
public:
	FuelTower();
	~FuelTower();
	int getFuel();
	void print(sf::RenderWindow&);

private:
	int housedFuel = 24;
};

