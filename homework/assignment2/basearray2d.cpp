#include "basearray2d.h"

using namespace std;

baseArray2d::baseArray2d( int rows, int cols ) {
    setNCols( cols );
    setNRows( rows );
    fillArray();
}

baseArray2d::~baseArray2d() {
    for( int r = 0; r < nRows; r++ ){
        delete[] array[r];
    }
    delete[] array;
}

void baseArray2d::fillArray(){
    int rows = getNRows();
    int cols = getNCols();
    array = new int*[rows];
    for( int r = 0; r < rows; r++ ){
        array[r] = new int[cols];
        for( int c = 0; c < cols; c++ ){
            array[r][c] = rand() % 90 + 10;
        }
    }
}

int baseArray2d::getNCols(){
    return nCols;
}

int baseArray2d::getNRows(){
    return nRows;
}

int** baseArray2d::getArray(){
    return array;
}

void baseArray2d::setNCols( int c ){
    nCols = c;
}

void baseArray2d::setNRows( int r ){
    nRows = r;
}
