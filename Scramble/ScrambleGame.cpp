#include "ScrambleGame.h"
#include "Altar.h"
#include "Base.h"
#include "Enemy.h"
#include "Entity.h"
#include "FuelTower.h"
//#include "Level.h"
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
    std::vector<Enemy*> enemyVec;
    sf::Clock clock, playerSpriteClock;
    sf::Sprite playerSprite, rocketSprite;
    sf::Texture tempI;
    sf::Shader test;
    int palette;
    
    srand(time(NULL));

    //test.loadFromFile("Shader_colour_swap.frag", sf::Shader::Fragment);
    //test.setUniform("COLOR", sf::Glsl::Vec4());
    //test.setUniform("TEXTURE", sf::Shader::CurrentTexture);
    //test.setUniform("UV", sf::Glsl::Vec4());
    //sf::Shader::bind(&test);
    //tempI.loadFromFile("2rocket0.png");
    player.changeSprite(playerSpriteClock, playerSprite);
    //rocketSprite.setTexture(tempI);
    //rocketSprite.scale(5, 5);


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

    window.setFramerateLimit(60);

    for (int i = 20; i > 0; i--)
    {
        enemyVec.push_back(new Rockets());
        enemyVec.push_back(new Ufo());
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
        player.changeSprite(playerSpriteClock, playerSprite);
        for (int i = enemyVec.size() - 1; i > 0; i--)
        {
            enemyVec.at(i)->changeSprite(0);
        }

        //move entities
        player.move(bullet, missile);
        for (int i = 0; i < enemyVec.size(); i++)
        {
            enemyVec.at(i)->move(clock);
        }

        //process interactions
        player.hit(enemyVec, bullet, missile);
        player.crash(enemyVec);

        //set up player sprite to print
        playerSprite.setPosition(player.getPosition().x, player.getPosition().y);

        // Clear the whole window before rendering a new frame
        window.clear();

        //Draw some graphical entities
        for (int i = 0; i < TOTAL_BULLETS; i++)
           window.draw(bullet[i]);
        for (int i = 0; i < 2; i++)
            window.draw(missile[i]);
        for (int i = 0; i < enemyVec.size(); i++)
        {
            enemyVec.at(i)->print(window);
            //get rid of off screen enemies
            if (enemyVec.at(i)->getPosition().x < 0)
            {
                delete enemyVec.at(i);
                for (int j = i + 1; j < enemyVec.size(); j++)
                {
                    enemyVec.at(j - 1) = enemyVec.at(j);
                }
                enemyVec.pop_back();

            }
        }
        window.draw(playerSprite);

        // End the current frame and display its contents on screen
        window.display();
    }

    //clean up
    for (int i = enemyVec.size() - 1; i >= 0; i--)
    {
        delete enemyVec.at(i);
    }

}
