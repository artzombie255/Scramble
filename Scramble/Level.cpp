#include "Level.h"

Level::Level()
{
	for (int i = 0; i < 33; i++)
		for (int z = 0; z < 7; z++)
		{
			std::string tempI, tempZ;
			tempI = std::to_string(i);
			tempZ = std::to_string(z);
			 
			levelTexture[i][z].loadFromFile("./sprites/" + tempZ + "map/" + tempZ + "map" + tempI + ".png");
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
void Level::readFromFile(std::string fileName)
{
	std::ifstream file;
    file.open(fileName);

	if (file.is_open())
	{
		std::string temp;
		for (int i = 0; i < 28; i++)
		{
			std::getline(file, temp);
			while (temp.size() > 0)
			{
				levelArrVec[i].push_back(temp.at(0));
				temp.erase(0, 1);
			}
		}
		file.close();
		//std::cout << "1 loaded";
	}
}


//loads each level into sfml
void Level::loadLevel(sf::RenderWindow& window)
{
	int offset;

	/*for (int j = 0; j < 28; j++)
	{
		for (int i = 0; i < 200; i++)
		{
			std::cout << levelArrVec[j][i];
		}
		std::cout << std::endl;
	}
	system("pause");
	*/
	for (int j = 0; j < 28; j++)
	{
		for (int i = 0; i < levelArrVec[0].size(); i++)
		{
			// Verifies within acceptable ASCII ranges
			// 48-57 for 0-9 | 97-119 for a-w
			if ((levelArrVec[j][i] >= 48 && levelArrVec[j][i] <= 57) || (levelArrVec[j][i] >= 97 && levelArrVec[j][i] <= 119))
			{
				if (levelArrVec[j][i] >= 48 && levelArrVec[j][i] <= 57)
					offset = 48;
				else
					offset = 87;
				levelSprite[levelArrVec[j][i] - offset].setPosition(i * 24 + k, 96 + (j * 24));
				window.draw(levelSprite[levelArrVec[j][i] - offset]);
			}
			else if (levelArrVec[j][i] == 120 || levelArrVec[j][i] == 121)
			{
				//std::cout << "ignore";
			}
			else
			{
				std::cout << static_cast<int>(levelArrVec[j][i]) << " I: " << i << " J: " << j;
				throw std::runtime_error("INVALID LEVEL ENTRY");
			}
		}
	}
	k--;
}


void Level::colorSwap(int palette)
{
	for (int i = 0; i < 33; i++)
	{
		levelSprite[i].setTexture(levelTexture[i][palette]);
		levelSprite[i].setScale(3, 3);
	}
}


//checks for position of pieces in each type of 
//piece and idetifies if it has struck something
bool Level::checkCollision(Player user)
{
    return true;
}