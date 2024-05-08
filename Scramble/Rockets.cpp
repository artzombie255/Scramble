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


void Rockets::move(sf::Clock &clock, sf::View viewport)
{
	//sf::RectangleShape::move(-1, 0);
	if (grounded == false)
		sf::RectangleShape::move(0, -2);
	if (clock.getElapsedTime().asSeconds() >= 1 && getPosition().x < viewport.getCenter().x
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


int Rockets::getPoints()
{
	if (grounded == true)
		return 50;
	else
		return 80;
}


void Rockets::print(sf::RenderWindow& window)
{
	sprite.setPosition(getPosition().x, getPosition().y);
	//window.draw(*this);
	window.draw(sprite);
}


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

	if (grounded == false && spriteClock.getElapsedTime().asMilliseconds() >= 250)
	{
		spriteClock.restart();
		spriteNum++;
		if (spriteNum == 3)
			spriteNum = 0;
	}

	file = "./sprites/" + color + "rocket" + num + ".png";
	image.loadFromFile(file);
	sprite.setTexture(image);
	sprite.setScale(3, 3);

}