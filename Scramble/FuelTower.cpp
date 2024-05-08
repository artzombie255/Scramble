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

//returns added few for rocket after fuel tower is destrpyed
int FuelTower::getFuel()
{
	return housedFuel;
}

//pastes few tower
void FuelTower::print(sf::RenderWindow& window)
{
	sprite.setPosition(getPosition().x, getPosition().y);
	//window.draw(*this);
	window.draw(sprite);
}

//chnages color of fuel tower to fit new color palette
void FuelTower::changeSprite(int palette)
{
	Enemy::changeSprite(palette);
}

//returns amount of point added from destroying fuel tower
int FuelTower::getPoints()
{
	return 150;
}
