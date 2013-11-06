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
#include "Block.h"

using namespace std;

class Character {

    bool powerup;
    bool flicking;

public:
    int x_speed;
    int y_speed;
    bool jumping;

    Character();
    //~Character();
    void displayCharacter();
    bool isJumping(bool);
    int MoveX(int, vector<Block>);
    int moveY(int);

    int jump(int);
    void Fall(vector<Block>);

protected:
    int x;
    int y;
    int z;

private:

};

#endif
