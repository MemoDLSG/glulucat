//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "Level.h"

Level::Level(void){
    width = 16;
    height = 12;

    //HARDCODED BLOCKS
    /*blocks.push_back(Block(GLULUCAT_BLOCK_SIZE/2+600, GLULUCAT_BLOCK_SIZE*1.5, BLOCK_UNBREAKABLE, BLOCK_NOITEM));
    blocks.push_back(Block(GLULUCAT_BLOCK_SIZE/2+50, GLULUCAT_BLOCK_SIZE*1.5, BLOCK_UNBREAKABLE, BLOCK_NOITEM));
    for(int i=0; i<4; i++){
        blocks.push_back(Block(375, (GLULUCAT_BLOCK_SIZE)*(i+1) + GLULUCAT_BLOCK_SIZE*1.5, BLOCK_UNBREAKABLE, BLOCK_NOITEM));
    }

    for(int i=0; i<3; i++){
        blocks.push_back(Block(375+i*GLULUCAT_BLOCK_SIZE, 325, BLOCK_UNBREAKABLE, BLOCK_NOITEM));
    }

    for(int i=0; i<16; i++){
        blocks.push_back(Block(GLULUCAT_BLOCK_SIZE/2+i*GLULUCAT_BLOCK_SIZE, GLULUCAT_BLOCK_SIZE/2, BLOCK_UNBREAKABLE, BLOCK_NOITEM));
    }

    for(int i=0; i<4; i++){
        blocks.push_back(Block(175+i*GLULUCAT_BLOCK_SIZE, 125, BLOCK_UNBREAKABLE, BLOCK_NOITEM));
    }*/

    //HARDCODED YARNBALLS

    //RANDOM
    /*
    for(int i=0; i<160; i++){
        for(int j=0; j<120; j++){
            int prob = rand() % 10;
            if(prob < 3){
                blocks.push_back(Block((i+0.5)*GLULUCAT_BLOCK_SIZE, (j+0.5)*GLULUCAT_BLOCK_SIZE, BLOCK_UNBREAKABLE, BLOCK_NOITEM));
            }else if(prob < 4){
                yarnballs.push_back(YarnBall((i+0.5)*GLULUCAT_BLOCK_SIZE, (j+0.5)*GLULUCAT_BLOCK_SIZE));
            }
        }
    }*/

    //RANDOM

    for(int i=0; i<width; i++){
        levelMap[i][0] = GLULUCAT_BLOCK;
    }
    levelMap[2][1] = GLULUCAT_BLOCK;
    levelMap[13][1] = GLULUCAT_BLOCK;


    for(int i=5; i<width-5; i++){
        levelMap[i][3] = GLULUCAT_BLOCK;
    }

    /*for(int i=0; i<width; i++){
        for(int j=1; j<height; j++){
            int prob = rand() % 100;
            if(prob < 25){
                levelMap[i][j] = GLULUCAT_BLOCK;
            }else if(prob < 35){
                levelMap[i][j] = GLULUCAT_YARNBALL;
            }else{
                levelMap[i][j] = GLULUCAT_NOTHING;
            }
        }
    }*/

    /*
    //RANDOM

    //RANDOM
    for(int i=5; i<width-5; i++){
        levelMap[i][3] = GLULUCAT_BLOCK;
    }
    */
}

Level::Level(int pwidth, int pheight){
    width = pwidth;
    height = pheight;
}

Level::Level(int pwidth, int pheight, std::vector<Block> pblocks ){
    width = pwidth;
    height = pheight;
    blocks = pblocks;
}

void Level::AddBlock(Block block){
    blocks.push_back(block);
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
            if(levelMap[i][j] == GLULUCAT_BLOCK){
                DrawBlock(i,j);
            }else if(levelMap[i][j] == GLULUCAT_YARNBALL){
                DrawYarnBall(i,j);
            }
        }
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

void Level::DrawYarnBall(int i, int j){
    int x = (i+0.5)*GLULUCAT_BLOCK_SIZE;
    int y = (j+0.5)*GLULUCAT_BLOCK_SIZE;
    glLoadIdentity();
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0); //color provisiorio mientras se ponen texturas
    glTranslatef(x, y, 0);
    glutSolidCube(GLULUCAT_BLOCK_SIZE/2);
    glPopMatrix();
}
