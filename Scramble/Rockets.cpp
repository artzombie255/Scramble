#include "Rockets.h"


Rockets::Rockets()
{
	setSize(sf::Vector2f(30, 50));
	setOrigin(0, 0);
	setPosition((rand() % 2000 + 300), 500);
}


Rockets::~Rockets()
{

}


void Rockets::move(sf::Clock &clock)
{
	sf::RectangleShape::move(-1, 0);
	if (grounded == false)
		sf::RectangleShape::move(0, -2);
	if (clock.getElapsedTime().asSeconds() >= 1 && getPosition().x < 450)
	{
		clock.restart();
		takeoff();
	}
	return;
}


void Rockets::takeoff()
{
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
	window.draw(*this);
}


void Rockets::changeSprite(sf::Clock& clock, sf::Sprite& sprite)
{
	sf::Texture image;
	std::string file, r = "rocket ", p = ".png", num, color;

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

	/*
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
	}*/

	if (clock.getElapsedTime().asMilliseconds() >= 100)
	{
		clock.restart();
		file = color + r + num + p;
		image.loadFromFile(file);
		sprite.setTexture(image);
		sprite.setScale(3, 3);
		spriteNum++;
		if (spriteNum == 8)
			spriteNum = 0;
	}
}
