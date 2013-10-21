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

int Block::getX () {
    return x;
}

int Block::getY () {
    return y;
}

blockType Block::getType () {
    return type;
}

blockItem Block::getItem () {
    return item;
}

void Block::setX(int x){
    this->x = x;
}

void Block::setY(int y){
    this->y = y;
}

void Block::setType(blockType type){
    this->type = type;
}

void Block::setItem(blockItem item){
    this->item = item;
}

void Block::hitBlock(){
    //TODO
    switch(item){
        //spawn the appropriate powerup above me
    }
    switch(type){
        //switch to the new type corresponding to hitting the block, or destroy itself
    }
}

void Block::drawBlock(){
    //TODO
    //OpenGL drawing functions
}
