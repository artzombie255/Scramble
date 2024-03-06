#include "Base.h"


Base::Base()
{
	setSize(sf::Vector2f(48, 48));
	setOrigin(0, 0);
	setPosition((rand() % 2000 + 300), 500);
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
	Enemy::changeSprite(palette);
}
