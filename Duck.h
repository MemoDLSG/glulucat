//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "Character.h"
#include "Block.h"

#ifndef __Glulucat__Duck__
#define __Glulucat__Duck__

#include <iostream>


class Duck: public Character {

public:
    Duck();
    Duck(int, int);
    int name;
    bool facing_right;
    void displayCharacter();
    void bumpDucks(vector<Duck>&);
    void bumpedLeft(vector<Duck>&, vector<Duck>::iterator);
    void bumpedRight(vector<Duck>&, vector<Duck>::iterator);
    void bumpedDown(vector<Duck>&, vector<Duck>::iterator);
    void bumpedUp(vector<Duck>&, vector<Duck>::iterator);

};

#endif /* defined(__Glulucat__Duck__) */
