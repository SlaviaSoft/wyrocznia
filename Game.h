#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <math.h>
#include "FpsTimer.h"
#include<windows.h>

#define MAX_FPS 100

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
//
//main game class
class Game
{
public:
  //this variable control blinking of cursor in user console input
  float blinkTextCursor;
  int fps;
  int drawStartTime, drawEndTime, delayToNextFrame;

  Game();
  void init();
  void render();

  FpsTimer* fpsTimer;

  static void timer(int flag);

  void printText(std::string text,Vector3f color, Vector3f position);
  void drawConsole();
  void consoleInput();

  //callbacks
  static void keybord(unsigned char key, int x, int y);
    static void keySpecial (int key, int x, int y);
};
