//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include <iostream>
#include "Glulucat.h"
#include "Block.h"
#include "Level.h"
#include "Duck.h"
#include "YarnBall.h"
#include "StartScreen.h"


Glulucat glulucat;
Level level;
StartScreen start_screen;
std::vector<Duck> ducks;

bool pause;

enum current_screen { START, CREDITS, PLAYING, SCORES, GAMEOVER } screen;

/*
* Limpia el fondo
*/
void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    
    pause = false;
    screen = START;
    
    start_screen = StartScreen();

    for(int i = 0; i < 3; i++) {
        Duck duck = Duck(200+i*150, GLULUCAT_BLOCK_SIZE*1.5);
        duck.name = i;
        ducks.push_back(duck);
    }
    Duck duck = Duck(350, GLULUCAT_BLOCK_SIZE*5.5);
    ducks.push_back(duck);

}

void timer(int una_vars) {

    if(!pause && screen == PLAYING) {
    	glulucat.moveY(level);
    	
    	for(int i=0; i<ducks.size(); i++){
        	Duck thisDuck = ducks.at(i);
        	thisDuck.moveY(level);
   	    	thisDuck.moveX(level);
   	    	ducks.erase(ducks.begin()+i);
   	    	thisDuck.bumpDucks(ducks);
    	    ducks.insert(ducks.begin()+i, thisDuck);
    	}
	}
    glutPostRedisplay();
    
    glutTimerFunc(25,timer,0);
}

/**
 * Manda a pintar el nivel y todo lo demas
 **/
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt (400, 300, 50, 400, 300, 0.0, 0.0, 1.0, 0.0);
    
    switch (screen) {
        case START:
            //std::cout << "Start this $#¡+" << std::endl;
            start_screen.DrawScreen();
            break;
            
        case CREDITS:
            
            break;
            
        case SCORES:
            
            break;
            
        case GAMEOVER:
            
            break;
            
        case PLAYING:
            level.DrawLevel();
            glulucat.displayCharacter();
            glulucat.displayMetadata();
            for(std::vector<Duck>::iterator it = ducks.begin() ; it != ducks.end(); ++it) {
                it->displayCharacter();
            }
            break;
            
        default:
            break;
    }
    

    glutSwapBuffers();

}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glOrtho(0, 800, 0, 600, 0, 100);
    glMatrixMode(GL_MODELVIEW);
}

void processMenu(int option){
    std::cout << option << std::endl;
    switch (option) {
        case 0:
            pause = !pause;
            break;
        case 1: case 2:
            screen = PLAYING;
            break;
        case 100:
            screen = START;
            break;
        case 101:
            screen = CREDITS;
            break;
        case 102:
            screen = SCORES;
            break;

        default:
            break;
    }
}

void createMenu (void){
    int mainMenu, levels, others;
    
    levels = glutCreateMenu(processMenu);
    glutAddMenuEntry("Level 1", 1);
    glutAddMenuEntry("Level 2", 2);
    
    others = glutCreateMenu(processMenu);
    glutAddMenuEntry("Pantalla Inicio", 100);
    glutAddMenuEntry("Créditos", 101);
    glutAddMenuEntry("Puntajes", 102);

    
    mainMenu = glutCreateMenu(processMenu);
    glutAddSubMenu("Niveles", levels);
    glutAddMenuEntry("Pausa", 0);
    glutAddSubMenu("Ir a ", others);
    
    // Let the menu respond on the right mouse button
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
}

void keyboard (unsigned char key, int x, int y) {
    if(!pause) {
        switch (key) {
	        case 'A': case 'a':
    	        glulucat.x_speed = -10;
        	    glulucat.moveX(level);
                break;

       	 	case 'D': case 'd':
        	    glulucat.x_speed = 10;
            	glulucat.moveX(level);
                break;

            case 'W': case 'w':
                glulucat.startJumping();

                break;

            case 'S': case 's':
                glulucat.isOnAir(false);

                break;
                
            case 'N': case 'n':
                if (screen == START || screen == GAMEOVER) {
                    screen = PLAYING;
                }
                break;

            case 27:
                exit(0);
                break;

            default:
                break;
        }
    }
    glutPostRedisplay();
}

int main (int argc, char** argv) {

    std::cout << "Hello Glulucat!!!" << std::endl;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Glulucat: The almighty cat");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    createMenu();
    glutTimerFunc(25, timer, 1);
    glutMainLoop();

    return 0;

}
