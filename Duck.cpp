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
    y = 500;
    z = 0;
    
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

int Duck::moveX(int x, std::vector<Block>){
    if(this->x > 800) {
        this->x = 0;
    }
    this->x += x + 1;
    
    
    return this->x;
}
