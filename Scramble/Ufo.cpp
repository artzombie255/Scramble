#include "Ufo.h"


Ufo::Ufo()
{
	points = 100;
	setSize(sf::Vector2f(48, 48));
	setOrigin(0, 0);
	setPosition((rand() % 5000 + 300), 500);
	start = getPosition().y;
	moveDir = -5;
	image.loadFromFile("./sprites/Ufo.png");
	sprite.setTexture(image);
	sprite.setScale(3, 3);
}

Ufo::Ufo(int x, int y)
{
	points = 100;
	setSize(sf::Vector2f(48, 48));
	setOrigin(0, 0);
	setPosition(x, y);
	start = getPosition().y;
	moveDir = -5;
	image.loadFromFile("./sprites/Ufo.png");
	sprite.setTexture(image);
	sprite.setScale(3, 3);
}


Ufo::~Ufo()
{

}

//moves ufo up and down
void Ufo::move(sf::Clock &clock, sf::View viewport)
{
	if (destroyed == false)
		sf::RectangleShape::move(0, moveDir);

	if (getPosition().y >= start)
		moveDir = -5;
	else if (getPosition().y <= start - 200)
		moveDir = 5;
}

//pastes ufo
void Ufo::print(sf::RenderWindow& window)
{
	sprite.setPosition(getPosition().x, getPosition().y);
	window.draw(sprite);
}

//useless
void Ufo::changeSprite(int palette)
{
	std::string file;

	if (destroyed == true)
	{
		file = "./sprites/UfoBoom" + std::to_string(boomNum) + ".png";
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

//returms points given for destroying ufo
int Ufo::getPoints()
{
	return 100;
}

