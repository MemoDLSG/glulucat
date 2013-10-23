//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "Block.h"

Block::Block () {
    x = 0;
    y = 0;
    type = BLOCK_BREAKABLE;
}

Block::Block (int px, int py, blockType ptype, blockItem pitem) {
    x = px;
    y = py;
    type = ptype;
    item = pitem;
}

blockType Block::getType () {
    return type;
}

blockItem Block::getItem () {
    return item;
}

void Block::setType(blockType ptype){
    this->type = ptype;
}