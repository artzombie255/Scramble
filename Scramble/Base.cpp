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


void Base::changeSprite(sf::Clock&, sf::Sprite&)
{
}
