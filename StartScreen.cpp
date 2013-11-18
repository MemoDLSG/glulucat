//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "StartScreen.h"
#include <sstream>
#include "string.h"


StartScreen::StartScreen () {
    
    x = y = z = 0;
    
}

void print_bitmap_stringg(void* font, const char* s) {
    if (s && strlen(s)) {
        while (*s) {
            glutBitmapCharacter(font, *s);
            s++;
        }
    }
}

void StartScreen::DrawScreen() {
    glLoadIdentity();
    glPushMatrix();
    glColor4f(0.7, 0.2, 0.2, .4);
    glTranslatef(400, 110, 0);
    glScalef(5.5, 1.0, 0);
    glutSolidCube(60);
    glColor4f(0.2, 0.7, 0.2, .4);
    glTranslatef(0, 100, 0);
    glutSolidCube(60);
    glColor4f(0.2, 0.2, 0.7, .4);
    glTranslatef(0, 100, 0);
    glutSolidCube(60);
    glPopMatrix();
    
    std::string str;
    std::stringstream ss;
    
    ss << " N U E V O  J U E G O    [N]";
    str = ss.str();
    //std::cout << str << std::endl;
    
    glColor3f(0.5, 0.8, 0.8);
    glRasterPos3i(252, 302, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str.c_str());
    glColor3f(0.5, 0.8, 0.8);
    glRasterPos3i(251, 301, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str.c_str());
    glColor3f( 1.0, 1.0, 0.7);
    glRasterPos3i(250, 300, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str.c_str());
    
    ss = std::stringstream();
    ss << " P  U  N  T  A  J  E  S       [P]";
    str = ss.str();
    //std::cout << str << std::endl;
    
    glColor3f(.9, .9, .2);
    glRasterPos3i(252, 202, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str.c_str());
    glColor3f(.9, .9, .2);
    glRasterPos3i(251, 201, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str.c_str());
    glColor3f(.6, .6, .1);
    glRasterPos3i(250, 200, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str.c_str());

    ss = std::stringstream();
    ss << " C  R  E  D  I  T  O  S        [C]";
    str = ss.str();
    //std::cout << str << std::endl;
    
    glColor3f(.9, .9, .2);
    glRasterPos3i(252, 102, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str.c_str());
    glColor3f(.9, .9, .2);
    glRasterPos3i(251, 101, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str.c_str());
    glColor3f(1.0, .6, 0.0);
    glRasterPos3i(250, 100, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str.c_str());

}

StartScreen::~StartScreen(void) {
}