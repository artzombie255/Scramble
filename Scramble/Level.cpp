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
    std::string temp;

    while (file.is_open())
    {
        file >> temp;
        file.close();
    }

    while (temp.size() > 0)
    {
        for (int i = 0; i < 25; i++)
        {
            levelArrVec[i % 25].push_back(temp.at(0));
            temp.erase(0, 1);
        }
    }
}

//loads each level into sfml
void Level::loadLevel()
{

}

void Level::colorSwap()
{

}

//checks for position of pieces in each type of 
//piece and idetifies if it has struck something
bool Level::checkCollision(Player user)
{
    return true;
}


