//
//  Glulucat.cpp
//  Glulucat
//
//  Created by David Tovar Goris on 10/20/13.
//  Copyright (c) 2013 David Tovar Goris. All rights reserved.
//

#include "Glulucat.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <windows.h>
#endif

Glulucat::Glulucat(){
    x = 400;
    y = 300;
    z = 0;
    
    y_speed = 0;
}

void Glulucat::displayCharacter() {
    glColor3f(1.0, 1.0, 1.0);
    //std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
    glScalef (2.0, 1.5, 0.5);
    glTranslatef(x, y, z);
    glutWireCube(50.0);
    
}
