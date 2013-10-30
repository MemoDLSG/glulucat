//
//  Glulucat.cpp
//  Glulucat
//
//  Created by David Tovar Goris on 10/20/13.
//  Copyright (c) 2013 David Tovar Goris. All rights reserved.
//

#include "Glulucat.h"

Glulucat::Glulucat(){
    x = 400;
    y = 137.5;
    z = 0;
}

void Glulucat::displayCharacter() {
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(x, y, z);
    glScalef (2.0, 1.5, 0.5);
    glutWireCube(50.0);
    glPopMatrix();
}

