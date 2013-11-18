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

    ifstream layout ("C:\\Users\\Memo\\Documents\\GitHub\\glulucat\\level1.txt");
    string line;
    int i = 0;
    if (layout.is_open()){
        getline(layout, line);
        this -> width = atoi(line.c_str());

        getline(layout, line);
        this -> height = atoi(line.c_str());

        for(int j=(height-1); j>=0; j--){
            getline(layout, line);
            for(int i=0; i<width; i++){
                levelMap[i][j] = line.at(i) - '0';
            }
        }
        layout.close();
    }

    else{
        cout << "Unable to open file" << endl;
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
}

Level::Level(int pwidth, int pheight){
    width = pwidth;
    height = pheight;
}

Level::Level(int pwidth, int pheight, std::vector<Block> pblocks ){
    width = pwidth;
    height = pheight;
    //blocks = pblocks;
}

void Level::AddBlock(Block block){
    //blocks.push_back(block);
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
            //cout << levelMap[i][j];
            if(levelMap[i][j] == GLULUCAT_BLOCK){
                DrawBlock(i,j);
            }else if(levelMap[i][j] == GLULUCAT_YARN){
                DrawYarn(i,j);
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
