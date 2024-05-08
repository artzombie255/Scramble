#include "Entity.h"


Entity::Entity()
{
}

Entity::~Entity()
{
}

/*
void Entity::moveCheck()
{

}
*/

//returns y postion of entity 
int Entity::getY()
{
	return Y;
}

//returns x postion of entity 
int Entity::getX()
{
	return X;
}

//colorswap
void Entity::changeSprite(sf::Clock&, sf::Sprite&)
{
}
