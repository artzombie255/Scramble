#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::move(sf::Clock &clock, sf::View viewport)
{
	//sf::RectangleShape::move(-1, 0);
	return;
}

//returns point total for destroying enemy
int Enemy::getPoints()
{
	return points;
}

//returns number of fuel added
int Enemy::getFuel()
{
	return 0;
}

//pastes enemy
void Enemy::print(sf::RenderWindow& window)
{
}

//color swaps enemy to palette
void Enemy::changeSprite(int palette)
{
	std::string file, color, t = "./sprites/";

	switch (palette)
	{
	case 0:
		color = "0";
		break;
	case 1:
		color = "1";
		break;
	case 2:
		color = "2";
		break;
	case 3:
		color = "3";
		break;
	case 4:
		color = "4";
		break;
	case 5:
		color = "5";
		break;
	case 6:
		color = "6";
		break;
	case 7:
		color = "7";
		break;
	}

	//spriteClock.restart();
	file = t + color + name;
	image.loadFromFile(file);
	sprite.setTexture(image);
	sprite.setScale(3, 3);

}

//returns if it is a base or not
bool Enemy::isBase()
{
	return false;
}
