#include "Ufo.h"


Ufo::Ufo()
{
	points = 100;
}


Ufo::~Ufo()
{

}


void Ufo::print(sf::RenderWindow& window)
{
	window.draw(*this);
}
