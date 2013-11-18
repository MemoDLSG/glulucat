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
    x_speed = 10;
    y_speed = 0;
    on_air = true;
    powerup = false;
}

//Funciones a implementar en Glulucat y Duck independientemente!
void Character::displayCharacter (void) {}

int Character::moveX(int levelMap[][12]){
    this -> x += x_speed;

    float i = this->x/(GLULUCAT_BLOCK_SIZE*1.0) - 0.5;
    float j = this->y/(GLULUCAT_BLOCK_SIZE*1.0) - 0.5;

    //touching on X left
    if(levelMap[(int)floor(i)][(int)floor(j)] == GLULUCAT_BLOCK || levelMap[(int)floor(i)][(int)ceil(j)] == GLULUCAT_BLOCK){
        this->x = (int) ((floor(i)+1.5) * GLULUCAT_BLOCK_SIZE);
        this->x_speed *= -1;
    }

    //touching on X right
    if(levelMap[(int)ceil(i)][(int)floor(j)] == GLULUCAT_BLOCK || levelMap[(int)ceil(i)][(int)ceil(j)] == GLULUCAT_BLOCK){
        this->x = (int) ((ceil(i)-0.5) * GLULUCAT_BLOCK_SIZE);
        this->x_speed *= -1;
    }

    return this->x;
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

int Character::moveY(int levelMap[][12]) {

    this -> y += y_speed;

    float i = this->x/(GLULUCAT_BLOCK_SIZE*1.0) - 0.5;
    float j = this->y/(GLULUCAT_BLOCK_SIZE*1.0) - 0.5;

    //touching on Y down
    if(levelMap[(int)floor(i)][(int)floor(j)] == GLULUCAT_BLOCK || levelMap[(int)ceil(i)][(int)floor(j)] == GLULUCAT_BLOCK){
        this->y = (int) ((floor(j)+1.5) * GLULUCAT_BLOCK_SIZE);
        y_speed = 0;
        on_air = false;
    }else{
        this -> on_air = true;
    }

    //touching on Y up
    if(levelMap[(int)floor(i)][(int)ceil(j)] == GLULUCAT_BLOCK || levelMap[(int)ceil(i)][(int)ceil(j)] == GLULUCAT_BLOCK){
        this->y = (int) ((ceil(j)-0.5) * GLULUCAT_BLOCK_SIZE);
        y_speed = 0;
    }

    if(on_air && y_speed > -GLULUCAT_BLOCK_SIZE/2){
        y_speed -= 2;
    }

    return this->y;
}
