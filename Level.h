//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "Block.h"
#include "YarnBall.h"

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

#define GLULUCAT_NOTHING 0
#define GLULUCAT_BLOCK 1
#define GLULUCAT_YARNBALL 2

using namespace std;


class Level {

    int width;
    int height;


public:
    Level();
    //~Level();
    Level(int, int);
    Level(int, int, std::vector<Block>);
    void AddBlock(Block);
    void DrawLevel();
    void DrawBlock(int, int);
    void DrawYarnBall(int, int);
    std::vector<Block> blocks;
    std::vector<YarnBall> yarnballs;
    int levelMap[160][120];
};

#endif /* defined(__Glulucat__Level__) */
