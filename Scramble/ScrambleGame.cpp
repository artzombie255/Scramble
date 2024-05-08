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
    sf::Sprite playerSprite, rocketSprite, lifeSprite;
    sf::Texture lifeTexture;

    sf::View viewPort;
    //level 1: 361, level 2: 223, level 3: 227, level 4: 329, level 5: 225, level 6: 139 
    int currentLevel = 1, textMove = 0;
    /*
    Level* level = new Level[6]
    {
        Level(1),
        Level(2),
        Level(3),
        Level(4),
        Level(5),
        Level(6)
    };*/

    Level *level = new Level;

    sf::Texture counterText[6];
    sf::Sprite counterSprite[6];
    for (int i = 0; i < 6; i++)
    {
        std::string tempI;
        tempI = std::to_string(i);
        counterText[i].loadFromFile("./sprites/levelNum" + tempI + ".png");
    }

    for (int i = 0; i < 6; i++)
    {
        counterSprite[i].setTexture(counterText[i]);
        counterSprite[i].setScale(3, 3);
    }
    sf::Texture onLevelText, offLevelText;
    sf::Sprite onLevelSprite, offLevelSprite;
    onLevelText.loadFromFile("./sprites/levelCount1.png");
    offLevelText.loadFromFile("./sprites/levelCount0.png");
    onLevelSprite.setTexture(onLevelText);
    offLevelSprite.setTexture(offLevelText);
    onLevelSprite.setScale(3, 3);
    offLevelSprite.setScale(3, 3);

    int palette = 0;
    std::vector<char> levelArrVec[25];
    

    lifeTexture.loadFromFile("./sprites/lives.png");
    lifeSprite.setTexture(lifeTexture);
    lifeSprite.setScale(3, 3);

    viewPort.setCenter(336, 408);
    viewPort.setSize(672, 816);


    srand(time(NULL));
    /*level[0].readFromFile("level1.txt");
    level[0].readFromFile("level2.txt");
    level[0].readFromFile("level3.txt");
    level[0].readFromFile("level4.txt");
    level[0].readFromFile("level5.txt");
    level[0].readFromFile("level6.txt");
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
    
    level[0].setEntities(enemyVec);
    level[2].setEntities(enemyVec);
    level[4].setEntities(enemyVec);
    */

    level->readFromFile("level1.txt");
    level->readFromFile("level2.txt");
    level->readFromFile("level3.txt");
    level->readFromFile("level4.txt");
    level->readFromFile("level5.txt");
    level->readFromFile("level6.txt");

    level->setEntities(enemyVec);

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

    level->setLevelArrVec(levelArrVec);

    window.setFramerateLimit(60);

    for (int i = enemyVec.size() - 1; i > 0; i--)
    {
        enemyVec.at(i)->changeSprite(palette);
    }

    //scoring text
    sf::Font font;
    font.loadFromFile("arcade-legacy.ttf");

    int score = player.getScore();
    int highScore = 10000;

    std::string scoreStr = std::to_string(score);
    std::string highSStr = std::to_string(highScore);
    
    sf::Text highSTxt;
    highSTxt.setString(highSStr);
    highSTxt.setFont(font);
    highSTxt.setPosition(400, 22);
    highSTxt.setCharacterSize(highSTxt.getCharacterSize() * 3 / 4);
    sf::Text scoreTxt;
    scoreTxt.setString(scoreStr);
    scoreTxt.setFont(font);
    scoreTxt.setPosition(100, 22);
    scoreTxt.setCharacterSize(scoreTxt.getCharacterSize() * 3 / 4);
    sf::Text upTxt;
    upTxt.setString("1UP");
    upTxt.setFont(font);
    upTxt.setPosition(100, 0);
    upTxt.setCharacterSize(upTxt.getCharacterSize() * 3 / 4);
    sf::Text highScoreTxt;
    highScoreTxt.setString("HIGH SCORE");
    highScoreTxt.setFont(font);
    highScoreTxt.setPosition(400, 0);
    highScoreTxt.setCharacterSize(highScoreTxt.getCharacterSize() * 3 / 4);
  
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
            for (int i = 0; i < 6; i++)
                level->colorSwap(palette);
            paletteClock.restart();
        }
        for (int i = enemyVec.size() - 1; i >= 0; i--)
        {
            if (enemyVec.at(i)->getPosition().x > viewPort.getCenter().x - 400 && enemyVec.at(i)->getPosition().x < viewPort.getCenter().x + 400)
                enemyVec.at(i)->changeSprite(palette);
        }
        player.changeSprite(playerSpriteClock, playerSprite);


        //move entities
        player.move(bullet, missile, viewPort);

        for (int i = 0; i < enemyVec.size(); i++)
        {
            enemyVec.at(i)->move(clock, viewPort);
        }

        if (currentLevel != level->currentLevel())
        {
            std::cout << "change level" << currentLevel + 1;
            currentLevel = level->currentLevel();
            //level.setLevelArrVec(levelArrVec);
        }


        //process interactions
        player.hit(enemyVec, bullet, missile);
        player.crash(enemyVec, currentLevel, level, viewPort, palette, textMove);
        player.crash(levelArrVec, level->getSprite(), currentLevel, level, viewPort, enemyVec, palette, textMove);

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

        level->loadLevel(window, viewPort, enemyVec);

        scoreStr = std::to_string(score);
        highSStr = std::to_string(highScore);

        scoreTxt.setString(scoreStr);
        if (highScore > 10000)
            highSTxt.setString(scoreStr);
        else
            highSTxt.setString(highSStr);

        for (int i = 1; i <= 6; i++)
        {
            counterSprite[i - 1].setPosition(48 + ((i-1) * 96) + textMove, 48);
            window.draw(counterSprite[i - 1]);
        }

        for (int i = 1; i <= 6; i++)
        {
            if (i <= currentLevel)
            {
                onLevelSprite.setPosition(48 + ((i - 1) * 96) + textMove, 72);
                window.draw(onLevelSprite);
            }
            else
            {
                offLevelSprite.setPosition(48 + ((i - 1) * 96) + textMove, 72);
                window.draw(offLevelSprite);
            }
            
        }
        

        // End the current frame and display its contents on screen
        for (int i = 0; i < player.getLives(); i++)
        {
            lifeSprite.setPosition(viewPort.getCenter().x - (viewPort.getSize().x / 2) + (50 * i), 764);
            window.draw(lifeSprite);
        }

        window.draw(upTxt);
        window.draw(highSTxt);
        window.draw(highScoreTxt);
        window.draw(scoreTxt);
        score = player.getScore();
        window.display();
        textMove += 3;

        highSTxt.setPosition(400 + textMove, 22);
        scoreTxt.setPosition(100 + textMove, 22);
        upTxt.setPosition(100 + textMove, 0);
        highScoreTxt.setPosition(400 + textMove, 0);
        //std::cout << viewPort.getCenter().x << std::endl;
    }

    //clean up
    for (int i = enemyVec.size() - 1; i >= 0; i--)
    {
        delete enemyVec.at(i);
    }

    delete level;

}
