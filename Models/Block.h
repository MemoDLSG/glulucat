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

#include <iostream>

#endif /* defined(__Glulucat__Block__) */

class Block {
  
    int x;
    int y;
    int type; //0 breakable, 1 unbreakable, 3 powerup
public:
    Block();
    Block(int, int, int);
};

