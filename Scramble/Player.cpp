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


/*returns missiles available
int Player::getUsableMissiles()
{
	return usableMissiles&;
}


//returns shots available
int Player::getUsableShots()
{
	//return usableShots;
}
*/


void Player::shootMissiles(sf::RectangleShape missile[])
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && mTimer > 3)
	{
		if (usableMissiles[0] == true)
		{
			missile[0].setPosition(getPosition().x + 90, getPosition().y + 20);
			usableMissiles[0] = false;
			//std::cout << "1";
			mxMove[0] = 5;
			mTimer = 0;
		}
		else if (usableMissiles[1] == true)
		{
			missile[1].setPosition(getPosition().x + 90, getPosition().y + 20);
			usableMissiles[1] = false;
			//std::cout << "2";
			mxMove[1] = 5;
			mTimer = 0;
		}
	}
}


void Player::shootBlaster(sf::RectangleShape bullet[])
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && sTimer > 5)
	{
		if (usableShots[0] == true)
		{
			bullet[0].setPosition(getPosition().x + 90, getPosition().y + 20);
			usableShots[0] = false;
			//std::cout << "1";
			sTimer = 0;
		}
		else if (usableShots[1] == true)
		{
			bullet[1].setPosition(getPosition().x + 90, getPosition().y + 20);
			usableShots[1] = false;
			//std::cout << "2";
			sTimer = 0;
		}
		else if (usableShots[2] == true)
		{
			bullet[2].setPosition(getPosition().x + 90, getPosition().y + 20);
			usableShots[2] = false;
			//std::cout << "3";
			sTimer = 0;
		}
		else if (usableShots[3] == true)
		{
			bullet[3].setPosition(getPosition().x + 90, getPosition().y + 20);
			usableShots[3] = false;
			//std::cout << "4";
			sTimer = 0;
		}
	}
}


void Player::addPoints(int tempPoints)
{
	points += tempPoints;
	return;
}


void Player::crash(std::vector<Enemy*> enemyVec)
{

}

void Player::hit(std::vector<Enemy*> enemyVec, sf::RectangleShape bullet[], sf::RectangleShape missile[])
{
	bool hit = false;

	for (int j = 0; j < enemyVec.size(); j++)
	{
		for (int i = 0; i < 4; i++)
			if (bullet[i].getPosition().y >= enemyVec.at(j)->getPosition().y &&
				bullet[i].getPosition().y <= enemyVec.at(j)->getPosition().y + 50 &&
				bullet[i].getPosition().x >= enemyVec.at(j)->getPosition().x &&
				bullet[i].getPosition().x <= enemyVec.at(j)->getPosition().x + 30)
			{
				hit = true;
				bullet[i].setPosition(900, 600);
			}
		for (int i = 0; i < 2; i++)
			if (missile[i].getPosition().y >= enemyVec.at(j)->getPosition().y &&
				missile[i].getPosition().y <= enemyVec.at(j)->getPosition().y + 50 &&
				missile[i].getPosition().x >= enemyVec.at(j)->getPosition().x &&
				missile[i].getPosition().x <= enemyVec.at(j)->getPosition().x + 30)
			{
				hit = true;
			}
		if (hit == true)
		{
			addPoints(enemyVec.at(j)->getPoints());
			enemyVec.at(j)->setPosition(-100, -100);
			//delete enemyVec.at(i);
			std::cout << points;
		}
		hit = false;
	}
}


void Player::moveCheck()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
		xMove = -3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
		xMove = 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
		yMove = -3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
		yMove = 3;
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


void Player::move(sf::RectangleShape bullet[], sf::RectangleShape missile[])
{
	//getPosition().x + 100, getPosition().y + 20;
	RectangleShape::move(xMove, yMove);
	if (getPosition().x <= 10 || getPosition().y <= 10 || getPosition().x >= 290 || getPosition().y >= 550)
	{
		if (getPosition().x <= 10)
			RectangleShape::setPosition(10, getPosition().y);
		if (getPosition().y <= 10)
			RectangleShape::setPosition(getPosition().x, 10);
		if (getPosition().x >= 290)
			RectangleShape::setPosition(290, getPosition().y);
		if (getPosition().y >= 550)
			RectangleShape::setPosition(getPosition().x, 550);
	}
	for (int i = 0; i < 4; i++)
	{
		bullet[i].RectangleShape::move(10, 0);
		if (bullet[i].getPosition().x > 800)
			usableShots[i] = true;
	}
	for (int i = 0; i < 2; i++)
	{
		missile[i].RectangleShape::move(mxMove[i], myMove[i]);
		if (mxMove[i] > 0)
			mxMove[i]--;
		if (myMove[i] < 5)
			myMove[i]++;
		if (missile[i].getPosition().y > 600)
			usableMissiles[i] = true;
	}
	sTimer++;
	mTimer++;
	
}
