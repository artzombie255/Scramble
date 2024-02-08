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
    sf::RectangleShape bullet[4];
    
    for (int i = 0; i < 4; i++)
    {
        bullet[i].setSize(sf::Vector2f(5, 5));
        bullet[i].setOrigin(0, 0);
    }

    window.setFramerateLimit(60);


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

        }

        player.move(bullet);
        // Clear the whole window before rendering a new frame
        window.clear();

        // Draw some graphical entities
        window.draw(player);
        for (int i = 0; i < 4; i++)
           window.draw(bullet[i]);
        // End the current frame and display its contents on screen
        window.display();
    }

}
