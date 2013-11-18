//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "Glulucat.h"
#include <sstream>
#include "string.h"

Glulucat::Glulucat(void){
    x = 425;
    y = 500;
    z = 0;
    
    y_speed = 0;
    lives = 3;
    score = 0;
}

void print_bitmap_string(void* font, const char* s) {
    if (s && strlen(s)) {
        while (*s) {
            glutBitmapCharacter(font, *s);
            s++;
        }
    }
}

void Glulucat::displayCharacter(void) {
    glPushMatrix();
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(x, y, z);
    glutWireCube(50.0);
    glPopMatrix();
    ;
}

void Glulucat::displayMetadata(void){
    glColor3f(1.0, 1.0, 1.0);
    string str;
    std::stringstream ss;
    
    ss << "Vidas: " << this->lives << "             Estambre: " << this->score;
    str = ss.str();
    
    //std::cout << str << std::endl;
    
    glRasterPos3i(260, 570, 0);
    print_bitmap_string(GLUT_BITMAP_HELVETICA_18, str.c_str());
    
}


