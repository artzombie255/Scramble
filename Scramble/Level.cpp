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
void Level::loadLevel(sf::RenderWindow window)
{
	for (int i = 0; i < 4; i++)
	{
		for (int z = 0; z < levelArcVec[i].size(); z++)
		{
			if (levelArcVec[i][z] == '0')
			{
				levelSprite[0].setPosition(z * 8, i * 8);
				window.draw(levelSprite[0]);
				window.display();
				window.draw(levelSprite[0]);
			}
			else if (levelArcVec[i][z] == '1')
			{
				levelSprite[1].setPosition(z * 8, i * 8);
				window.draw(levelSprite[1]);
				window.display();
				window.draw(levelSprite[1]);
			}
			else if (levelArcVec[i][z] == '2')
			{
				levelSprite[2].setPosition(z * 8, i * 8);
				window.draw(levelSprite[2]);
				window.display();
				window.draw(levelSprite[2]);
			}
			else if (levelArcVec[i][z] == '3')
			{
				levelSprite[3].setPosition(z * 8, i * 8);
				window.draw(levelSprite[3]);
				window.display();
				window.draw(levelSprite[3]);
			}
			else if (levelArcVec[i][z] == '4')
			{
				levelSprite[4].setPosition(z * 8, i * 8);
				window.draw(levelSprite[4]);
				window.display();
				window.draw(levelSprite[4]);
			}
			else if (levelArcVec[i][z] == '5')
			{
				levelSprite[5].setPosition(z * 8, i * 8);
				window.draw(levelSprite[5]);
				window.display();
				window.draw(levelSprite[5);
			}
			else if (levelArcVec[i][z] == '6')
			{
				levelSprite[6].setPosition(z * 8, i * 8);
				window.draw(levelSprite[6]);
				window.display();
				window.draw(levelSprite[6]);
			}
			else if (levelArcVec[i][z] == '7')
			{
				levelSprite[7].setPosition(z * 8, i * 8);
				window.draw(levelSprite[7]);
				window.display();
				window.draw(levelSprite[7]);
			}
			else if (levelArcVec[i][z] == '8')
			{
				levelSprite[8].setPosition(z * 8, i * 8);
				window.draw(levelSprite[8]);
				window.display();
				window.draw(levelSprite[8]);
			}
			else if (levelArcVec[i][z] == '9')
			{
				levelSprite[9].setPosition(z * 8, i * 8);
				window.draw(levelSprite[9]);
				window.display();
				window.draw(levelSprite[9]);
			}
			else if (levelArcVec[i][z] == 'a')
			{
				levelSprite[10].setPosition(z * 8, i * 8);
				window.draw(levelSprite[10]);
				window.display();
				window.draw(levelSprite[10]);
			}
			else if (levelArcVec[i][z] == 'b')
			{
				levelSprite[11].setPosition(z * 8, i * 8);
				window.draw(levelSprite[11]);
				window.display();
				window.draw(levelSprite[11]);
			}
			else if (levelArcVec[i][z] == 'c')
			{
				levelSprite[12].setPosition(z * 8, i * 8);
				window.draw(levelSprite[12]);
				window.display();
				window.draw(levelSprite[12]);
			}
			else if (levelArcVec[i][z] == 'd')
			{
				levelSprite[13].setPosition(z * 8, i * 8);
				window.draw(levelSprite[13]);
				window.display();
				window.draw(levelSprite[13]);
			}
			else if (levelArcVec[i][z] == 'e')
			{
				levelSprite[14].setPosition(z * 8, i * 8);
				window.draw(levelSprite[14]);
				window.display();
				window.draw(levelSprite[14]);
			}
			else if (levelArcVec[i][z] == 'f')
			{
				levelSprite[15].setPosition(z * 8, i * 8);
				window.draw(levelSprite[15]);
				window.display();
				window.draw(levelSprite[15]);
			}
			else if (levelArcVec[i][z] == 'g')
			{
				levelSprite[16].setPosition(z * 8, i * 8);
				window.draw(levelSprite[16]);
				window.display();
				window.draw(levelSprite[16]);
			}
			else if (levelArcVec[i][z] == 'h')
			{
				levelSprite[17].setPosition(z * 8, i * 8);
				window.draw(levelSprite[17]);
				window.display();
				window.draw(levelSprite[17]);
			}
			else if (levelArcVec[i][z] == 'i')
			{
				levelSprite[18].setPosition(z * 8, i * 8);
				window.draw(levelSprite[18]);
				window.display();
				window.draw(levelSprite[18]);
			}
			else if (levelArcVec[i][z] == 'j')
			{
				levelSprite[19].setPosition(z * 8, i * 8);
				window.draw(levelSprite[19]);
				window.display();
				window.draw(levelSprite[19]);
			}
			else if (levelArcVec[i][z] == 'k')
			{
				levelSprite[20].setPosition(z * 8, i * 8);
				window.draw(levelSprite[20]);
				window.display();
				window.draw(levelSprite[20]);
			}
			else if (levelArcVec[i][z] == 'l')
			{
				levelSprite[21].setPosition(z * 8, i * 8);
				window.draw(levelSprite[21]);
				window.display();
				window.draw(levelSprite[21]);
			}
			else if (levelArcVec[i][z] == 'm')
			{
				levelSprite[22].setPosition(z * 8, i * 8);
				window.draw(levelSprite[22]);
				window.display();
				window.draw(levelSprite[22]);
			}
			else if (levelArcVec[i][z] == 'n')
			{
				levelSprite[23].setPosition(z * 8, i * 8);
				window.draw(levelSprite[23]);
				window.display();
				window.draw(levelSprite[23]);
			}
			else if (levelArcVec[i][z] == 'o')
			{
				levelSprite[24].setPosition(z * 8, i * 8);
				window.draw(levelSprite[24]);
				window.display();
				window.draw(levelSprite[24]);
			}
			else if (levelArcVec[i][z] == 'p')
			{
				levelSprite[25].setPosition(z * 8, i * 8);
				window.draw(levelSprite[25]);
				window.display();
				window.draw(levelSprite[25]);
			}
			else if (levelArcVec[i][z] == 'q')
			{
				levelSprite[26].setPosition(z * 8, i * 8);
				window.draw(levelSprite[26]);
				window.display();
				window.draw(levelSprite[26]);
			}
			else if (levelArcVec[i][z] == 'r')
			{
				levelSprite[27].setPosition(z * 8, i * 8);
				window.draw(levelSprite[27]);
				window.display();
				window.draw(levelSprite[27]);
			}
			else if (levelArcVec[i][z] == 's')
			{
				levelSprite[28].setPosition(z * 8, i * 8);
				window.draw(levelSprite[28]);
				window.display();
				window.draw(levelSprite[28]);
			}
			else if (levelArcVec[i][z] == 't')
			{
				levelSprite[29].setPosition(z * 8, i * 8);
				window.draw(levelSprite[29]);
				window.display();
				window.draw(levelSprite[29]);
			}
			else if (levelArcVec[i][z] == 'u')
			{
				levelSprite[30].setPosition(z * 8, i * 8);
				window.draw(levelSprite[30]);
				window.display();
				window.draw(levelSprite[30]);
			}
			else if (levelArcVec[i][z] == 'v')
			{
				levelSprite[31].setPosition(z * 8, i * 8);
				window.draw(levelSprite[31]);
				window.display();
				window.draw(levelSprite[31]);
			}
			else if (levelArcVec[i][z] == 'w')
			{
				levelSprite[32].setPosition(z * 8, i * 8);
				window.draw(levelSprite[32]);
				window.display();
				window.draw(levelSprite[32]);
			}

		}
	}
}

void Level::colorSwap(int color)
{
	for (int i = 0; i < 33; i++)
		levelSprite[i].setTexture(levelText[i][color]);
}

//checks for position of pieces in each type of 
//piece and idetifies if it has struck something
bool Level::checkCollision(Player user)
{
    return true;
}


