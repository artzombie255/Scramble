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
	for (int z = 0; z < levelArrVec[0].size(); z++)
	{
		for (int i = 0; i < 28; i++)
		{
			if (levelArrVec[i][z] == '0')
			{
				levelSprite[0].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[0]);
				window.display();
				window.draw(levelSprite[0]);
			}
			if (levelArrVec[i][z] == '1')
			{
				levelSprite[1].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[1]);
				window.display();
				window.draw(levelSprite[1]);
			}
			if (levelArrVec[i][z] == '2')
			{
				levelSprite[2].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[2]);
				window.display();
				window.draw(levelSprite[2]);
			}
			if (levelArrVec[i][z] == '3')
			{
				levelSprite[3].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[3]);
				window.display();
				window.draw(levelSprite[3]);
			}
			if (levelArrVec[i][z] == '4')
			{
				levelSprite[4].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[4]);
				window.display();
				window.draw(levelSprite[4]);
			}
			if (levelArrVec[i][z] == '5')
			{
				levelSprite[5].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[5]);
				window.display();
				window.draw(levelSprite[5]);
			}
			if (levelArrVec[i][z] == '6')
			{
				levelSprite[6].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[6]);
				window.display();
				window.draw(levelSprite[6]);
			}
			if (levelArrVec[i][z] == '7')
			{
				levelSprite[7].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[7]);
				window.display();
				window.draw(levelSprite[7]);
			}
			if (levelArrVec[i][z] == '8')
			{
				levelSprite[8].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[8]);
				window.display();
				window.draw(levelSprite[8]);
			}
			if (levelArrVec[i][z] == '9')
			{
				levelSprite[9].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[9]);
				window.display();
				window.draw(levelSprite[9]);
			}
			if (levelArrVec[i][z] == 'a')
			{
				levelSprite[10].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[10]);
				window.display();
				window.draw(levelSprite[10]);
			}
			if (levelArrVec[i][z] == 'b')
			{
				levelSprite[11].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[11]);
				window.display();
				window.draw(levelSprite[11]);
			}
			if (levelArrVec[i][z] == 'c')
			{
				levelSprite[12].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[12]);
				window.display();
				window.draw(levelSprite[12]);
			}
			if (levelArrVec[i][z] == 'd')
			{
				levelSprite[13].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[13]);
				window.display();
				window.draw(levelSprite[13]);
			}
			if (levelArrVec[i][z] == 'e')
			{
				levelSprite[14].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[14]);
				window.display();
				window.draw(levelSprite[14]);
			}
			if (levelArrVec[i][z] == 'f')
			{
				levelSprite[15].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[15]);
				window.display();
				window.draw(levelSprite[15]);
			}
			if (levelArrVec[i][z] == 'g')
			{
				levelSprite[16].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[16]);
				window.display();
				window.draw(levelSprite[16]);
			}
			if (levelArrVec[i][z] == 'h')
			{
				levelSprite[17].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[17]);
				window.display();
				window.draw(levelSprite[17]);
			}
			if (levelArrVec[i][z] == 'i')
			{
				levelSprite[18].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[18]);
				window.display();
				window.draw(levelSprite[18]);
			}
			if (levelArrVec[i][z] == 'j')
			{
				levelSprite[19].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[19]);
				window.display();
				window.draw(levelSprite[19]);
			}
			if (levelArrVec[i][z] == 'k')
			{
				levelSprite[20].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[20]);
				window.display();
				window.draw(levelSprite[20]);
			}
			if (levelArrVec[i][z] == 'l')
			{
				levelSprite[21].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[21]);
				window.display();
				window.draw(levelSprite[21]);
			}
			if (levelArrVec[i][z] == 'm')
			{
				levelSprite[22].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[22]);
				window.display();
				window.draw(levelSprite[22]);
			}
			if (levelArrVec[i][z] == 'n')
			{
				levelSprite[23].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[23]);
				window.display();
				window.draw(levelSprite[23]);
			}
			if (levelArrVec[i][z] == 'o')
			{
				levelSprite[24].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[24]);
				window.display();
				window.draw(levelSprite[24]);
			}
			if (levelArrVec[i][z] == 'p')
			{
				levelSprite[25].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[25]);
				window.display();
				window.draw(levelSprite[25]);
			}
			if (levelArrVec[i][z] == 'q')
			{
				levelSprite[26].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[26]);
				window.display();
				window.draw(levelSprite[26]);
			}
			if (levelArrVec[i][z] == 'r')
			{
				levelSprite[27].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[27]);
				window.display();
				window.draw(levelSprite[27]);
			}
			if (levelArrVec[i][z] == 's')
			{
				levelSprite[28].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[28]);
				window.display();
				window.draw(levelSprite[28]);
			}
			if (levelArrVec[i][z] == 't')
			{
				levelSprite[29].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[29]);
				window.display();
				window.draw(levelSprite[29]);
			}
			if (levelArrVec[i][z] == 'u')
			{
				levelSprite[30].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[30]);
				window.display();
				window.draw(levelSprite[30]);
			}
			if (levelArrVec[i][z] == 'v')
			{
				levelSprite[31].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[31]);
				window.display();
				window.draw(levelSprite[31]);
			}
			if (levelArrVec[i][z] == 'w')
			{
				levelSprite[32].setPosition(z * 24, (i * 24) + 96);
				window.draw(levelSprite[32]);
				window.display();
				window.draw(levelSprite[32]);
			}
		}
		window.display();
	}

	window.display();
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
		window.clear();
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


