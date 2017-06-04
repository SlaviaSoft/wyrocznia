#include "Game.h"

Game::Game(){

};

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
};

void Game::render(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  printText("Simple text",Vector3f(0.8,0.8,0.8));
  drawConsole();

}

void Game::drawConsole(){
  glColor3f(0.1,0.1,0.1);
  glBegin(GL_POLYGON);
		glVertex3f(-0.8,-0.8,0.0);
		glVertex3f(-0.8,0.8,0.0);
		glVertex3f(0.8,0.8,0.0);
		glVertex3f(0.8,-0.8,0.0);
	glEnd();
}

void Game::printText(std::string text,Vector3f color){

  //convert string to char
  char text2[text.length()];
  strcpy(text2, text.c_str());
  //set text color
  glColor3f(color.x,color.y,color.z);

  // Position of the text to be print
  glRasterPos3f(-0.78, 0.7, 0);

  //print text
  for(int i = 0; text2[i] != '\0'; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text2[i]);
};
