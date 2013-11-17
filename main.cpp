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


Glulucat glulucat;
Level level;
std::vector<Duck> ducks;

bool pause;

/*
* Limpia el fondo
*/
void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    
    glulucat = Glulucat();
    
    for(int i = 0; i < 5; i++) {
        Duck duck = Duck();
        ducks.push_back(duck);
    }
    
    pause = false;
}

void timer(int una_vars) {

    if(!pause) {
        glulucat.moveY(level.blocks);
        int i = 0;
        for(std::vector<Duck>::iterator it = ducks.begin(); it != ducks.end(); ++it, i++ ) {
            it->moveY(level.blocks);
            it->moveX(i, level.blocks);
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

void processMenu(int option){
    switch (option) {
        case 1:
            
            break;
        case 99:
            pause = !pause;
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
    glutAddMenuEntry("Opcion randy", 1);
    glutAddMenuEntry("Locura!", 2);
    
    mainMenu = glutCreateMenu(processMenu);
    glutAddSubMenu("Niveles", levels);
    glutAddMenuEntry("Pausa", 99);
    glutAddSubMenu("Otros", others);
    
    // Let the menu respond on the right mouse button
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
}

void keyboard (unsigned char key, int x, int y) {
    if(!pause) {
        switch (key) {
            case 'A': case 'a':
                glulucat.moveX(-10, level.blocks);

                break;

            case 'D': case 'd':
                glulucat.moveX(10, level.blocks);

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
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    
    switch (button) {
        case GLUT_LEFT_BUTTON:
            
            break;
            
        case GLUT_RIGHT_BUTTON:
            if(state == GLUT_UP){

            }
            break;
    }
}

int main (int argc, char** argv) {

    std::cout << "Hello Glulucat!!!" << std::endl;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Glulucat: The almighty cat");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    createMenu();
    glutTimerFunc(25, timer, 1);
    glutMainLoop();

    return 0;

}
