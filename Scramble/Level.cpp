#include "Level.h"

Level::Level()
{
	for (int i = 0; i < 33; i++)
		for (int z = 0; z < 7; z++)
		{
			std::string tempI, tempZ;
			tempI = std::to_string(i);
			tempZ = std::to_string(z);
			 
			levelTexture[i][z].loadFromFile(tempZ + "map" + tempI + ".png");
		}

	for (int i = 0; i < 33; i++)
	{
		levelSprite[i].setTexture(levelTexture[i][0]);
		levelSprite[i].setScale(3, 3);
	}
}

Level::~Level()
{

}

//takes information from file to make level 
void Level::readFromFile(std::ifstream file, std::string fileName)
{
    file.open(fileName);

	while (file.is_open())
	{
		std::string temp;
		int i = 0;
		while (std::getline(file, temp))
		{
			while (temp.size() > 0)
			{
				levelArrVec[i].push_back(temp.at(0));
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
	int offset;
	for (int i = 0; i < levelArrVec[0].size(); i++)
	{
		for (int j = 0; j < 28; j++)
		{
			// Verifies within acceptable ASCII ranges
			// 48-57 for 0-9 | 97-119 for a-w
			if ((i >= 48 && i <= 57) || (i >= 97 && i <= 119))
			{
				if (i >= 48 && i <= 57)
					offset = 48;
				else
					offset = 87;

				levelSprite[j - offset].setPosition(i * 24, 96 + i * 24);
				window.draw(levelSprite[j - offset]);
			}
			else if (i == 120 || i == 121)
			{
			}
			else
			{
				throw std::exception("INVALID LEVEL ENTRY");
			}
		}
	}

	if (levelArrVec[0].size() > 28)
	{
		for (int i = 0; i < 28; i++)
		{
			for (int z = 0; levelArrVec[i].size() - 1 > z; z++)
			{
				levelArrVec[i][z] = levelArrVec[i][z + 1];
			}
			levelArrVec[i].pop_back();
		}
	}
}


void Level::colorSwap(int palette)
{
	if (spriteClock.getElapsedTime().asMilliseconds() >= 250)
	{
		spriteClock.restart();
		for (int i = 0; i < 33; i++)
		{
			levelSprite[i].setTexture(levelTexture[i][palette]);
			levelSprite[i].setScale(3, 3);
		}
	}
}

//checks for position of pieces in each type of 
//piece and idetifies if it has struck something
bool Level::checkCollision(Player user)
{
    return true;
}


