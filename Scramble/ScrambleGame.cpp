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
    sf::RenderWindow window(sf::VideoMode(800, 600), "Scramble");
	Player player;
    sf::RectangleShape bullet[4], missile[2];
    std::vector<Enemy*> enemyVec;
    sf::Clock clock, playerSpriteClock;
    sf::Sprite playerSprite, rocketSprite;
    sf::Texture tempI;
    sf::Shader test;
    int frame = 0;
    
    srand(time(NULL));

    //test.loadFromFile("Shader_colour_swap.frag", sf::Shader::Fragment);
    //test.setUniform("COLOR", sf::Glsl::Vec4());
    //test.setUniform("TEXTURE", sf::Shader::CurrentTexture);
    //test.setUniform("UV", sf::Glsl::Vec4());
    //sf::Shader::bind(&test);
    //tempI.loadFromFile("rocketEnemy.png");
    player.changeSprite(playerSpriteClock, playerSprite);
    //rocketSprite.setTexture(tempI);
    //rocketSprite.scale(5, 5);


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
  

    while (window.isOpen())
    {
        // Event processing
        sf::Event e;
        while (window.pollEvent(e))
        {
            // Request for closing the window
            if (e.type == sf::Event::Closed)
                window.close();

            player.moveCheck();
            player.shootBlaster(bullet);
            player.shootMissiles(missile);
        }

        player.changeSprite(playerSpriteClock, playerSprite);
        player.move(bullet, missile);
        for (int i = 0; i < enemyVec.size(); i++)
        {
            enemyVec.at(i)->move(clock);
        }
        player.hit(enemyVec, bullet, missile);
        player.crash(enemyVec);
        playerSprite.setPosition(player.getPosition().x, player.getPosition().y);
        // Clear the whole window before rendering a new frame
        window.clear();
        // Draw some graphical entities
        window.draw(rocketSprite);
        window.draw(playerSprite);
        for (int i = 0; i < TOTAL_BULLETS; i++)
           window.draw(bullet[i]);
        for (int i = 0; i < 2; i++)
            window.draw(missile[i]);
        for (int i = 0; i < enemyVec.size(); i++)
        {
            enemyVec.at(i)->print(window);
            if (enemyVec.at(i)->getPosition().x < -30)
            {
                delete enemyVec.at(i);
                for (int j = i + 1; j < enemyVec.size(); j++)
                {
                    enemyVec.at(j - 1) = enemyVec.at(j);
                }
                enemyVec.pop_back();

            }
        }
        // End the current frame and display its contents on screen
        window.display();
    }

    for (int i = enemyVec.size() - 1; i >= 0; i--)
    {
        delete enemyVec.at(i);
    }

}
