#include "Player.h"
#include <iostream>
#include "Enemy.h"
#include <vector>


Player::Player()
{
	setSize(sf::Vector2f(57, 33));
	setOrigin(0, 0);
	setPosition(400, 200);
}


Player::~Player()
{

}


//checks if the key is pressed and there are available missiles then shoots them
void Player::shootMissiles(sf::RectangleShape missile[])
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && mTimer > 3)
	{
		if (usableMissiles[0] == true)
		{
			missile[0].setPosition(getPosition().x + 57, getPosition().y + 20);
			usableMissiles[0] = false;
			//std::cout << "1";
			mxMove[0] = 5;
			mTimer = 0;
		}
		else if (usableMissiles[1] == true)
		{
			missile[1].setPosition(getPosition().x + 57, getPosition().y + 20);
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
			bullet[TOTAL_BULLETS - 4].setPosition
			(getPosition().x + 57, getPosition().y + 20);
			usableShots[TOTAL_BULLETS - 4] = false;
			//std::cout << "1";
			sTimer = 0;
		}
		else if (usableShots[TOTAL_BULLETS - 3] == true)
		{
			bullet[TOTAL_BULLETS - 3].setPosition
			(getPosition().x + 57, getPosition().y + 20);
			usableShots[TOTAL_BULLETS - 3] = false;
			//std::cout << "2";
			sTimer = 0;
		}
		else if (usableShots[TOTAL_BULLETS - 2] == true)
		{
			bullet[TOTAL_BULLETS - 2].setPosition
			(getPosition().x + 57, getPosition().y + 20);
			usableShots[TOTAL_BULLETS - 2] = false;
			//std::cout << "3";
			sTimer = 0;
		}
		else if (usableShots[TOTAL_BULLETS - 1] == true)
		{
			bullet[TOTAL_BULLETS - 1].setPosition
			(getPosition().x + 57, getPosition().y + 20);
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
	sf::FloatRect nextPos;
	sf::FloatRect playerBounds = getGlobalBounds();

	//makes a float rect that has where the player will move to next
	nextPos = playerBounds;
	nextPos.left += xMove;
	nextPos.top += yMove;

	for (int i = 0; i < enemyVec.size(); i++)
	{
		sf::FloatRect enemyBounds = enemyVec.at(i)->getGlobalBounds();

		//compares player and enemies
		if (enemyBounds.intersects(nextPos))
		{
			std::cout << "hit";
			lives--;
			if (lives == 0);
			//play end animation
			else
			{
				//setPosition(-100, -100);

			}
			//respawn
		}
	}
}


void Player::crash(std::vector<char> levelArrVec[25], sf::Sprite sprite, int levelOffset)
{
	sf::FloatRect nextPos;
	sf::FloatRect playerBounds = getGlobalBounds();
	int offset;

	//makes a float rect that has where the player will move to next
	nextPos = playerBounds;
	nextPos.left += xMove;
	nextPos.top += yMove;

	for (int j = 0; j < 25; j++)
	{
		for (int i = 0; i < levelArrVec[0].size(); i++)
		{
			// Verifies within acceptable ASCII ranges
			// 48-57 for 0-9 | 97-119 for a-w
			if ((levelArrVec[j][i] >= 48 && levelArrVec[j][i] <= 57) || 
				(levelArrVec[j][i] >= 97 && levelArrVec[j][i] <= 119))
			{
				if (levelArrVec[j][i] >= 48 && levelArrVec[j][i] <= 57)
					offset = 48;
				else
					offset = 87;
				sprite.setPosition((i + levelOffset) * 24, 96 + (j * 24));
			}
			else if (levelArrVec[j][i] == 120 || levelArrVec[j][i] == 121)
			{
				//std::cout << "ignore";
			}
			else
			{
				//std::cout << static_cast<int>(levelArrVec[j][i]) << " I: " << i << " J: " << j;
				//throw std::runtime_error("INVALID LEVEL ENTRY");
			}

			sf::FloatRect wallBounds = sprite.getGlobalBounds();

			//compares player and walls
			if (wallBounds.intersects(nextPos))
			{
				std::cout << "collide";
				lives--;
				if (lives == 0);
				//play end animation
				else;
				//respawn
			}
		}
	}
}


//detects when an enemy is hit and manages it
void Player::hit(std::vector<Enemy*> enemyVec, 
	sf::RectangleShape bullet[], sf::RectangleShape missile[])
{
	bool hit = false;
	sf::FloatRect nextPos;

	for (int j = 0; j < enemyVec.size(); j++)
	{
		sf::FloatRect enemyBounds = enemyVec.at(j)->getGlobalBounds();
		for (int i = 0; i < TOTAL_BULLETS; i++)
		{
			sf::FloatRect bulletBounds = bullet[i].getGlobalBounds();
			nextPos = bulletBounds;

			if (enemyBounds.intersects(nextPos))
			{
				hit = true;
				bullet[i].setPosition(-100, -100);
				usableShots[i] = true;
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
		for (int i = 0; i < 2; i++)
		{
			sf::FloatRect missileBounds = missile[i].getGlobalBounds();
			nextPos = missileBounds;
			nextPos.left += mxMove[i];
			nextPos.top += myMove[i];

			if (enemyBounds.intersects(nextPos))
			{
				hit = true;
				missile[i].setPosition(-100, 900);
				usableMissiles[i] = true;
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
	}




	for (int j = 0; j < enemyVec.size(); j++)
	{
		sf::FloatRect enemyBounds = enemyVec.at(j)->getGlobalBounds();
		for (int i = 0; i < TOTAL_BULLETS; i++)
		{
			sf::FloatRect bulletBounds = bullet[i].getGlobalBounds();
			nextPos = bulletBounds;

			if (enemyBounds.intersects(nextPos))
			{
				hit = true;
				bullet[i].setPosition(-100, -100);
				usableShots[i] = true;
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
		for (int i = 0; i < 2; i++)
		{
			sf::FloatRect missileBounds = missile[i].getGlobalBounds();
			nextPos = missileBounds;
			nextPos.left += mxMove[i];
			nextPos.top += myMove[i];

			if (enemyBounds.intersects(nextPos))
			{
				hit = true;
				missile[i].setPosition(-100, 900);
				usableMissiles[i] = true;
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
		xMove = -1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
		xMove = 7;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
		yMove = -4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
		yMove = 4;
    }


    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) 
		&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
    	xMove = 3;
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) 
		&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
		yMove = 0;
    }

}


//moves player based on pressed keys
void Player::move(sf::RectangleShape bullet[], 
	sf::RectangleShape missile[], sf::View viewPort)
{
	//getPosition().x + 100, getPosition().y + 20;
	if (fuel > 0)
		RectangleShape::move(xMove, yMove);
	else 
		RectangleShape::move(3, 3);
	if (getPosition().x <= viewPort.getCenter().x - 326 || getPosition().y <= 106 
		|| getPosition().x >= viewPort.getCenter().x - 50 || getPosition().y >= 718)
	{
		if (getPosition().x <= viewPort.getCenter().x - 326)
			RectangleShape::setPosition(viewPort.getCenter().x - 326, getPosition().y);
		if (getPosition().y <= 106)
			RectangleShape::setPosition(getPosition().x, 106);
		if (getPosition().x >= viewPort.getCenter().x - 50)
			RectangleShape::setPosition(viewPort.getCenter().x - 50, getPosition().y);
		if (getPosition().y >= 718)
			RectangleShape::setPosition(getPosition().x, 718);
	}
	for (int i = 0; i < TOTAL_BULLETS; i++)
	{
		if (bullet[i].getPosition().x > viewPort.getCenter().x + 336)
		{ 
			usableShots[i] = true;
			bullet[i].setPosition(-100, -100);
		}
		else 
			bullet[i].RectangleShape::move(13, 0);
	}
	for (int i = 0; i < 2; i++)
	{
		if (mxMove[i] > 3)
			mxMove[i]--;
		if (myMove[i] < 3)
			myMove[i]++;
		if (missile[i].getPosition().y > 672)
		{
			usableMissiles[i] = true;
			missile[i].setPosition(-100, 1000);
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


void Player::fuelLoss(sf::Clock& clock, 
	sf::RenderWindow& window, sf::View viewPort)
{
	int fuelBar = 0;
	sf::Texture fuelTexture;
	sf::Sprite fuelSprite;
	fuelTexture.loadFromFile("./sprites/fuel8.png");
	fuelSprite.setTexture(fuelTexture);
	fuelSprite.setScale(3, 3);

	if (clock.getElapsedTime().asMilliseconds() >= 1000/(60/fuelUseSpeed))
	{
		clock.restart();
		//fuel--;
		//std::cout << fuel << std::endl;
	}

	for (int i = 0; i < fuel / 8; i++)
	{
		fuelSprite.setPosition(viewPort.getCenter().x - 136 + (i * 24), 768);
		window.draw(fuelSprite);
		fuelBar++;
	}

	if (fuelBar != 16 && fuel > 0)
	{
		switch (fuel % 8)
		{
		case 7:
			fuelTexture.loadFromFile("./sprites/fuel7.png");
			break;
		case 6:
			fuelTexture.loadFromFile("./sprites/fuel6.png");
			break;
		case 5:
			fuelTexture.loadFromFile("./sprites/fuel5.png");
			break;
		case 4:
			fuelTexture.loadFromFile("./sprites/fuel4.png");
			break;
		case 3:
			fuelTexture.loadFromFile("./sprites/fuel3.png");
			break;
		case 2:
			fuelTexture.loadFromFile("./sprites/fuel2.png");
			break;
		case 1:
			fuelTexture.loadFromFile("./sprites/fuel1.png");
			break;
		case 0:
			fuelTexture.loadFromFile("./sprites/fuel0.png");
		}

		fuelSprite.setTexture(fuelTexture);
		fuelSprite.setPosition(viewPort.getCenter().x - 136 + (fuel / 8 * 24), 768);
		window.draw(fuelSprite);
		fuelBar++;
	}


	for (int i = 1; i < 17 - fuelBar; i++)
	{
		fuelTexture.loadFromFile("./sprites/fuel0.png");
		fuelSprite.setTexture(fuelTexture);
		if (fuel > 0)
			fuelSprite.setPosition
			(viewPort.getCenter().x - 136 + (((fuel / 8) + i) * 24), 768);
		else 
			fuelSprite.setPosition(viewPort.getCenter().x - 136 + ((i - 1) * 24), 768);
		window.draw(fuelSprite);
	}

}


void Player::addFuel(int tempFuel)
{
	fuel += tempFuel;
	if (fuel > 128)
		fuel = 128;
	return;
}
