//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "Block.h"
#include <iostream>

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

void Block::DrawBlock(){
    glLoadIdentity();
    glPushMatrix();
    glColor3f(x/800.0, (1-x/800.0), 1.0); //color provisiorio mientras se ponen texturas
    glTranslatef(x, y, 0);
    //glTranslatef(700.0, 350.0, 0);
    glutSolidCube(GLULUCAT_BLOCK_SIZE);
    glPopMatrix();
}
