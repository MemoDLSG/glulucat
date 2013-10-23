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

int Character::moveX(int px){
    x = x + px;
    //std::cout << "Move x: " << x << std::endl;
    return x;
}

int Character::moveY(int py){
    y = y + py;
    return y;
}
