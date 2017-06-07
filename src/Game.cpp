#include "Game.h"

extern Game*game;

extern Console*console;

Game::Game(){
  blinkTextCursor = 0;
  fps=0;
  fpsTimer = new FpsTimer(100);
};
//
void Game::init(){
  //settings
  glClearColor( 0.8, 0.8, 0.8, 1);
  glClearDepth( 1.0 );
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_LIGHT0);
}

void Game::keybord(unsigned char key, int x, int y){

    switch(key)
    {
    //close window when click esc
    case 27:
        exit(0);
    }
    glutPostRedisplay();

    if((key>=32 && key<=126) || key == 8 || key == 13)
    {
        console->keybuffer = key;
        console->linecreator();
    }

};

void Game::keySpecial(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
        console->up();
        break;
        case GLUT_KEY_DOWN:
        console->down();
        break;
        case GLUT_KEY_LEFT:
        //do something here
        break;
        case GLUT_KEY_RIGHT:
        //do something here
        break;
    }

}

//..............................................................................

void Game::render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    printText("Simple text",Vector3f(0.8,0.8,0.8), Vector3f(-0.78, 0.7, 0));
    consoleInput();
    drawConsole();

    //display fps
    fpsTimer->timeFrame();
    printText(fpsTimer->getFps(),Vector3f(0.0,0.0,0.0), Vector3f(-0.97, 0.92, 0));

    glutSwapBuffers();
    glutPostRedisplay();
}

//..............................................................................

void Game::drawConsole(){
  glColor3f(0.1,0.1,0.1);
  glBegin(GL_POLYGON);
		glVertex3f(-0.8,-0.8,0.0);
		glVertex3f(-0.8,0.8,0.0);
		glVertex3f(0.8,0.8,0.0);
		glVertex3f(0.8,-0.8,0.0);
	glEnd();


}

void Game::consoleInput(){

  //cursor blinking
  blinkTextCursor+=0.03;
  if(blinkTextCursor>1)
    printText(console->linebuffer + "|",Vector3f(0.8,0.8,0.8),Vector3f(-0.78,-0.75,0));
  else
    printText(console->linebuffer,Vector3f(0.8,0.8,0.8),Vector3f(-0.78,-0.75,0));

  if(blinkTextCursor>2)
    blinkTextCursor=0;

    //console output
    //printText(console->linebuffer,Vector3f(0.0,0.0,0.0),Vector3f(-0.78, -0.75, 0));

  //draw console input area
  glColor3f(0.3,0.3,0.3);
  glBegin(GL_POLYGON);
		glVertex3f(-0.8,-0.8,0.0);
		glVertex3f(-0.8,-0.68,0.0);
		glVertex3f(0.8,-0.68,0.0);
		glVertex3f(0.8,-0.8,0.0);
	glEnd();


}

void Game::printText(std::string text,Vector3f color, Vector3f position){

  //convert string to char
  char text2[text.length()];
  strcpy(text2, text.c_str());
  //set text color
  glColor3f(color.x,color.y,color.z);

  // Position of the text to be print
  glRasterPos3f(position.x,position.y,position.z);

  //print text
  for(int i = 0; text2[i] != '\0'; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text2[i]);
};

//
//FPS timer
void Game::timer(int flag) {
    game->drawStartTime = clock();
    glutPostRedisplay();
    game->drawEndTime = clock();

    game->delayToNextFrame =  (CLOCKS_PER_SEC/MAX_FPS) - (game->drawEndTime-game->drawStartTime);
    game->delayToNextFrame = floor(game->delayToNextFrame+0.5);
    (game->delayToNextFrame < 0) ? game->delayToNextFrame = 0 : 0;

    glutTimerFunc(game->delayToNextFrame, game->timer, 0);
}
