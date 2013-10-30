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

int Character::moveX(int x){
    this -> x += x;
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
    if (y_speed <= 55 && jumping) {
        y_speed = y_speed + 5;
        this->y += y_speed;
    } else if (y_speed > 55 && jumping){
        jumping = false;
        y_speed = 0;
    } else {
        std::cout << "jump y_speed : " << y_speed << std::endl;
    }
    return this->y;
}

void Character::Fall(vector<Block> blocks) {
    bool onBlock = false;
    bool touchingOnY;
    bool touchingOnX;
    //std::cout << "Estoy en Fall" << std::endl;
    for (std::vector<Block>::iterator it = blocks.begin() ; it != blocks.end(); ++it){
        touchingOnY = (it->y + 50) == (y - 50);
        touchingOnX = (x >= (it->x - 50)) && (x <= (it->x + 50));
        /*
        std::cout << "Comparando con bloque en" << it->x << "," << it->y << "; ";
        if(touchingOnY){
            std::cout << "Estoy tocando en y! ";
         
        }
        if(touchingOnX){
            std::cout << "Estoy tocando en x! ";
        }
        std::cout << std::endl;
        */
        if (touchingOnX && touchingOnY){
            onBlock = true;
            
            //std::cout << "jumping : " << jumping << " y_speed: " << y_speed << std::endl;
            //std::cout << "Esta sobre este bloque!" << std::endl;
            break;
        }
    }
    if(!onBlock){
        moveY(-10);
    }
}
