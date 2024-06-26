#include "Level.h"
#include "Altar.h"
#include "Base.h"
#include "Enemy.h"
#include "Entity.h"
#include "FuelTower.h"
#include "Meteors.h"
#include "Rockets.h"
#include "Ufo.h"


//level 1: 361, level 2: 225, level 3: 227, 
// level 4: 329, level 5: 225, level 6: 139 


Level::Level()
{
	levelOffset = 0;
	//sets needed textures for terrain building
	for (int i = 0; i < 34; i++)
		for (int z = 0; z < 7; z++)
		{
			std::string tempI, tempZ;
			tempI = std::to_string(i);
			tempZ = std::to_string(z);

			levelTexture[i][z].loadFromFile
			("./sprites/" + tempZ + "map/" + tempZ + "map" + tempI + ".png");
		}
	//sets needed sprites for terrain building
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
		levelOffset += 224;
	case 5:
		levelOffset += 328;
	case 4:
		levelOffset += 226;
	case 3:
		levelOffset += 224;
	case 2:
		levelOffset += 360;
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
	std::fstream file;
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

//erases the levels from the level array of vectors
void Level::clearVec()
{
	for (int i = 0; i < 25; i++)
		levelArrVec[i].clear();
	return;
}

//places enemies in their set location identified in the level txt file
void Level::setEntities(std::vector<Enemy*>& enemyVec)
{
	int x, y;
	for (int j = 0; j < 25; j++)
	{
		for (int i = 0; i < levelArrVec->size(); i++)
		{
			if (levelArrVec[j][i] == 82)
			{
				std::cout << "rocket:" << i << "\n" << j << "\n";
				x = (i + levelOffset) * 24;
				y = 96 + (j * 24);
				enemyVec.push_back(new Rockets(x, y));
			}
			else if (levelArrVec[j][i] == 85)
			{
				std::cout << "ufo:" << i << "\n" << j << "\n";
				x = (i + levelOffset) * 24;
				y = 96 + (j * 24);
				enemyVec.push_back(new Ufo(x, y));
			}
			else if (levelArrVec[j][i] == 70)
			{
				std::cout << "fuel tank:" << i << "\n" << j << "\n";
				x = (i + levelOffset) * 24;
				y = 96 + (j * 24);
				enemyVec.push_back(new FuelTower(x, y));
			}
			else if (levelArrVec[j][i] == 65)
			{
				std::cout << "Altar:" << i << "\n" << j << "\n";
				x = (i + levelOffset) * 24;
				y = 96 + (j * 24);
				enemyVec.push_back(new Altar(x, y));
			}
			else if (levelArrVec[j][i] == 66)
			{
				std::cout << "Base:" << i << "\n" << j << "\n";
				x = (i + levelOffset) * 24;
				y = 96 + (j * 24);
				enemyVec.push_back(new Base(x, y));
			}
		}
	}
}


//loads each level into sfml and finds current level
void Level::loadLevel(sf::RenderWindow& window, sf::View& viewPort, std::vector<Enemy*>& enemyVec)
{
	int offset;

	for (int j = 0; j < 25; j++)
	{
		for (int i = ((viewPort.getCenter().x - 336) / 24 - levelOffset);
			i < (viewPort.getCenter().x - 336) / 24 + 30 - levelOffset; i++)
		{
			// Verifies within acceptable ASCII ranges
			// 48-57 for 0-9 | 97-119 for a-w
			//std::cout << ((viewPort.getCenter().x - 336) / 24) - (levelOffset) << std::endl;
			//std::cout << (viewPort.getCenter().x - 336) / 24 - levelOffset + 30 << std::endl;
			if ((levelArrVec[j][i] >= 48 && levelArrVec[j][i] <= 57) ||
				(levelArrVec[j][i] >= 97 && levelArrVec[j][i] <= 119)
				|| levelArrVec[j][i] == 75)
			{
				if (levelArrVec[j][i] >= 48 && levelArrVec[j][i] <= 57)
					offset = 48;
				else if (levelArrVec[j][i] == 75)
					offset = 42;
				else
					offset = 87;
				levelSprite[levelArrVec[j][i] - offset].setPosition
				((i + levelOffset) * 24, 96 + (j * 24));
				window.draw(levelSprite[levelArrVec[j][i] - offset]);
			}
			else if (levelArrVec[j][i] > 32 && levelArrVec[j][i] < 39)
				levelOn = levelArrVec[j][i] - 32;
			//identifies current level by looking for select characters
		}
	}

	viewPort.move(3, 0);
	window.setView(viewPort);
}

//changes color sets for the terrain on each level
void Level::colorSwap(int palette)
{
	for (int i = 0; i < 34; i++)
	{
		levelSprite[i].setTexture(levelTexture[i][palette]);
		levelSprite[i].setScale(3, 3);
	}
}

//returns level 1 sprite
sf::Sprite Level::getSprite()
{
	return levelSprite[0];
}

//sets the array of vectors to make each level
void Level::setLevelArrVec(std::vector<char> tempLevelArrVec[25])
{
	for (int i = 0; i < 25; i++)
		tempLevelArrVec[i].clear();
	for (int j = 0; j < 25; j++)
	{
		for (int i = 0; i < levelArrVec[0].size(); i++)
		{
			tempLevelArrVec[j].push_back(levelArrVec[j][i]);
		}
	}
	return;
}

//returns the current level player is on
int Level::currentLevel()
{
	return levelOn;
}

//resturns the level offset
int Level::getOffset()
{
	return levelOffset;
}
