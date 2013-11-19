//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#ifndef __Glulucat__Screen__
#define __Glulucat__Screen__

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include <fstream>
#include <iostream>
#include <vector>

class Screen {
    
    int x, y, z;
    
public :
    Screen(void);
    ~Screen(void);
    
    void DrawStartScreen(void);
    void DrawScores(std::vector<std::string>);
    void DrawCredits(void);
    void DrawGameOver(void);
    void DrawWinnerIsYOU(int);
    
};

#endif /* defined(__Glulucat__Screen__) */
