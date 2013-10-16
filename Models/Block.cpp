//
//  Glulucat
//
//  Created by David Tovar Goris
//         and Guillermo de los Santos
//          on 10/15/13.
//  Copyright (c) 2013 Glulucat. All rights reserved.
//

#include "Block.h"

Block::Block () {
    x = 0;
    y = 0;
    type = 0;
}

Block::Block (int px, int py, int ptype) {
    x = px;
    y = py;
    type = ptype;
}