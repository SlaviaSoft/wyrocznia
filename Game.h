#pragma once
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <math.h>
#include "Console.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


#define WIDTH 1280
#define HEIGHT 720

#ifdef _WIN32
  #include<windows.h>
#endif

#define MAX_FPS 100

//Najważniejszy nie jest cel lecz droga do niego
//omphalos
//main game class
class Game
{
private:
  bool ifDisplayLogo;
  bool ifFadeIn;
public:
  int fps;
  int scene;
  int displayTextLine;
  std::string command;

  sf::RenderWindow window;

  sf::Clock FPSclock;
  sf::Clock blinkingCursorClock;
  sf::Clock LogoClock;
  sf::Clock fadeClock;
  sf::Clock displayTextClock;

  sf::Time FPStime;

  sf::RectangleShape* consoleShape;
  //sf::RectangleShape* consoleInputShape;
  sf::RectangleShape* fadeRect;
  sf::Sprite bgImg;
  sf::Texture bgImgTexture;

  sf::Font arial;
  sf::Font* obelix;

  sf::Text* inputText;
  sf::Text* mainText;
  //wyrocznia logo
  std::vector<sf::Text> logo;

  Game();
  void render();

  static void timer(int flag);

  void displayLogo();
  void fadeIn();
  void consoleInput();
  void setBgImage(std::string);
  void calculateFPS();
  void writeText(int key);
  void keyPressed(sf::Keyboard::Key key);
  void displayText(std::string text, int speed, int end);
  void executor(std::string command,int mode);


};
