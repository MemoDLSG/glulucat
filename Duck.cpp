//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "Duck.h"

Duck::Duck(void){
    x = 525;
    y = GLULUCAT_BLOCK_SIZE*1.5;
    z = 0;
    x_speed = 1;
    x_speed = (int) (rand() % 5) + 1;
    //x_speed = 0;
    y_speed = 0;
}

void Duck::displayCharacter(void) {
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(x, y, z);
    glutWireSphere(25, 30, 10);
    glPopMatrix();
}

int Duck::moveX(int x, std::vector<Block> blocks){
    this -> x += x_speed;
    bool touchingOnY;
    int blockUpperEdge, blockLowerEdge, characterUpperEdge, characterLowerEdge;
    int blockLeftEdge, blockRightEdge, characterLeftEdge, characterRightEdge;
    for (std::vector<Block>::iterator it = blocks.begin() ; it != blocks.end(); ++it){
        blockUpperEdge = it->y + GLULUCAT_BLOCK_SIZE/2;
        blockLowerEdge = it->y - GLULUCAT_BLOCK_SIZE/2;
        characterUpperEdge = this->y + GLULUCAT_BLOCK_SIZE/2;
        characterLowerEdge = this->y - GLULUCAT_BLOCK_SIZE/2;

        blockLeftEdge = it->x - GLULUCAT_BLOCK_SIZE/2;
        blockRightEdge = it->x + GLULUCAT_BLOCK_SIZE/2;
        characterLeftEdge = this -> x - GLULUCAT_BLOCK_SIZE/2;
        characterRightEdge = this -> x + GLULUCAT_BLOCK_SIZE/2;

        touchingOnY = (characterLowerEdge < blockUpperEdge && characterLowerEdge >= blockLowerEdge)
        || (characterUpperEdge > blockLowerEdge && characterUpperEdge <= blockUpperEdge);

        if(touchingOnY){
            //std::cout << "Estoy tocando en y" << std::endl;
            //std::cout << "Character left edge: " << characterLeftEdge << std::endl;
            //std::cout << "Character right edge: " << characterRightEdge << std::endl;
            //std::cout << "Block left edge: " << blockLeftEdge << std::endl;
            //std::cout << "Block right edge: " << blockRightEdge << std::endl;
            if(characterLeftEdge<blockRightEdge && characterLeftEdge >= blockLeftEdge){
                //std::cout << "Estoy pegando por la izquierda" << std::endl;
                this -> x = it->x + GLULUCAT_BLOCK_SIZE;
                this -> x_speed *= -1;
                break;
            }

            if(characterRightEdge>blockLeftEdge && characterRightEdge <= blockRightEdge){
                //std::cout << "Estoy pegando por la derecha" << std::endl;
                this -> x = it->x - GLULUCAT_BLOCK_SIZE;
                this -> x_speed *= -1;
                break;
            }
        }
    }

    //std::cout << "Move x: " << x << std::endl;
    return x;
}
