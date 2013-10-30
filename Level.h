//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "Block.h"

#ifndef __Glulucat__Level__
#define __Glulucat__Level__

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include <iostream>
#include <vector>


class Level {

    int width;
    int height;
    std::vector<Block> blocks;

public:
    Level();
    //~Level();
    Level(int, int);
    Level(int, int, std::vector<Block>);
    void AddBlock(Block);
    void DrawLevel();
};

#endif /* defined(__Glulucat__Level__) */
