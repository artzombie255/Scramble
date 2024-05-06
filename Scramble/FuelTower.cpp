#include "FuelTower.h"


FuelTower::FuelTower()
{
	setSize(sf::Vector2f(48, 48));
	setOrigin(0, 0);
	setPosition((rand() % 2000 + 300), 500);
	name = "FuelTower.png";
}


FuelTower::FuelTower(int x, int y)
{
	setSize(sf::Vector2f(48, 48));
	setOrigin(0, 0);
	setPosition(x, y);
	name = "FuelTower.png";
}


FuelTower::~FuelTower()
{

}


int FuelTower::getFuel()
{
	return housedFuel;
}


void FuelTower::print(sf::RenderWindow& window)
{
	sprite.setPosition(getPosition().x, getPosition().y);
	//window.draw(*this);
	window.draw(sprite);
}


void FuelTower::changeSprite(int palette)
{
	Enemy::changeSprite(palette);
}


int FuelTower::getPoints()
{
	return 150;
}
