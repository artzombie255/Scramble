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
#include <windows.h>


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
    //play area = 200
    sf::RenderWindow window(sf::VideoMode(672, 744), "Scramble");
	Player player;
    sf::RectangleShape bullet[4], missile[2];
    //can hold any enemy, deletes them when they are killed
    std::vector<Enemy*> enemyVec;
    //animations and palette swaps
    sf::Clock clock, playerSpriteClock, fuelClock, paletteClock, levelClock, meteorClock, pointClock;
    sf::Sprite playerSprite, rocketSprite, lifeSprite, flagSprite;
    sf::Texture lifeTexture, flagText;

    flagText.loadFromFile("./sprites/flag.png");
    flagSprite.setTexture(flagText);
    flagSprite.setScale(3, 3);
    flagSprite.setPosition(654, 720);

    //gameover sprites
    sf::Texture endText;
    sf::Sprite endSprite;
    endText.loadFromFile("./sprites/gameover.png");
    endSprite.setTexture(endText);


    sf::View viewPort;
    //level 1: 361, level 2: 223, level 3: 227, 
    // level 4: 329, level 5: 228, level 6: 139 
    int currentLevel = 1, textMove = 0, palette = 0;

    Level *level = new Level;

    //sprites and texture for level counter
    sf::Texture counterText[6];
    sf::Sprite counterSprite[6];
    for (int i = 0; i < 6; i++)
    {
        std::string tempI;
        tempI = std::to_string(i);
        counterText[i].loadFromFile("./sprites/levelNum" + tempI + ".png");
    }

    //sets sprites for counting the levels displayed
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

    std::vector<char> levelArrVec[25];
    
    //sprite for lives
    lifeTexture.loadFromFile("./sprites/lives.png");
    lifeSprite.setTexture(lifeTexture);
    lifeSprite.setScale(3, 3);

    viewPort.setCenter(336, 372);
    viewPort.setSize(672, 744);


    srand(time(NULL));

    //loads levels into array of vectors
    level->readFromFile("levelIntro.txt");
    level->readFromFile("level1.txt");
    level->readFromFile("level2.txt");
    level->readFromFile("level3.txt");
    level->readFromFile("level4.txt");
    level->readFromFile("level5.txt");
    level->readFromFile("level6.txt");
    level->readFromFile("level6.txt");
    level->readFromFile("level6.txt");
    level->readFromFile("level6.txt");
    level->readFromFile("level6.txt");

    //places enemies on level
    level->setEntities(enemyVec);
    //player rocket animation
    player.changeSprite(playerSpriteClock, playerSprite);
 

    //setup
    for (int i = 0; i < TOTAL_BULLETS; i++)
    {
        bullet[i].setSize(sf::Vector2f(5, 5));
    }
    for (int i = 0; i < 2; i++)
    {
       missile[i].setSize(sf::Vector2f(10, 10));
    }
    //sets array of vectors for levels
    level->setLevelArrVec(levelArrVec);

    window.setFramerateLimit(60);

    for (int i = enemyVec.size() - 1; i > 0; i--)
    {
        enemyVec.at(i)->changeSprite(palette);
    }

    //scoring text
    sf::Font font;
    font.loadFromFile("arcade-legacy.ttf");

    //sets high score(the default high score being 10000) 
    // and current player score
    int score = player.getScore();
    int highScore = 10000;

    std::string scoreStr = std::to_string(score);
    std::string highSStr = std::to_string(highScore);
    
    sf::Text highSTxt;
    highSTxt.setString(highSStr);
    highSTxt.setFont(font);
    highSTxt.setPosition(400, 22);
    highSTxt.setCharacterSize(highSTxt.getCharacterSize() * 3 / 4);
    highSTxt.setFillColor(sf::Color::Yellow);
    sf::Text scoreTxt;
    scoreTxt.setString(scoreStr);
    scoreTxt.setFont(font);
    scoreTxt.setPosition(100, 22);
    scoreTxt.setCharacterSize(scoreTxt.getCharacterSize() * 3 / 4);
    scoreTxt.setFillColor(sf::Color::Yellow);
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

    sf::Text fuelTxt;
    fuelTxt.setString("FUEL");
    fuelTxt.setFont(font);
    fuelTxt.setPosition(100, 700);
    fuelTxt.setCharacterSize(fuelTxt.getCharacterSize() * 3 / 4);
    fuelTxt.setFillColor(sf::Color::Yellow);



    if (window.isOpen())
    {
        sf::Texture screen1Txt, screen2Txt, screen3Txt, screen4Txt;
        screen1Txt.loadFromFile("./sprites/screen1.png");
        screen2Txt.loadFromFile("./sprites/screen2.png");
        //screen3Txt.loadFromFile("./sprites/screen3.png");
        screen4Txt.loadFromFile("./sprites/screen4.png");
        sf::Sprite screen1, screen2, screen3, screen4;
        screen1.setTexture(screen1Txt);
        screen2.setTexture(screen2Txt);
        //screen3.setTexture(screen3Txt);
        screen4.setTexture(screen4Txt);

        window.draw(screen1);
        window.display();
        Sleep(2000);
        window.clear();

        window.draw(screen2);
        window.draw(upTxt);
        window.draw(highSTxt);
        window.draw(highScoreTxt);
        window.draw(scoreTxt);
        window.display();
        Sleep(4000);
        window.clear();

        window.draw(screen4);
        window.draw(upTxt);
        window.draw(highSTxt);
        window.draw(highScoreTxt);
        window.draw(scoreTxt);
        window.display();
        Sleep(10000);
        window.clear();

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


        if (pointClock.getElapsedTime().asMilliseconds() > 1000)
        {
            player.addPoints(10);
            pointClock.restart();
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
            if (enemyVec.at(i)->getPosition().x > viewPort.getCenter().x - 400 
                && enemyVec.at(i)->getPosition().x < viewPort.getCenter().x + 400)
                enemyVec.at(i)->changeSprite(palette);
        }
        player.changeSprite(playerSpriteClock, playerSprite);
        scoreStr = std::to_string(score);
        highSStr = std::to_string(highScore);

        scoreTxt.setString(scoreStr);
        if (highScore > 10000)
            highSTxt.setString(scoreStr);
        else
            highSTxt.setString(highSStr);


        
        if (player.getLives() > 0)
        {
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
                currentLevel = level->currentLevel();

            if (currentLevel == 3 && meteorClock.getElapsedTime().asMilliseconds() > 500)
            {
                meteorClock.restart();
                enemyVec.push_back(new Meteors(viewPort));
            }



            if (player.hit(enemyVec, bullet, missile) == 1)
            {
                int tempPoints;
                player.addFuel(128);
                textMove = 0;
                tempPoints = player.getScore();
                for (int i = enemyVec.size() - 1; i >= 0; i--)
                {
                    enemyVec.at(i)->setPosition(-200, -200);
                }
                player.setPoints(tempPoints);

                level->setEntities(enemyVec);

                for (int i = enemyVec.size() - 1; i > 0; i--)
                {
                    enemyVec.at(i)->changeSprite(palette);
                }
                viewPort.setCenter(336, 372);
                player.setPosition(400, 200);
                player.changeFuelSpeed();
            }
            player.crash(enemyVec, currentLevel, level, viewPort,
            palette, textMove, levelArrVec, window, playerSprite);
            player.crash(levelArrVec, level->getSprite(), currentLevel, 
            level, viewPort, enemyVec, palette, textMove, window, playerSprite);

            //set up player sprite to print
            playerSprite.setPosition(player.getPosition().x - 39,
            player.getPosition().y - 9);

            // Clear the whole window before rendering a new frame
            window.clear();

            //Draw some graphical entities

            for (int i = 0; i < enemyVec.size(); i++)
            {
                enemyVec.at(i)->print(window);
                //get rid of off screen enemies
                if (enemyVec.at(i)->getPosition().x < 0
                    || enemyVec.at(i)->getPosition().y < 96)
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

            level->loadLevel(window, viewPort, enemyVec);

            //updates current player score and high score
            //prints the level counter information
            for (int i = 1; i <= 6; i++)
            {
                counterSprite[i - 1].setPosition(48 + ((i - 1) * 96) + textMove, 48);
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
                lifeSprite.setPosition(viewPort.getCenter().x - (viewPort.getSize().x / 2) + (50 * i), 719);
                window.draw(lifeSprite);
            }

            player.fuelLoss(fuelClock, window, viewPort);

            //draws all the text at the top of the screen
            window.draw(upTxt);
            window.draw(highSTxt);
            window.draw(highScoreTxt);
            window.draw(scoreTxt);
            window.draw(flagSprite);
            window.draw(fuelTxt);

            //updates player score
            score = player.getScore();
            window.display();
            textMove += 3;

            //keeps high score text in frame
            highSTxt.setPosition(400 + textMove, 22);
            scoreTxt.setPosition(100 + textMove, 22);
            upTxt.setPosition(100 + textMove, 0);
            highScoreTxt.setPosition(400 + textMove, 0);
            flagSprite.setPosition(654 + textMove, 719);
            fuelTxt.setPosition(100 + textMove, 696);
            //std::cout << viewPort.getCenter().x << std::endl;
        }
        else
        {
            viewPort.setCenter(336, 408);
            window.clear();
            window.draw(upTxt);
            window.draw(highSTxt);
            window.draw(highScoreTxt);
            window.draw(scoreTxt);
            player.fuelLoss(fuelClock, window, viewPort);
            window.draw(endSprite);
            window.draw(fuelTxt);
            window.display();
        }
    }

    //clean up
    for (int i = enemyVec.size() - 1; i >= 0; i--)
    {
        delete enemyVec.at(i);
    }

    delete level;
    
}
