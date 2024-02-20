#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::move(sf::Clock &clock)
{
	sf::RectangleShape::move(-1, 0);
	return;
}

int Enemy::getPoints()
{
	return points;
}


void Enemy::print(sf::RenderWindow& window)
{
}
