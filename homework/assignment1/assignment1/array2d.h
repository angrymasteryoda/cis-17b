#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <cstdlib>
#include <iostream>

using namespace std;
class Array2D {
    public:
        Array2D( int, int );
        ~Array2D();
        int getNRows();
        int getNCols();
        int** getArray();
        char* toString();
        void setNRows( int );
        void setNCols( int );
        void test();
    private:
        int nRows;
        int nCols;
        int** array;
};

#endif // ARRAY2D_H
