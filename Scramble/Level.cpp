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
    std::string levelSequence
    std::string temp;

    while (file >> temp)
    {
        levelSequence += temp;
    }

    file.close();

    while (levelSequence.size() > 0)
    {
        for (int i = 0; i < 25; i++)
        {
            levelArrVec[i % 25].push_back(levelSequence.at(0));
            levelSequence.erase(0, 1);
        }
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


