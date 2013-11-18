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

void Duck::bumpDucks(vector<Duck> otherDucks) {
    bool touchingOnYDown, touchingOnYUp, touchingOnXLeft, touchingOnXRight;
    int blockUpperEdge, blockLowerEdge, characterUpperEdge, characterLowerEdge;
    int blockLeftEdge, blockRightEdge, characterLeftEdge, characterRightEdge;
    int movX, movY;
    for (std::vector<Duck>::iterator it = otherDucks.begin() ; it != otherDucks.end(); ++it){
        blockUpperEdge = it->y + GLULUCAT_BLOCK_SIZE/2;
        blockLowerEdge = it->y - GLULUCAT_BLOCK_SIZE/2;
        characterUpperEdge = this->y + GLULUCAT_BLOCK_SIZE/2;
        characterLowerEdge = this->y - GLULUCAT_BLOCK_SIZE/2;

        blockLeftEdge = it->x - GLULUCAT_BLOCK_SIZE/2;
        blockRightEdge = it->x + GLULUCAT_BLOCK_SIZE/2;
        characterLeftEdge = this -> x - GLULUCAT_BLOCK_SIZE/2;
        characterRightEdge = this -> x + GLULUCAT_BLOCK_SIZE/2;

        touchingOnYDown = (characterLowerEdge <= blockUpperEdge && characterLowerEdge >= blockLowerEdge);
        touchingOnYUp = (characterUpperEdge >= blockLowerEdge && characterUpperEdge <= blockUpperEdge);
        touchingOnXLeft = (characterLeftEdge < blockRightEdge && characterLeftEdge >= blockLeftEdge);
        touchingOnXRight = (characterRightEdge > blockLeftEdge && characterRightEdge <= blockRightEdge);

        /*
        if((touchingOnXLeft || touchingOnXRight) && (touchingOnYDown || touchingOnYUp)){
            if(touchingOnXLeft || touchingOnXRight){
                this -> x_speed *= -1;
            }
            if(touchingOnXLeft){
                movX = 1;
            }else{ //touchingOnXRight;
                movX = -1;
            }
            if(touchingOnYDown){
                movY = 1;
            }else{ //touchingOnYUp;
                movY = -1;
            }

            this -> x = it->x + movX*GLULUCAT_BLOCK_SIZE;
            this -> y = it->y + movY*GLULUCAT_BLOCK_SIZE;

            break;
        }*/


        if(touchingOnYDown || touchingOnYUp){
            if(touchingOnXLeft){
                this -> x = it->x + GLULUCAT_BLOCK_SIZE;
                this -> x_speed *= -1;
                break;
            }

            if(touchingOnXRight){
                this -> x = it->x - GLULUCAT_BLOCK_SIZE;
                this -> x_speed *= -1;
                break;
            }
        }
/*

        if(touchingOnXLeft || touchingOnXRight){
            if(touchingOnYDown){
                this -> y = it->y + GLULUCAT_BLOCK_SIZE;
                //this -> x_speed *= -1;
                //break;
            }

            if(touchingOnYUp){
                this -> y = it->y - GLULUCAT_BLOCK_SIZE;
                //this -> x_speed *= -1;
                //break;
            }
        }*/
    }
}

