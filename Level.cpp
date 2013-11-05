//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "Block.h"
#include "Level.h"

Level::Level(void){
    width = 800;
    height = 600;

    blocks.push_back(Block(GLULUCAT_BLOCK_SIZE/2+600, GLULUCAT_BLOCK_SIZE*1.5, BLOCK_UNBREAKABLE, BLOCK_NOITEM));

    for(int i=0; i<16; i++){
        blocks.push_back(Block(GLULUCAT_BLOCK_SIZE/2+i*GLULUCAT_BLOCK_SIZE, GLULUCAT_BLOCK_SIZE/2, BLOCK_UNBREAKABLE, BLOCK_NOITEM));
    }

    for(int i=0; i<3; i++){
        blocks.push_back(Block(175+i*GLULUCAT_BLOCK_SIZE, 125, BLOCK_UNBREAKABLE, BLOCK_NOITEM));
    }
}

Level::Level(int pwidth, int pheight){
    width = pwidth;
    height = pheight;
}

Level::Level(int pwidth, int pheight, std::vector<Block> pblocks ){
    width = pwidth;
    height = pheight;
    blocks = pblocks;
}

void Level::AddBlock(Block block){
    blocks.push_back(block);
}

void Level::DrawLevel(){
    for (std::vector<Block>::iterator it = blocks.begin() ; it != blocks.end(); ++it){
        (*it).DrawBlock();
    }
}
