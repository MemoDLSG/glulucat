//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "Level.h"

Level::Level(void){
    width = 800;
    height = 600;
    blocks = std::vector<Block> (0);
    
}

Level::Level(int pwidth, int pheight, std::vector<Block> pblocks){
    width = pwidth;
    height = pheight;
    blocks = pblocks;
    
}
