//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 17/11/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "YarnBall.h"
#include <iostream>

YarnBall::YarnBall(){
    this->x = 0;
    this->y = 0;
}

YarnBall::YarnBall(int x, int y){
    this->x = x;
    this->y = y;
}

void YarnBall::DrawYarnBall() {
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(x, y, 0);
    glutSolidCube(25);
    glPopMatrix();
}
