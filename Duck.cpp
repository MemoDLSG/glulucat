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
    y = GLULUCAT_BLOCK_SIZE*1.5;
    z = 0;
    //x_speed = (int) (rand() % 5) + 1;
    x_speed = 2;
    y_speed = 0;
}

Duck::Duck(int x, int y){
    this->x = x;
    this->y = y;
    z = 0;
    //x_speed = (int) (rand() % 5) + 1;
    x_speed = 2;
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

void Duck::bumpedLeft(vector<Duck>& ducks, vector<Duck>::iterator it){
    this -> x_speed *= -1;
    this -> x = it->x + GLULUCAT_BLOCK_SIZE;
}

void Duck::bumpedRight(vector<Duck>& ducks, vector<Duck>::iterator it){
    this -> x_speed *= -1;
    this -> x = it->x - GLULUCAT_BLOCK_SIZE;
}

void Duck::bumpedDown(vector<Duck>& ducks, vector<Duck>::iterator it){
    this -> y = it->y + GLULUCAT_BLOCK_SIZE;
}

void Duck::bumpedUp(vector<Duck>& ducks, vector<Duck>::iterator it){
    this -> y = it->y - GLULUCAT_BLOCK_SIZE;
}

void Duck::bumpDucks(vector<Duck>& ducks) {
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

