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
string currentLevel;

bool pause;

enum current_screen { START, CREDITS, PLAYING } screen;

void startDefault(){
    for(int i = 0; i < 3; i++) {
        Duck duck = Duck(150, GLULUCAT_BLOCK_SIZE*(i+1.5));
        duck.name = i;
        ducks.push_back(duck);
    }
    level.StartDefault();
}

void startLevel(string file){
    ifstream layout (file.c_str());
    string line;
    int x, y, i = 0;
    Duck duck;
    if (layout.is_open()){
        getline(layout, line);
        level.width = atoi(line.c_str());

        getline(layout, line);
        level.height = atoi(line.c_str());

        for(int j=(level.height-1); j>=0; j--){
            getline(layout, line);
            for(int i=0; i<level.width; i++){
                switch (line.at(i)){
                    case 'G':
                        x = (i+0.5)*GLULUCAT_BLOCK_SIZE;
                        y = (j+0.5)*GLULUCAT_BLOCK_SIZE;
                        glulucat = Glulucat(x, y, glulucat.lives); //FOREVEEEEEEEERRRRRR!!!!!!!!111!11!1
                        break;
                    case 'D':
                        x = (i+0.5)*GLULUCAT_BLOCK_SIZE;
                        y = (j+0.5)*GLULUCAT_BLOCK_SIZE;
                        duck = Duck(x, y);
                        ducks.push_back(duck);
                        break;
                    default:
                        level.levelMap[i][j] = line.at(i) - '0';
                        break;
                }
            }
        }
        layout.close();
    }

    else{
        cout << "Unable to open file" << endl;
        startDefault();
    }
}

void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    currentLevel = "C:\\Users\\Memo\\Documents\\GitHub\\glulucat\\level1.txt";
    pause = false;
    startLevel(currentLevel);

}

void timer(int una_vars) {

    if(glulucat.dead){
        while (!ducks.empty()){
            ducks.pop_back();
        }
        startLevel(currentLevel);
    }

    if(!pause) {
    	glulucat.moveY(level.levelMap);
    	glulucat.collectYarn(level);

    	for(int i=0; i<ducks.size(); i++){
        	Duck thisDuck = ducks.at(i);
        	thisDuck.moveY(level.levelMap);
   	    	thisDuck.moveX(level.levelMap);
   	    	ducks.erase(ducks.begin()+i);
   	    	thisDuck.bumpDucks(ducks);
    	    ducks.insert(ducks.begin()+i, thisDuck);
    	}
    	glulucat.bumpDucks(ducks);
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
    glulucat.displayMetadata();
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
    glutAddMenuEntry("Opcion randy", 3);
    glutAddMenuEntry("Locura!", 4);

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
    	        glulucat.x_speed = -10;
        	    glulucat.moveX(level.levelMap);
                break;

       	 	case 'D': case 'd':
        	    glulucat.x_speed = 10;
            	glulucat.moveX(level.levelMap);
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
    createMenu();
    glutTimerFunc(25, timer, 1);
    glutMainLoop();

    return 0;

}
