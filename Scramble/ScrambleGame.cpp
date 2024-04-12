#include "ScrambleGame.h"
#include "Altar.h"
#include "Base.h"
#include "Enemy.h"
#include "Entity.h"
#include "FuelTower.h"
#include "Level.h"
#include "Meteors.h"
#include "Player.h"
#include "Rockets.h"
#include "Ufo.h"
#include <iostream>
#include <SFML/Graphics.hpp>


ScrambleGame::ScrambleGame()
{

}


ScrambleGame::~ScrambleGame()
{

}


void ScrambleGame::playGame()
{
    //header = 32
    //bottom = 16
    //play area = 224
    sf::RenderWindow window(sf::VideoMode(672, 816), "Scramble");
	Player player;
    sf::RectangleShape bullet[4], missile[2];
    //can hold any enemy, deletes them when they are killed
    std::vector<Enemy*> enemyVec;
    //animations and palette swaps
    sf::Clock clock, playerSpriteClock, fuelClock, paletteClock, levelClock;
    sf::Sprite playerSprite, rocketSprite;
    sf::Texture tempI;
    sf::Shader test;
    sf::View viewPort;
    //level 1: 361, level 2: 223, level 3: 227, level 4: 329, level 5: 225, level 6: 139 
    int currentLevel = 1;

    Level* level = new Level[6]
    {
        Level(1),
        Level(2),
        Level(3),
        Level(4),
        Level(5),
        Level(6)
    };
        //levels[6] =
   // {
      //  Level(1),
     //   Level(2),
//Level(3),
    //    Level(4),
    //    Level(5),
//Level(6)
    //};
    int palette = 0;
    std::vector<char> levelArrVec[25];
    

    viewPort.setCenter(336, 408);
    viewPort.setSize(672, 816);

    srand(time(NULL));
    level[0].readFromFile("level1.txt");
    level[0].readFromFile("level2.txt");
    //level[1].readFromFile("level1.txt");
    level[1].readFromFile("level2.txt");
    level[1].readFromFile("level3.txt");
    level[2].readFromFile("level3.txt");
    level[2].readFromFile("level4.txt");
    level[3].readFromFile("level4.txt");
    level[3].readFromFile("level5.txt");
    level[4].readFromFile("level5.txt");
    level[4].readFromFile("level6.txt");
    level[5].readFromFile("level6.txt");
    
    player.changeSprite(playerSpriteClock, playerSprite);
 

    //setup
    for (int i = 0; i < TOTAL_BULLETS; i++)
    {
        bullet[i].setSize(sf::Vector2f(5, 5));
        bullet[i].setOrigin(0, 0);
    }
    for (int i = 0; i < 2; i++)
    {
        missile[i].setSize(sf::Vector2f(10, 10));
        missile[i].setOrigin(0, 0);
    }

    level[0].setLevelArrVec(levelArrVec);

    window.setFramerateLimit(60);

    for (int i = 20; i > 0; i--)
    {
        enemyVec.push_back(new Rockets());
        enemyVec.push_back(new Ufo());
        enemyVec.push_back(new FuelTower());
        enemyVec.push_back(new Altar());
    }

    for (int i = enemyVec.size() - 1; i > 0; i--)
    {
        enemyVec.at(i)->changeSprite(palette);
    }
  
    //window
    while (window.isOpen())
    {
        // Event processing
        sf::Event e;
        while (window.pollEvent(e))
        {
            // Request for closing the window
            if (e.type == sf::Event::Closed)
                window.close();

            //player events
            player.moveCheck();
            player.shootBlaster(bullet);
            player.shootMissiles(missile);
        }

        //change sprites for palette change and animations
        if (paletteClock.getElapsedTime().asMilliseconds() > 10000)
        {
            palette++;
            if (palette == 7)
                palette = 0;
            for (int i = enemyVec.size() - 1; i > 0; i--)
            {
                enemyVec.at(i)->changeSprite(palette);
            }
            for (int i = 0; i < 6; i++)
                level[currentLevel].colorSwap(palette);
            paletteClock.restart();
        }
        player.changeSprite(playerSpriteClock, playerSprite);


        //move entities
        player.move(bullet, missile, viewPort);

        for (int i = 0; i < enemyVec.size(); i++)
        {
            enemyVec.at(i)->move(clock);
        }

        if (currentLevel != level.currentLevel())
        {
            currentLevel++;
            level[currentLevel].setLevelArrVec(levelArrVec);
        }


        //process interactions
        player.hit(enemyVec, bullet, missile);
        player.crash(enemyVec);
        player.crash(levelArrVec, level[0].getSprite());

        //set up player sprite to print
        playerSprite.setPosition(player.getPosition().x - 39, player.getPosition().y - 9);

        // Clear the whole window before rendering a new frame
        window.clear();

        //Draw some graphical entities

        for (int i = 0; i < enemyVec.size(); i++)
        {
            enemyVec.at(i)->print(window);
            //get rid of off screen enemies
            if (enemyVec.at(i)->getPosition().x < 0 || enemyVec.at(i)->getPosition().y < 96)
            {
                delete enemyVec.at(i);
                for (int j = i + 1; j < enemyVec.size(); j++)
                {
                    enemyVec.at(j - 1) = enemyVec.at(j);
                }
                enemyVec.pop_back();

            }
        }
        for (int i = 0; i < TOTAL_BULLETS; i++)
            window.draw(bullet[i]);
        for (int i = 0; i < 2; i++)
            window.draw(missile[i]);
        window.draw(playerSprite);
        player.fuelLoss(fuelClock, window, viewPort);

        level[currentLevel - 1].loadLevel(window, viewPort);
        

        // End the current frame and display its contents on screen
        window.display();
    }

    //clean up
    for (int i = enemyVec.size() - 1; i >= 0; i--)
    {
        delete enemyVec.at(i);
    }

    delete[] level;

}
