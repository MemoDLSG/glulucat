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
    on_air = true;
    powerup = false;
    flicking = false;
}

void Character::displayCharacter (void) {
    
}

int Character::moveX(int x, vector<Block> blocks){
    this -> x += x;
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

bool Character::isOnAir(bool on_air){
    this -> on_air = on_air;
    return on_air;
}

void Character::startJumping(){
    if (!on_air) {
        on_air = true;
        y_speed = GLULUCAT_BLOCK_SIZE/2;
    }
}

int Character::moveY(vector<Block> blocks) {
    bool touchingOnYDown, touchingOnYUp;
    bool touchingOnX;
    int blockUpperEdge, blockLowerEdge, characterUpperEdge, characterLowerEdge;
    int blockLeftEdge, blockRightEdge, characterLeftEdge, characterRightEdge;
    
    //std::cout << "y_speed: " << y_speed << std::endl;
    this -> y += y_speed;
    
    characterUpperEdge = this->y + GLULUCAT_BLOCK_SIZE / 2;
    characterLowerEdge = this->y - GLULUCAT_BLOCK_SIZE / 2;
    characterLeftEdge = this->x - GLULUCAT_BLOCK_SIZE / 2;
    characterRightEdge = this->x + GLULUCAT_BLOCK_SIZE / 2;
    
    for (std::vector<Block>::iterator it = blocks.begin() ; it != blocks.end(); ++it){
        blockUpperEdge = it->y + GLULUCAT_BLOCK_SIZE / 2;
        blockLowerEdge = it->y - GLULUCAT_BLOCK_SIZE / 2;
        blockLeftEdge = it->x - GLULUCAT_BLOCK_SIZE / 2;
        blockRightEdge = it->x + GLULUCAT_BLOCK_SIZE / 2;
        
        touchingOnYDown = characterLowerEdge <= blockUpperEdge && characterLowerEdge >= blockLowerEdge;
        
        touchingOnYUp = characterUpperEdge >= blockLowerEdge && characterLowerEdge < blockLowerEdge;
        
        touchingOnX = (characterLeftEdge < blockRightEdge && characterLeftEdge >= blockLeftEdge)
        || (characterRightEdge > blockLeftEdge && characterRightEdge <= blockRightEdge);
        
        if(touchingOnX){
            //std::cout << "Estoy cayendo" << std::endl;
            
            if(touchingOnYDown){
                this->y = it->y + GLULUCAT_BLOCK_SIZE;
                y_speed = 0;
                on_air = false;
                break;
            }
            
            if(touchingOnYUp){
                y_speed = 0;
                //std::cout << " Tratando de saltar y no puedo" << std::endl;
                this->y = it->y - GLULUCAT_BLOCK_SIZE;
                break;
            }
        }else{
            on_air = true;
        }
    }
    
    if(on_air && y_speed > -GLULUCAT_BLOCK_SIZE/2){
        y_speed -= 2;
    }

    return this->y;
}
