//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#ifndef __Glulucat__Block__
#define __Glulucat__Block__

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#define GLULUCAT_BLOCK_SIZE 50

enum blockType {
     BLOCK_BREAKABLE = 10000,
     BLOCK_UNBREAKABLE = 10001,
     BLOCK_POWERUP = 10002
   };

enum blockItem {
     BLOCK_NOITEM = 20000,
     BLOCK_CAMERA = 20001,
     BLOCK_YARN = 20002
   };


class Block {

public:

    Block();
    Block(int, int, blockType, blockItem);
//    ~Block();
    int getX();
    int getY();
    blockType getType();
    blockItem getItem();
    void setX(int x);
    void setY(int y);
    void setType(blockType type);
    void setItem(blockItem item);
    void hitBlock();
    void DrawBlock();
    int x;
    int y;

private:

    blockType type;
    blockItem item;
};

#endif /* defined(__Glulucat__Block__) */

