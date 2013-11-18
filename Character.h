//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#ifndef Glulucat_character_h
#define Glulucat_character_h

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include <vector>
#include <tgmath.h>
#include "Block.h"

#define GLULUCAT_NOTHING 0
#define GLULUCAT_BLOCK 1
#define GLULUCAT_YARN 2
//#include "Level.h"

using namespace std;

class Character {

    bool powerup;

public:
    int x_speed;
    int y_speed;
    bool on_air;

    Character();
    //~Character();
    void displayCharacter();
    bool isOnAir(bool);
    void startJumping();
    void jump(vector<Block>);
    int moveY(int[][12]);
    int moveX(int[][12]);

    int x;
    int y;
    int z;

private:

};

#endif
