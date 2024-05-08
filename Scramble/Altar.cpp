#include "Altar.h"


Altar::Altar()
{
	setSize(sf::Vector2f(48, 48));
	setOrigin(0, 0);
	setPosition((rand() % 2000 + 300), 500);
	points = 100 * (rand() % 3 + 1);
	name = "altar.png";
}


Altar::Altar(int x, int y)
{
	setSize(sf::Vector2f(48, 48));
	setPosition(x, y);
	points = 100 * (rand() % 3 + 1);
	name = "altar.png";
}


Altar::~Altar()
{
}

//pastes an alter
void Altar::print(sf::RenderWindow& window)
{
	sprite.setPosition(getPosition().x, getPosition().y);
	//window.draw(*this);
	window.draw(sprite);
}

//changes the color palette of an alter
void Altar::changeSprite(int palette)
{
	Enemy::changeSprite(palette);
}

//returns points for destroying an alter
int Altar::getPoints()
{
	srand(time(NULL));

	return (rand() % 3 + 1) * 100;
}
