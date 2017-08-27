#include <stdlib.h>
#include "Game.h"
#include "Console.h"
#include <iostream>
#include <SFML/Graphics.hpp>

 #ifdef _WIN32
   #include<windows.h>
 #endif

Game *game;

Console *console = new Console();



int main()
{
  game = new Game();

  int scene;

  //GAME LOOP
  while (game->window.isOpen())
  {
      sf::Event event;
      while (game->window.pollEvent(event))
      {
        switch (event.type)
          {
            case sf::Event::Closed:
                game->window.close();
                break;
            case sf::Event::TextEntered:
                game->writeText(event.text.unicode);
                break;
            case sf::Event::KeyPressed:
                game->keyPressed(event.key.code);
            default:
                break;
          }
      }

      //game->calculateFPS();

      game->window.clear();
      game->render();
      game->window.display();


  }

  return 0;
}
