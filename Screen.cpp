//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "Screen.h"
#include "string.h"


Screen::Screen () {
    
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

void Screen::DrawStartScreen() {
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
    
    const char* str;
    
    str = " N U E V O  J U E G O    [N]";
    
    glColor3f(0.5, 0.8, 0.8);
    glRasterPos3i(252, 302, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(0.5, 0.8, 0.8);
    glRasterPos3i(251, 301, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f( 1.0, 1.0, 0.7);
    glRasterPos3i(250, 300, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    
    str = " P  U  N  T  A  J  E  S       [P]";
    
    glColor3f(.9, .9, .2);
    glRasterPos3i(252, 202, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(.9, .9, .2);
    glRasterPos3i(251, 201, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(.6, .6, .1);
    glRasterPos3i(250, 200, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);

    str = " C  R  E  D  I  T  O  S        [C]";
    
    glColor3f(.9, .9, .2);
    glRasterPos3i(252, 102, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(.9, .9, .2);
    glRasterPos3i(251, 101, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(1.0, .6, 0.0);
    glRasterPos3i(250, 100, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);

}

void Screen::DrawScores() {
    
}

void Screen::DrawGameOver() {
    glLoadIdentity();
    glPushMatrix();
    glColor4f(0.5, 0.5, 0.5, .4);
    glTranslatef(400, 300, 0);
    glScalef(10,  5, 1);
    glutSolidSphere(40, 40, 50);
    glPopMatrix();
    
    const char* str;
    
    str = " N U E V O  J U E G O    [N]";
    
    glColor3f(0.5, 0.8, 0.8);
    glRasterPos3i(252, 302, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(0.5, 0.8, 0.8);
    glRasterPos3i(251, 301, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f( 1.0, 1.0, 0.7);
    glRasterPos3i(250, 300, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    
    str = " S   A   L   I   R        [S]";
    
    glColor3f(.9, .9, .2);
    glRasterPos3i(252, 202, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(.9, .9, .2);
    glRasterPos3i(251, 201, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(.6, .6, .1);
    glRasterPos3i(250, 200, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);

}

void Screen::DrawCredits() {
    
}

Screen::~Screen(void) {
}