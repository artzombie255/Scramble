#include "Base.h"


Base::Base()
{
	points = 800;
}


Base::~Base()
{

}


void Base::print(sf::RenderWindow& window)
{
	window.draw(*this);
}
