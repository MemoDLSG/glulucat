//
//  main.cpp
//  Glulucat
//
//  Created by
//      Guillermo de lo Santos
//      David Tovar Goris
//  on 10/16/13.
//  Copyright (c) 2013 Glulucat. All rights reserved and meowed.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <windows.h>
#endif

#include <iostream>
#include "Glulucat.h"
#include "Block.h"
#include "Level.h"
#include "Duck.h"


Glulucat glulucat;
Level level;
std::vector<Duck> ducks;


/*
* Limpia el fondo
*/
void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}



void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt (0.0, 3.0, 5.0, 0.0, 0.0, 0.0, 0.0, 3.0, 0.0);
    glScalef (1.0, 2.0, 1.0);
    glulucat.displayCharacter();
    glutSwapBuffers();
    
}


void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}


void keyboard (unsigned char key, int x, int y) {
    switch (key) {
        case 'A': case 'a':
            glulucat.moveX(-1);
            glutPostRedisplay();
            
            break;
        
        case 'D': case 'd':
            glulucat.moveX(1);
            glutPostRedisplay();
            break;
        
        default:
            break;
    }
}


int main (int argc, char** argv) {
    
    std::cout << "Hello World!!!" << std::endl;
    
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;

}