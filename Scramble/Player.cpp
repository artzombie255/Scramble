#include "Player.h"
#include <iostream>
#include "Enemy.h"
#include <vector>


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


void Player::shootBlaster(sf::RectangleShape &bullet)
{
	if (usableShots > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		bullet.setPosition(getPosition().x + 100, getPosition().y + 20);
		usableShots--;
		//not done yet
	}
	usableShots++;
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
		xMove = -5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
		xMove = 5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
		yMove = -5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
		yMove = 5;
    }


	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		xMove = 0;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		yMove = 0;
	}

}


void Player::move(sf::RectangleShape& bullet)
{
	getPosition().x + 100, getPosition().y + 20;
	if (getPosition().x > 10 || getPosition().y > 10)
		RectangleShape::move(xMove, yMove);
	bullet.RectangleShape::move(10, 0);
}
