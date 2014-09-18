#ifndef BASEARRAY2D_H
#define BASEARRAY2D_H

#include "absarray2d.h"

#include <cstdlib>
#include <iostream>
using namespace std;
class baseArray2d:absArray2d {
    public:
        baseArray2d( int, int);
        ~baseArray2d();
        void fillArray();
        int getNRows();
        int getNCols();
        int** getArray();
        void setNRows( int );
        void setNCols( int );
    protected:
        int nRows;
        int nCols;
        int** array;
};

#endif // BASEARRAY2D_H
