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
