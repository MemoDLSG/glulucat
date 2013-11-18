//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#ifndef __Glulucat__StartScreen__
#define __Glulucat__StartScreen__

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include <iostream>

class StartScreen {
    
    int x, y, z;
    
    public :
        StartScreen(void);
        ~StartScreen(void);
    
        void DrawScreen(void);
    
};

#endif /* defined(__Glulucat__StartScreen__) */
