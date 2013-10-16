//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#ifndef __Glulucat__Block__
#define __Glulucat__Block__

#include <iostream>

enum blockType {
     BLOCK_BREAKABLE = 10000,
     BLOCK_UNBREAKABLE = 10001,
     BLOCK_POWERUP = 10002
   };

enum blockItem {
     BLOCK_NOITEM = 20000,
     BLOCK_CAMERA = 20001,
     BLOCK_YARN = 20002
   };

#endif /* defined(__Glulucat__Block__) */

class Block {
public:
    Block();
    Block(int, int, blockType, blockItem);
    ~Block();
    int getX();
    int getY();
    blockType getType();
    blockItem getItem();
    void setX(int x);
    void setY(int y);
    void setType(blockType type);
    void setItem(blockItem item);
    void hitBlock();
    void drawBlock();
private:
    int x;
    int y;
    blockType type;
    blockItem item;
};

