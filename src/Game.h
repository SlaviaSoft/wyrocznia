#pragma once
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <math.h>
#include "Console.h"
#include <SFML/Graphics.hpp>

#define WIDTH 1280
#define HEIGHT 720

#ifdef _WIN32
  #include<windows.h>
#endif

#define MAX_FPS 100


//main game class
class Game
{
public:
  int fps;

  sf::RenderWindow window;

  sf::Clock FPSclock;
  sf::Clock blinkingCursorClock;

  sf::Time FPStime;

  sf::RectangleShape* consoleShape;
  sf::RectangleShape* consoleInputShape;
  sf::Sprite bgImg;
  sf::Texture bgImgTexture;

  sf::Font arial;
  sf::Text* inputText;

  Game();
  void render();

  static void timer(int flag);

  void consoleInput();
  void setBgImage(std::string);
  void calculateFPS();
  void writeText(int key);
  void keyPressed(sf::Keyboard::Key key);
};
