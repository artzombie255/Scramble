#include "Altar.h"


Altar::Altar()
{
	points = 100 * (rand() % 3 + 1);
}


Altar::~Altar()
{
}


void Altar::print(sf::RenderWindow& window)
{
	window.draw(*this);
}


void Altar::changeSprite(sf::Clock&, sf::Sprite&)
{

}
