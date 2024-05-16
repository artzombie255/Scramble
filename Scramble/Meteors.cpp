#include "Meteors.h"


Meteors::Meteors()
{

}


Meteors::Meteors(sf::View viewport)
{
	setSize(sf::Vector2f(48, 48));
	setOrigin(0, 0);
	setPosition(viewport.getCenter().x + 400, (rand() % 408 + 100));
	name = "meteor.png";
	destroyable = false;
}

Meteors::~Meteors()
{
}


void Meteors::move(sf::Clock& clock, sf::View viewport)
{
	sf::RectangleShape::move(-5, 0);
}

//displays meteors
void Meteors::print(sf::RenderWindow& window)
{
	sprite.setPosition(getPosition().x, getPosition().y);
	//window.draw(*this);
	window.draw(sprite);
}

//useless
void Meteors::changeSprite(int palette)
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
	}

	if (spriteClock.getElapsedTime().asMilliseconds() >= 150)
	{
		spriteClock.restart();
		spriteNum++;
		if (spriteNum == 3)
			spriteNum = 0;
	}

	file = "./sprites/meteor" + num + ".png";
	image.loadFromFile(file);
	sprite.setTexture(image);
	sprite.setScale(3, 3);
}
