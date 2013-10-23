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


class Character {

    int x_speed;
    int y_speed;
    bool jumping;
    bool powerup;
    bool flicking;
    
public:

    Character();
    //~Character();
    void displayCharacter();
    int moveX(int);
    int moveY(int);

protected:
    int x;
    int y;
    int z;
    
private:
    
};

#endif