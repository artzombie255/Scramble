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
}

Meteors::~Meteors()
{
}


void Meteors::move()
{
	//unfinished
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
	/*std::string file, num, color = "0";

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

	if (grounded == false && spriteClock.getElapsedTime().asMilliseconds() >= 150)
	{
		spriteClock.restart();
		spriteNum++;
		if (spriteNum == 4)
			spriteNum = 1;
	}

	file = "./sprites/" + color + "rocket" + num + ".png";
	image.loadFromFile(file);
	sprite.setTexture(image);
	sprite.setScale(3, 3);*/
}
