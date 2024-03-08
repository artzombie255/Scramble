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


//checks if the key is pressed and there are available missiles then shoots them
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


//checks if the key is pressed and there are available bullet then shoots them
void Player::shootBlaster(sf::RectangleShape bullet[])
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && sTimer > 5)
	{
		if (usableShots[TOTAL_BULLETS - 4] == true)
		{
			bullet[TOTAL_BULLETS - 4].setPosition(getPosition().x + 90, getPosition().y + 20);
			usableShots[TOTAL_BULLETS - 4] = false;
			//std::cout << "1";
			sTimer = 0;
		}
		else if (usableShots[TOTAL_BULLETS - 3] == true)
		{
			bullet[TOTAL_BULLETS - 3].setPosition(getPosition().x + 90, getPosition().y + 20);
			usableShots[TOTAL_BULLETS - 3] = false;
			//std::cout << "2";
			sTimer = 0;
		}
		else if (usableShots[TOTAL_BULLETS - 2] == true)
		{
			bullet[TOTAL_BULLETS - 2].setPosition(getPosition().x + 90, getPosition().y + 20);
			usableShots[TOTAL_BULLETS - 2] = false;
			//std::cout << "3";
			sTimer = 0;
		}
		else if (usableShots[TOTAL_BULLETS - 1] == true)
		{
			bullet[TOTAL_BULLETS - 1].setPosition(getPosition().x + 90, getPosition().y + 20);
			usableShots[TOTAL_BULLETS - 1] = false;
			//std::cout << "4";
			sTimer = 0;
		}
	}
}


//adds to the players points
void Player::addPoints(int tempPoints)
{
	points += tempPoints;
	return;
}


//detects when the player crashes and calls level to deal with it
void Player::crash(std::vector<Enemy*> enemyVec)
{
	for (int i = 0; i < enemyVec.size(); i++)
	{
		if (getPosition().y <= enemyVec.at(i)->getPosition().y + enemyVec.at(i)->getSize().y &&
			getPosition().y + getSize().y >= enemyVec.at(i)->getPosition().y &&
			getPosition().x <= enemyVec.at(i)->getPosition().x + enemyVec.at(i)->getSize().x &&
			getPosition().x + getSize().x >= enemyVec.at(i)->getPosition().x)
		{
			lives--;
			if (lives == 0);
			//play end animation
			else;
			//respawn
		}
	}
}


//detects when an enemy is hit and manages it
void Player::hit(std::vector<Enemy*> enemyVec, sf::RectangleShape bullet[], sf::RectangleShape missile[])
{
	bool hit = false;

	for (int j = 0; j < enemyVec.size(); j++)
	{
		for (int i = 0; i < TOTAL_BULLETS; i++)
			if (bullet[i].getPosition().y >= enemyVec.at(j)->getPosition().y &&
				bullet[i].getPosition().y <= enemyVec.at(j)->getPosition().y + enemyVec.at(j)->getSize().y &&
				bullet[i].getPosition().x >= enemyVec.at(j)->getPosition().x &&
				bullet[i].getPosition().x <= enemyVec.at(j)->getPosition().x + enemyVec.at(j)->getSize().x)
			{
				hit = true;
				bullet[i].setPosition(900, 600);
			}
		for (int i = 0; i < 2; i++)
			if (missile[i].getPosition().y >= enemyVec.at(j)->getPosition().y &&
				missile[i].getPosition().y <= enemyVec.at(j)->getPosition().y + enemyVec.at(j)->getSize().y &&
				missile[i].getPosition().x >= enemyVec.at(j)->getPosition().x &&
				missile[i].getPosition().x <= enemyVec.at(j)->getPosition().x + enemyVec.at(j)->getSize().x)
			{
				hit = true;
				missile[i].setPosition(900, 700);
			}
		if (hit == true)
		{
			addPoints(enemyVec.at(j)->getPoints());
			addFuel(enemyVec.at(j)->getFuel());
			enemyVec.at(j)->setPosition(-100, -100);
			//delete enemyVec.at(j);
			//std::cout << points;
		}
		hit = false;
	}
}


//animates the explosions, what else
void Player::animateBoom(std::string name)
{

}


//checks if keys are pressed and starts movement
void Player::moveCheck()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
		xMove = -3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
		xMove = 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
		yMove = -3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
		yMove = 3;
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


//moves player based on pressed keys
void Player::move(sf::RectangleShape bullet[], sf::RectangleShape missile[])
{
	//getPosition().x + 100, getPosition().y + 20;
	RectangleShape::move(xMove, yMove);
	if (getPosition().x <= 10 || getPosition().y <= 106 || getPosition().x >= 226 || getPosition().y >= 718)
	{
		if (getPosition().x <= 10)
			RectangleShape::setPosition(10, getPosition().y);
		if (getPosition().y <= 106)
			RectangleShape::setPosition(getPosition().x, 106);
		if (getPosition().x >= 226)
			RectangleShape::setPosition(226, getPosition().y);
		if (getPosition().y >= 718)
			RectangleShape::setPosition(getPosition().x, 718);
	}
	for (int i = 0; i < TOTAL_BULLETS; i++)
	{
		if (bullet[i].getPosition().x > 800)
		{ 
			usableShots[i] = true;
			bullet[i].setPosition(1000, 1000);
		}
		else 
			bullet[i].RectangleShape::move(10, 0);
	}
	for (int i = 0; i < 2; i++)
	{
		if (mxMove[i] > 0)
			mxMove[i]--;
		if (myMove[i] < 5)
			myMove[i]++;
		if (missile[i].getPosition().y > 672)
		{
			usableMissiles[i] = true;
			missile[i].setPosition(1000, 1000);
		}
		else
			missile[i].RectangleShape::move(mxMove[i], myMove[i]);
	}
	sTimer++;
	mTimer++;
	
}


//changes sprites to animate them
void Player::changeSprite(sf::Clock& clock, sf::Sprite &playerSprite)
{
	std::string file, num;
	switch (spriteNum)
	{
	case 0:
		num = "0";
		break;
	case 1:
		num = "1";
		break;
	case 2:
		num = "2";
		break;
	case 3:
		num = "3";
		break;
	case 4:
		num = "4";
		break;
	case 5:
		num = "5";
		break;
	case 6:
		num = "6";
		break;
	case 7:
		num = "7";
		break;
	}
	if (clock.getElapsedTime().asMilliseconds() >= 100)
	{
		clock.restart();
		file = "./sprites/player" + num + ".png" ;
		image.loadFromFile(file);
		playerSprite.setTexture(image);
		playerSprite.setScale(3, 3);
		spriteNum++;
		if (spriteNum == 8)
			spriteNum = 0;
	}
}


void Player::fuelLoss(sf::Clock& clock)
{
	if (clock.getElapsedTime().asMilliseconds() >= 1000/(60/fuelUseSpeed))
	{
		clock.restart();
		fuel--;
		std::cout << fuel << std::endl;
	}
}


void Player::addFuel(int tempFuel)
{
	fuel += tempFuel;
	if (fuel > 128)
		fuel = 128;
	return;
}
