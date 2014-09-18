#ifndef DERARRAY2D_H
#define DERARRAY2D_H

#include "basearray2d.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
using namespace std;
class derArray2d : public baseArray2d {
    public:
        derArray2d( int rows, int cols ) : baseArray2d( rows, cols ) {
            // inherit it
        }
        const char* toString();
};

#endif // DERARRAY2D_H
