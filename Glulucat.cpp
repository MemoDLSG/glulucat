//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "Glulucat.h"

Glulucat::Glulucat(){
    x = 425;
    y = 500;
    z = 0;
    y_speed = 0;
}

void Glulucat::displayCharacter() {
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(x, y, z);
    glutWireCube(50.0);
    glPopMatrix();
}
