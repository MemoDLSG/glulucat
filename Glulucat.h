//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//
#include "Character.h"

#ifndef __Glulucat__Glulucat__
#define __Glulucat__Glulucat__

#include <iostream>
#include "Duck.h"
#include "Level.h"

#define GLULUCAT_YARN_SCORE 100


class Glulucat: public Character {


public:
    int lives;
    int score;
    bool dead;

    Glulucat(void);
    Glulucat(int, int);
    Glulucat(int, int, int);
    void displayCharacter(void);
    void displayMetadata(void);
    void collectYarn(Level&);
    void bumpDucks(vector<Duck>&);
    void bumpedLeft(vector<Duck>&, vector<Duck>::iterator);
    void bumpedRight(vector<Duck>&, vector<Duck>::iterator);
    void bumpedDown(vector<Duck>&, vector<Duck>::iterator);
    void bumpedUp(vector<Duck>&, vector<Duck>::iterator);
    void die();

};

#endif /* defined(__Glulucat__Glulucat__) */
