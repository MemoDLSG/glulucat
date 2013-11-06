//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "Character.h"
#include <iostream>

Character::Character(){
    x = 0;
    y = 0;
    z = 0;
    x_speed = 0;
    y_speed = 0;
    jumping = false;
    powerup = false;
    flicking = false;
}

void Character::displayCharacter (void) {

}

/*int Character::moveX(int x){
    this -> x += x;
    //std::cout << "Move x: " << x << std::endl;
    return x;
}*/

int Character::MoveX(int x, vector<Block> blocks){
    this -> x += x;
    bool touchingOnY;
    int blockUpperEdge, blockLowerEdge, characterUpperEdge, characterLowerEdge;
    int blockLeftEdge, blockRightEdge, characterLeftEdge, characterRightEdge;
    for (std::vector<Block>::iterator it = blocks.begin() ; it != blocks.end(); ++it){
        blockUpperEdge = it->y + GLULUCAT_BLOCK_SIZE/2;
        blockLowerEdge = it->y - GLULUCAT_BLOCK_SIZE/2;
        characterUpperEdge = y + GLULUCAT_BLOCK_SIZE/2;
        characterLowerEdge = y - GLULUCAT_BLOCK_SIZE/2;

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
                break;
            }

            if(characterRightEdge>blockLeftEdge && characterRightEdge <= blockRightEdge){
                //std::cout << "Estoy pegando por la derecha" << std::endl;
                this -> x = it->x - GLULUCAT_BLOCK_SIZE;
                break;
            }
        }
    }

    //std::cout << "Move x: " << x << std::endl;
    return x;
}

int Character::moveY(int py){
    y = y + py;
    //std::cout << "Move y: " << y << std::endl;
    return this->y;
}

bool Character::isJumping(bool jumping){
    this -> jumping = jumping;
    return jumping;
}

int Character::jump(int y) {
    /*if (y_speed <= 55 && jumping) {
        y_speed = y_speed + 5;
        this->y += y_speed;
    } else if (y_speed > 55 && jumping){
        jumping = false;
        y_speed = 0;
    } else {
        std::cout << "jump y_speed : " << y_speed << std::endl;
    }*/
    y_speed = 50;
    return this->y;
}

void Character::Fall(vector<Block> blocks) {
    bool onBlock = false;
    bool touchingOnY;
    bool touchingOnX;
    int blockUpperEdge, blockLowerEdge, characterUpperEdge, characterLowerEdge;
    int blockLeftEdge, blockRightEdge, characterLeftEdge, characterRightEdge;
    if(y_speed <= 0){
    //std::cout << "Estoy en Fall" << std::endl;
    y_speed -= 1;
    moveY(y_speed);
    for (std::vector<Block>::iterator it = blocks.begin() ; it != blocks.end(); ++it){
        blockUpperEdge = it->y + GLULUCAT_BLOCK_SIZE/2;
        blockLowerEdge = it->y - GLULUCAT_BLOCK_SIZE/2;
        characterUpperEdge = y + GLULUCAT_BLOCK_SIZE/2;
        characterLowerEdge = y - GLULUCAT_BLOCK_SIZE/2;

        blockLeftEdge = it->x - GLULUCAT_BLOCK_SIZE/2;
        blockRightEdge = it->x + GLULUCAT_BLOCK_SIZE/2;
        characterLeftEdge = x - GLULUCAT_BLOCK_SIZE/2;
        characterRightEdge = x + GLULUCAT_BLOCK_SIZE/2;

        touchingOnY = characterLowerEdge <= blockUpperEdge && characterLowerEdge >= blockLowerEdge;

        touchingOnX = (characterLeftEdge < blockRightEdge && characterLeftEdge >= blockLeftEdge)
                        || (characterRightEdge > blockLeftEdge && characterRightEdge <= blockRightEdge);

        if(touchingOnY && touchingOnX){
            onBlock = true;
            y = it->y + GLULUCAT_BLOCK_SIZE;
            y_speed = 0;
            break;
        }
    }
    }
    else{
        moveY(y_speed);
        y_speed -= 5;
    }
}
