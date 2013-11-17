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
    
    int moveX(int, std::vector<Block>);
    void displayCharacter();
    
};

#endif /* defined(__Glulucat__Duck__) */
