#include "Base.h"


Base::Base()
{
	setSize(sf::Vector2f(48, 48));
	setOrigin(0, 0);
	setPosition((rand() % 2000 + 300), 500);
	points = 800;
	name = "base.png";
}

Base::Base(int x, int y)
{
	setSize(sf::Vector2f(48, 48));
	setOrigin(0, 0);
	setPosition(x, y);
	points = 800;
	name = "base.png";
}


Base::~Base()
{

}


void Base::print(sf::RenderWindow& window)
{
	sprite.setPosition(getPosition().x, getPosition().y);
	//window.draw(*this);
	window.draw(sprite);
}


void Base::changeSprite(int palette)
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
	}

	if (spriteClock.getElapsedTime().asMilliseconds() >= 100)
	{
		spriteClock.restart();
		spriteNum++;
		if (spriteNum == 3)
			spriteNum = 0;
	}

	file = "./sprites/" + color + "base" + num + ".png";
	image.loadFromFile(file);
	sprite.setTexture(image);
	sprite.setScale(3, 3);
}

int Base::getPoints()
{
	return 800;
}


int isBase()
{
	return true;
}
