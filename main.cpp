#include "FpsTimer.h"
 #include <stdlib.h>
 #include <GL/gl.h>
 #include <GL/glut.h>
 #include "Game.h"
 #include "Console.h"
 #include<windows.h>
 #include <iostream>

//create game object
Game *game = new Game();

Console *console = new Console();

void renderScene() {
    game->render();
}


int main(int argc, char **argv) {

	// init GLUT and create Window
  glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(1280,720);
	glutCreateWindow("Wyrocznia");

	game->init();

  // register callbacks
	glutDisplayFunc(renderScene);
	glutKeyboardFunc(Game::keybord);
	glutSpecialFunc(Game::keySpecial);

  // enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}
