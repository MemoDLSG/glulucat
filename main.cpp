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
#include <fstream>
#include "Glulucat.h"
#include "Block.h"
#include "Level.h"
#include "Duck.h"
#include "YarnBall.h"
#include "Screen.h"
#include "Materials.h"


Glulucat glulucat;
Level level;
Screen screen;
std::vector<Duck> ducks;
std::vector<string> scores;
string currentLevel;
Materials materials;

bool pause;

enum e_states { START, CREDITS, PLAYING, SCORES, GAMEOVER, WINNERISYOU } state;

std::vector<string> readScores() {
    std::vector<string> lines;
    std::ifstream text_lines("scores.txt");

    if(text_lines.is_open()){
        std::string line;
        while(getline(text_lines, line) ){
            lines.push_back(line);
        }
    }
    return lines;
}

void startDefault(){
    while (!ducks.empty()){
        ducks.pop_back();
    }
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
    int x, y;
    Duck duck;
    level.yarnBalls = 0;
    while (!ducks.empty()){
        ducks.pop_back();
    }
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
                    case '2':
                        level.yarnBalls++;
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

/*
 * Limpia el fondo e inicializa lo necesario
 */
void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    currentLevel = "level1.txt";
    pause = false;
    state = START;

    scores = readScores();

    screen = Screen();
    startLevel(currentLevel);
}

void timer(int una_vars) {

    if(glulucat.dead){
        startLevel(currentLevel);
    }

    if(glulucat.lives < 1) {
        state = GAMEOVER;
    }

    if(!pause && state == PLAYING) {
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
    	if(glulucat.flicking > 0){
            glulucat.flicking--;
    	}else{
            glulucat.bumpDucks(ducks);
    	}

    	//WINNING CONDITION
    	if(level.yarnBalls == 0 && ducks.empty()){
            //cout << "A WINNER IS YOU!" << endl;
            state = WINNERISYOU;
    	}
	}
    glutPostRedisplay();

    glutTimerFunc(25,timer,0);
}

void initializeLight(){
    glEnable(GL_LIGHT0);
    GLfloat diffuse[ ] = {1.0, 1.0, 1.0, 1.0};
    GLfloat ambient[ ] = {1.0, 1.0, 1.0, 1.0};
    GLfloat specular[ ] = {1.0, 1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    GLfloat position[] = {400, 300, 20, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glEnable(GL_LIGHT1);

    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular);

    glLightfv(GL_LIGHT1, GL_POSITION, position);
}

/**
 * Manda a pintar el nivel y todo lo demas
 **/
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt (400, 300, 50, 400, 300, 0.0, 0.0, 1.0, 0.0);

    switch (state) {
        case START:
            //std::cout << "Start this $#¡+" << std::endl;
            screen.DrawStartScreen();
            break;

        case CREDITS:
            screen.DrawCredits();
            break;

        case SCORES:
            screen.DrawScores(scores);
            break;

        case GAMEOVER:
            screen.DrawGameOver();
            break;

        case WINNERISYOU:
            screen.DrawWinnerIsYOU();
            break;

        case PLAYING:
            glEnable(GL_LIGHTING);
            initializeLight();
            materials.setMaterial(8);
            level.DrawLevel();
            materials.setMaterial(2);
            glulucat.displayMetadata();
            materials.setMaterial(10);
            glulucat.displayCharacter();
            for(std::vector<Duck>::iterator it = ducks.begin() ; it != ducks.end(); ++it) {
                it->displayCharacter();
            }
            glDisable(GL_LIGHTING);
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
            if(state == PLAYING) pause = !pause;
            else pause = false;
            break;
        case 1: case 2:
            state = PLAYING;
            break;
        case 100:
            state = START;
            pause = false;
            break;
        case 101:
            state = CREDITS;
            pause = false;
            break;
        case 102:
            state = SCORES;
            pause = false;
            break;
        case 103:
            state = GAMEOVER;
            pause = false;
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
                if (state == PLAYING) {
                    glulucat.isOnAir(false);
                } else if (state == GAMEOVER) {
                    exit(0);
                } else if (state == SCORES || state == CREDITS) {
                    state = START;
                }

                break;

            case 'M': case 'm':
                if (state == GAMEOVER) {
                    state = START;
                    glulucat.lives = 3;
                }
                break;

            case 'N': case 'n':
                if (state == START) {
                    state = PLAYING;
                    glulucat.lives = 3;
                    startLevel(currentLevel);
                }
                break;
            case 'C': case 'c':
                if (state != GAMEOVER && state != PLAYING
                    && state != SCORES) {
                    state = CREDITS;
                }
                break;
            case 'P': case 'p':
                if (state == START) {
                    state = SCORES;
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
