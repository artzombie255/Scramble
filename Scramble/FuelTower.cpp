#include "FuelTower.h"


FuelTower::FuelTower()
{

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
	window.draw(*this);
}


void FuelTower::changeSprite(sf::Clock&, sf::Sprite&)
{
}
