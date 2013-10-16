//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#ifndef __Glulucat__Level__
#define __Glulucat__Level__

#include <iostream>
#include <vector>
#include "Block.h"

#endif /* defined(__Glulucat__Level__) */

class Level {
    
    int width;
    int height;
    std::vector<Block> blocks;
    
public:
    Level();
    Level(int, int, std::vector<Block>);
    
    void addBlockToVector(Block block);
    
};