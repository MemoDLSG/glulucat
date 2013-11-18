//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#ifndef __Glulucat__Level__
#define __Glulucat__Level__

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//class Glulucat;
//class Duck;
//#include "Glulucat.h"
//#include "Duck.h"

#define GLULUCAT_NOTHING 0
#define GLULUCAT_BLOCK 1
#define GLULUCAT_YARN 2
#define GLULUCAT_CAMERA 3

using namespace std;


class Level {
public:
    int width;
    int height;
    int levelMap[16][12];
    int yarnBalls;
    //Glulucat glulucat;
    //vector<Duck> ducks;

    Level();
    Level(string);
    void DrawLevel();
    void UpdateCell(int, int, int);
    void DrawBlock(int, int);
    void DrawYarn(int, int);
    void DrawCamera(int, int);
    void PrintLevel();
    void Start(string);
    void StartDefault();
};

#endif /* defined(__Glulucat__Level__) */
