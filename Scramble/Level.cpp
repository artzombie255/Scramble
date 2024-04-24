#include "Level.h"


//level 1: 361, level 2: 225, level 3: 227, 
// level 4: 329, level 5: 225, level 6: 139 


Level::Level()
{
	levelOffset = 0;
	for (int i = 0; i < 34; i++)
		for (int z = 0; z < 7; z++)
		{
			std::string tempI, tempZ;
			tempI = std::to_string(i);
			tempZ = std::to_string(z);

			levelTexture[i][z].loadFromFile
			("./sprites/" + tempZ + "map/" + tempZ + "map" + tempI + ".png");
		}

	for (int i = 0; i < 34; i++)
	{
		levelSprite[i].setTexture(levelTexture[i][0]);
		levelSprite[i].setScale(3, 3);
	}
}


Level::Level(int levelNum)
{
	levelOffset = 0;
	for (int i = 0; i < 34; i++)
		for (int z = 0; z < 7; z++)
		{
			std::string tempI, tempZ;
			tempI = std::to_string(i);
			tempZ = std::to_string(z);

			levelTexture[i][z].loadFromFile
			("./sprites/" + tempZ + "map/" + tempZ + "map" + tempI + ".png");
		}

	switch (levelNum)
	{
	case 6:
		levelOffset += 225;
	case 5:
		levelOffset += 329;
	case 4:
		levelOffset += 227;
	case 3:
		levelOffset += 225;
	case 2:
		levelOffset += 361;
	}

	//levelOffset = 0;

	for (int i = 0; i < 34; i++)
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
		for (int i = 0; i < 25; i++)
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
void Level::loadLevel(sf::RenderWindow& window, sf::View& viewPort)
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

	for (int j = 0; j < 25; j++)
	{
		for (int i = ((viewPort.getCenter().x - 336) / 24) - (levelOffset); 
			i < (viewPort.getCenter().x - 336) / 24 - levelOffset + 30; i++)
		{
			// Verifies within acceptable ASCII ranges
			// 48-57 for 0-9 | 97-119 for a-w
			if ((levelArrVec[j][i] >= 48 && levelArrVec[j][i] <= 57) || 
				(levelArrVec[j][i] >= 97 && levelArrVec[j][i] <= 119)
				|| levelArrVec[j][i] == 75)
			{
				if (levelArrVec[j][i] >= 48 && levelArrVec[j][i] <= 57)
					offset = 48;
				else if(levelArrVec[j][i] == 75)
					offset = 42;
				else
					offset = 87;
				levelSprite[levelArrVec[j][i] - offset].setPosition
				((i + levelOffset) * 24, 96 + (j * 24));
				window.draw(levelSprite[levelArrVec[j][i] - offset]);
			}
			else if (levelArrVec[j][i] == 120 || levelArrVec[j][i] == 121
				|| levelArrVec[j][i] == 82 || levelArrVec[j][i] == 85
				|| levelArrVec[j][i] == 65 || levelArrVec[j][i] == 70
				|| levelArrVec[j][i] == 66 || levelArrVec[j][i] == 79)
			{
				//std::cout << "ignore";
			}
			else
			{
				//std::cout << static_cast<int>(levelArrVec[j][i]) << " I: " << i << " J: " << j;
				//throw std::runtime_error("INVALID LEVEL ENTRY");
			}
		}
	}
	viewPort.move(3, 0);
	window.setView(viewPort);
}


void Level::colorSwap(int palette)
{
	for (int i = 0; i < 34; i++)
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


sf::Sprite Level::getSprite()
{
	return levelSprite[0];
}


void Level::setLevelArrVec(std::vector<char> tempLevelArrVec[25])
{
	tempLevelArrVec->clear();
	for (int j = 0; j < 25; j++)
	{
		for (int i = 0; i < levelArrVec[0].size(); i++)
		{
			tempLevelArrVec[j].push_back(levelArrVec[j][i]);
		}
	}
}

//adjust these nums
int Level::currentLevel(sf::View& view)
{
	if (view.getCenter().x - 336 < 8824)
		return 1;
	else if (view.getCenter().x - 336 < 18016 && view.getCenter().x - 336 >= 8824)
		return 2;
	else if (view.getCenter().x - 336 < 19864 && view.getCenter().x - 336 >= 18016)
		return 3;
	else if (view.getCenter().x - 336 < 27760 && view.getCenter().x - 336 >= 19864)
		return 4;
	else if (view.getCenter().x - 336 < 33160 && view.getCenter().x - 336 >= 27760)
		return 5;
	else if (view.getCenter().x - 336 > 33160)
		return 6;
}

int Level::getOffset()
{
	return levelOffset;
}
