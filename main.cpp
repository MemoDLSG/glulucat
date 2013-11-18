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


Glulucat glulucat;
Level level;
std::vector<Duck> ducks;


/*
* Limpia el fondo
*/
void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);

    glulucat = Glulucat();

    for(int i = 0; i < 3; i++) {
        Duck duck = Duck(200+i*150, GLULUCAT_BLOCK_SIZE*1.5);
        duck.name = i;
        ducks.push_back(duck);
    }
    Duck duck = Duck(350, GLULUCAT_BLOCK_SIZE*5.5);
    ducks.push_back(duck);

}

void timer(int una_vars){

    glulucat.moveY(level);
    int i = 0;

    for(int i=0; i<ducks.size(); i++){
        Duck thisDuck = ducks.at(i);
        thisDuck.moveY(level);
        thisDuck.moveX(level);
        ducks.erase(ducks.begin()+i);
        thisDuck.bumpDucks(ducks);
        ducks.insert(ducks.begin()+i, thisDuck);
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
    level.DrawLevel();
    glulucat.displayCharacter();
    for(std::vector<Duck>::iterator it = ducks.begin() ; it != ducks.end(); ++it) {
        it->displayCharacter();
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

void keyboard (unsigned char key, int x, int y) {
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

        case 27:
            exit(0);
            break;

        default:
            break;
    }
    glutPostRedisplay();
}


int main (int argc, char** argv) {

    std::cout << "Hello Glulucat!!!" << std::endl;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(25, timer, 1);
    glutMainLoop();

    return 0;

}
