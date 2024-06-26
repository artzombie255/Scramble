#include "Rockets.h"


Rockets::Rockets()
{
	setSize(sf::Vector2f(48, 48));
	setOrigin(0, 0);
	setPosition((rand() % 2000 + 300), 500);
}


Rockets::Rockets(int x, int y)
{
	setSize(sf::Vector2f(48, 48));
	setOrigin(0, 0);
	setPosition(x, y);
}


Rockets::~Rockets()
{

}

//sets rocket off from the ground
void Rockets::move(sf::Clock &clock, sf::View viewport)
{
	//sf::RectangleShape::move(-1, 0);
	if (grounded == false && destroyed == false)
		sf::RectangleShape::move(0, -2);
	if (clock.getElapsedTime().asSeconds() >= 1 
		&& getPosition().x < viewport.getCenter().x
		&& getPosition().x > viewport.getCenter().x - 370 && grounded == true)
	{
		std::cout << "takeoff";
		clock.restart();
		takeoff();
	}
	return;
}


void Rockets::takeoff()
{
	//std::cout << "sprking";
	grounded = false;
	return;
}

//returns points for rocket depending on if it is grounded or in the air
int Rockets::getPoints()
{
	if (grounded == true)
		return 50;
	else
		return 80;
}

//pastes rocket
void Rockets::print(sf::RenderWindow& window)
{
	sprite.setPosition(getPosition().x, getPosition().y);
	//window.draw(*this);
	window.draw(sprite);
}

//color swaps for rokcets to new color palette
void Rockets::changeSprite(int palette)
{
	std::string file, num, color = "0";

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
	}

	
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

	if (grounded == false && spriteClock.getElapsedTime().asMilliseconds() >= 150)
	{
		spriteClock.restart();
		spriteNum++;
		if (spriteNum == 4)
			spriteNum = 1;
	}

	file = "./sprites/" + color + "rocket" + num + ".png";

	if (destroyed == true)
	{
		file = "./sprites/" + color + "enemyBoom" + std::to_string(boomNum) + ".png";
		if (boomClock.getElapsedTime().asMilliseconds() >= 250)
		{
			boomClock.restart();
			boomNum++;
			if (boomNum == 4)
			{
				setPosition(-200, -200);
				destroyed = false;
			}
		}
	}

	image.loadFromFile(file);
	sprite.setTexture(image);
	sprite.setScale(3, 3);

}