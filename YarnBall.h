//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 17/11/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#ifndef YARNBALL_H_INCLUDED
#define YARNBALL_H_INCLUDED

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

class YarnBall {

public:
    YarnBall();
    YarnBall(int, int);
    int x;
    int y;
    void DrawYarnBall();

};

#endif // YARNBALL_H_INCLUDED
