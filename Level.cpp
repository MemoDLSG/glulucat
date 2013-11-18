//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "Level.h"
#include "Glulucat.h"
#include "Duck.h"

Level::Level(){}

void Level::StartDefault(){
    width = 16;
    height = 12;

    for(int i=0; i<width; i++){
            levelMap[i][0] = GLULUCAT_BLOCK;
    }
    levelMap[2][1] = GLULUCAT_BLOCK;
    levelMap[13][1] = GLULUCAT_BLOCK;

    for(int i=5; i<width-5; i++){
        levelMap[i][3] = GLULUCAT_BLOCK;
    }

}

void Level::UpdateCell(int i, int j, int val){
    levelMap[i][j] = val;
}

void Level::PrintLevel(){
    for(int j=(height-1); j>=0; j--){
        for(int i=0; i<width; i++){
            cout << levelMap[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void Level::DrawLevel(){
    /*for (std::vector<Block>::iterator it = blocks.begin() ; it != blocks.end(); ++it){
        (*it).DrawBlock();
    }
    for (std::vector<YarnBall>::iterator it = yarnballs.begin() ; it != yarnballs.end(); ++it){
        (*it).DrawYarnBall();
    }*/

    for(int i=0; i<width; i++){
        for(int j=0; j<height; j++){
            switch (levelMap[i][j]){
                case GLULUCAT_BLOCK:
                    DrawBlock(i,j);
                    break;
                case GLULUCAT_YARN:
                    DrawYarn(i,j);
                    break;
                case GLULUCAT_CAMERA:
                    DrawCamera(i,j);
                    break;
                default:
                    break;
            }
        }
        //cout << endl;
    }
}

void Level::DrawBlock(int i, int j){
    int x = (i+0.5)*GLULUCAT_BLOCK_SIZE;
    int y = (j+0.5)*GLULUCAT_BLOCK_SIZE;
    glLoadIdentity();
    glPushMatrix();
    glColor3f(x/800.0, (1-x/800.0), 1.0); //color provisiorio mientras se ponen texturas
    glTranslatef(x, y, 0);
    glutSolidCube(GLULUCAT_BLOCK_SIZE);
    glPopMatrix();
}

void Level::DrawYarn(int i, int j){
    int x = (i+0.5)*GLULUCAT_BLOCK_SIZE;
    int y = (j+0.5)*GLULUCAT_BLOCK_SIZE;
    glLoadIdentity();
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0); //color provisiorio mientras se ponen texturas
    glTranslatef(x, y, 0);
    glutSolidCube(GLULUCAT_BLOCK_SIZE/2);
    glPopMatrix();
}

void Level::DrawCamera(int i, int j){
    int x = (i+0.5)*GLULUCAT_BLOCK_SIZE;
    int y = (j+0.5)*GLULUCAT_BLOCK_SIZE;
    glLoadIdentity();
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0); //color provisiorio mientras se ponen texturas
    glTranslatef(x, y, 0);
    glutSolidCube(GLULUCAT_BLOCK_SIZE*0.67);
    glPopMatrix();
}
