#include "Player.h"
#include <iostream>
#include "Enemy.h"


Player::Player()
{
	setSize(sf::Vector2f(100, 40));
	setOrigin(0, 0);
	setPosition(400, 200);
}


Player::~Player()
{

}


//returns missiles available
int Player::getUsableMissiles()
{
	return usableMissiles;
}


//returns shots available
int Player::getUsableShots()
{
	return usableShots;
}


void Player::shootMissiles()
{
	if (usableMissiles > 0)
	{
		usableMissiles--;
		//not done yet
	}
}


void Player::shootBlaster()
{
	if (usableShots > 0)
	{
		usableShots--;
		//not done yet
	}
}


void Player::addPoints(int tempPoints)
{

}


void Player::crash(Enemy)
{

}

void Player::hit(Enemy)
{
}


void Player::moveCheck()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
		xMove = -5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
		xMove = 5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
		yMove = -5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
		yMove = 5;
    }


	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		xMove = 0;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		yMove = 0;
	}

}


void Player::move()
{
	RectangleShape::move(xMove, yMove);
}
