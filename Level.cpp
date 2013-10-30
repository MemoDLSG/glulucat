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

    for(int i=0; i<8; i++){
        blocks.push_back(Block(50+i*100, 50, BLOCK_UNBREAKABLE, BLOCK_NOITEM));
    }

    for(int i=0; i<3; i++){
        blocks.push_back(Block(350+i*100, 250, BLOCK_UNBREAKABLE, BLOCK_NOITEM));
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
