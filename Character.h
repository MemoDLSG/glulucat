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

class Character {

    bool powerup;
    bool flicking;

public:
    int x_speed;
    int y_speed;

    Character();
    //~Character();
    void displayCharacter();
    bool jump(bool);
    int moveX(int);
    int moveY(int);

protected:
    int x;
    int y;
    int z;
    bool jumping;

private:

};

#endif
