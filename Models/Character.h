//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#ifndef Glulucat_character_h
#define Glulucat_character_h

#endif

class Character {
    int x;
    int y;
    int x_speed;
    int y_speed;
    bool jumping;
    bool powerup;
    bool flicking;
    
public:
    Character();
    ~Block();
    int moveX(int dx);
    int moveY(int dy);
};