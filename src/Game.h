#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include <string.h>

//usful class
class Vector3f
{
public:
  float x,y,z;
  Vector3f(float x1, float y1, float z1){
    x=x1;
    y=y1;
    z=z1;
  };
};

//main game class
class Game
{
public:
  Game();
  void init();
  void render();

  void printText(std::string text,Vector3f color);
  void drawConsole();


  //callbacks
  static void keybord(unsigned char key, int x, int y);
};
