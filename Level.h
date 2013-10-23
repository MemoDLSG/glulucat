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

#include <iostream>
#include <vector>


class Level {
    
    int width;
    int height;
    std::vector<Block> blocks;
    
public:
    Level();
    //~Level();
    Level(int, int, std::vector<Block>);
    
};

#endif /* defined(__Glulucat__Level__) */