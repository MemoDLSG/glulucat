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
    return y;
}

bool Character::jump(bool jumping){
    this -> jumping = jumping;
    return jumping;
}

void Character::Fall(vector<Block> blocks) {
    bool onBlock = false;
    bool touchingOnY;
    bool touchingOnX;
    cout << "Estoy en Fall" << endl;
    for (std::vector<Block>::iterator it = blocks.begin() ; it != blocks.end(); ++it){
        touchingOnY = (it->y + 50) == (y - 50);
        touchingOnX = (x >= (it->x - 50)) && (x <= (it->x + 50));
        /*
        cout << "Comparando con bloque en" << it->x << "," << it->y << "; ";
        if(touchingOnY){
            cout << "Estoy tocando en y! ";
        }
        if(touchingOnX){
            cout << "Estoy tocando en x! ";
        }
        cout << endl;
        */
        if (touchingOnX && touchingOnY){
            onBlock = true;
            //cout << "Esta sobre este bloque!" << endl;
            break;
        }
    }
    if(!onBlock){
        moveY(-10);
    }
}
