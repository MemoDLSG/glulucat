//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "Screen.h"
#include <iostream>
#include <fstream>

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

void Screen::DrawScores(std::vector<std::string> lines) {
    
    glLoadIdentity();
    glPushMatrix();
    glColor4f(0.2, 0.6, 0.3, .4);
    glTranslatef(600, 450, 0);
    glScalef(90,  90, 2);
    glutSolidIcosahedron();
    glPopMatrix();
    
    const char* str;
    int yy = 90;
    
    for (std::vector<std::string>::iterator it = lines.begin() ; it != lines.end(); ++it) {
        glColor3f(0.5, 0.5, 0.5);
        glRasterPos3i(152, ++yy, 0);
        print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, it->c_str());
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3i(151, yy++, 0);
        print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, it->c_str());
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3i(150, yy++, 0);
        print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, it->c_str());
        yy += 90;
    }
    
    
    
    str = "R e g r e s a r     M e n u [S]";
    
    glColor3f(0.5, 0.5, 0.5);
    glRasterPos3i(452, 52, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos3i(451, 51, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos3i(450, 50, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);

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
    
    str = " S A L I R   D E L   J U E G O [S]";
    
    glColor3f(.9, .9, .2);
    glRasterPos3i(232, 202, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(.9, .9, .2);
    glRasterPos3i(231, 201, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(.6, .6, .1);
    glRasterPos3i(230, 200, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    
    str = " R E G R E S A R     M E N U    P R I N C I P A L [M]";
    
    glColor3f(0.5, 0.8, 0.8);
    glRasterPos3i(152, 302, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(0.5, 0.8, 0.8);
    glRasterPos3i(151, 301, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f( 1.0, 1.0, 0.7);
    glRasterPos3i(150, 300, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);

}

void Screen::DrawCredits() {
    
    glLoadIdentity();
    glPushMatrix();
    glColor4f(0.2, 0.6, 0.3, .4);
    glTranslatef(600, 450, 0);
    glScalef(60,  60, 2);
    glutSolidDodecahedron();
    glPopMatrix();
    
    const char* str;
    
    str = "G U I L L E R M O   D E   L O S   S A N T O S   1 1 1 1 1 1 1 ";
    
    glColor3f(0.5, 0.8, 0.8);
    glRasterPos3i(52, 302, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(0.5, 0.8, 0.8);
    glRasterPos3i(51, 301, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f( 1.0, 1.0, 0.7);
    glRasterPos3i(50, 300, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    
    str = "D  A  V  I  D     T  O  V  A  R     G  O  R  I  S     1 1 6 1 5 0 2";
    
    glColor3f(.9, .5, .2);
    glRasterPos3i(52, 202, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(1.0, .3, .1);
    glRasterPos3i(51, 201, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(1.0, .3, .1);
    glRasterPos3i(50, 200, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    
    str = "R e g r e s a r     M e n u [S]";
    
    glColor3f(0.5, 0.5, 0.5);
    glRasterPos3i(452, 52, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos3i(451, 51, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos3i(450, 50, 0);
    print_bitmap_stringg(GLUT_BITMAP_TIMES_ROMAN_24, str);
}

Screen::~Screen(void) {
}