#include "Level.h"

Level::Level()
{
    
}

Level::~Level()
{

}

//takes information from file to make level 
void Level::loadFromFile(std::ifstream file, std::string fileName)
{
    file.loadFromFile(fileName);

	while (file.is_open())
	{
		std::string temp;
		int i = 0;
		while (std::getline(file, temp))
		{
			while (temp.size() > 0)
			{
				level[i].push_back(temp.at(0));
				temp.erase(0, 1);
			}
			i++;
		}
		file.close();
	}
}

//loads each level into sfml
void Level::loadLevel(sf::RenderWindow window)
{
	
}

void Level::colorSwap(int color)
{

}

//checks for position of pieces in each type of 
//piece and idetifies if it has struck something
bool Level::checkCollision(Player user)
{
    return true;
}


