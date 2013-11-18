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

#define GLULUCAT_YARN_SCORE 100


class Glulucat: public Character {


public:
    int lives;
    int score;

    Glulucat(void);
    void displayCharacter(void);
    void displayMetadata(void);
    void collectYarn(Level&);

};

#endif /* defined(__Glulucat__Glulucat__) */
