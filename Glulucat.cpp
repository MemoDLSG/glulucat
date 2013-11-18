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
    this -> dead = false;
}

Glulucat::Glulucat(int x, int y){
    this->x = x;
    this->y = y;
    z = 0;

    y_speed = 0;
    lives = 3;
    score = 0;
    this -> dead = false;
}

Glulucat::Glulucat(int x, int y, int lives){
    this->x = x;
    this->y = y;
    z = 0;

    y_speed = 0;
    score = 0;
    this -> lives = lives;
    this -> dead = false;
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

    ss << "Vidas: " << this->lives << "             Puntos: " << this->score;
    str = ss.str();

    //std::cout << str << std::endl;

    glRasterPos3i(260, 570, 0);
    print_bitmap_string(GLUT_BITMAP_HELVETICA_18, str.c_str());

}

void Glulucat::collectYarn(Level& level){

    float i = this->x/(GLULUCAT_BLOCK_SIZE*1.0) - 0.5;
    float j = this->y/(GLULUCAT_BLOCK_SIZE*1.0) - 0.5;
    int left = (int)floor(i);
    int right = (int)ceil(i);
    int down = (int)floor(j);
    int up = (int)ceil(j);

    //touching on X left
    if(level.levelMap[left][down] == GLULUCAT_YARN){
        //level.levelMap[left][down] = GLULUCAT_NOTHING;
        level.UpdateCell(left, down, GLULUCAT_NOTHING);
        score += GLULUCAT_YARN_SCORE;
    }
    if(level.levelMap[right][down] == GLULUCAT_YARN){
        //level.levelMap[right][down] = GLULUCAT_NOTHING;
        level.UpdateCell(right, down, GLULUCAT_NOTHING);
        score += GLULUCAT_YARN_SCORE;
    }
    if(level.levelMap[left][up] == GLULUCAT_YARN){
        //level.levelMap[left][up] = GLULUCAT_NOTHING;
        level.UpdateCell(left, up, GLULUCAT_NOTHING);
        score += GLULUCAT_YARN_SCORE;
    }
    if(level.levelMap[right][up] == GLULUCAT_YARN){
        //level.levelMap[right][up] = GLULUCAT_NOTHING;
        level.UpdateCell(right, up, GLULUCAT_NOTHING);
        score += GLULUCAT_YARN_SCORE;
    }
}

void Glulucat::die(){
    this -> lives--;
    this -> score = 0;
    this -> dead = true;
}

void Glulucat::bumpedLeft(vector<Duck>& ducks, vector<Duck>::iterator it){
    die();
}

void Glulucat::bumpedRight(vector<Duck>& ducks, vector<Duck>::iterator it){
    die();
}

void Glulucat::bumpedDown(vector<Duck>& ducks, vector<Duck>::iterator it){
    ducks.erase(it);
    this -> score += 200;
    this -> on_air = false;
    startJumping();
}

void Glulucat::bumpedUp(vector<Duck>& ducks, vector<Duck>::iterator it){
    die();
}

void Glulucat::bumpDucks(vector<Duck>& ducks) {
    bool touchingOnYDown, touchingOnYUp, touchingOnXLeft, touchingOnXRight;
    int duckUpperEdge, duckLowerEdge, characterUpperEdge, characterLowerEdge;
    int duckLeftEdge, duckRightEdge, characterLeftEdge, characterRightEdge;

    for (std::vector<Duck>::iterator it = ducks.begin() ; it != ducks.end(); ++it){
        duckUpperEdge = it->y + GLULUCAT_BLOCK_SIZE/2;
        duckLowerEdge = it->y - GLULUCAT_BLOCK_SIZE/2;
        characterUpperEdge = this->y + GLULUCAT_BLOCK_SIZE/2;
        characterLowerEdge = this->y - GLULUCAT_BLOCK_SIZE/2;

        duckLeftEdge = it->x - GLULUCAT_BLOCK_SIZE/2;
        duckRightEdge = it->x + GLULUCAT_BLOCK_SIZE/2;
        characterLeftEdge = this -> x - GLULUCAT_BLOCK_SIZE/2;
        characterRightEdge = this -> x + GLULUCAT_BLOCK_SIZE/2;

        touchingOnYDown = (characterLowerEdge <= duckUpperEdge && characterLowerEdge >= duckLowerEdge);
        touchingOnYUp = (characterUpperEdge >= duckLowerEdge && characterUpperEdge <= duckUpperEdge);
        touchingOnXLeft = (characterLeftEdge < duckRightEdge && characterLeftEdge >= duckLeftEdge);
        touchingOnXRight = (characterRightEdge > duckLeftEdge && characterRightEdge <= duckRightEdge);

        if(touchingOnXLeft || touchingOnXRight){
            if(characterUpperEdge == duckUpperEdge){
                if(touchingOnXLeft){
                    bumpedLeft(ducks, it);
                }else{ //touchingOnXRight;
                    bumpedRight(ducks, it);
                }
                break;
            }

            if(touchingOnYDown){
                bumpedDown(ducks, it);
                break;
            }

            if(touchingOnYUp){
                bumpedUp(ducks, it);
                break;
            }
        }
    }
}


