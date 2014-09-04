#include "array2d.h"

using namespace std;

Array2D::Array2D( int rows, int cols ) {
    setNCols( cols );
    setNRows( rows );
    array = new int*[rows];
    for( int r = 0; r < rows; r++ ){
        array[r] = new int[cols];
        for( int c = 0; c < cols; c++ ){
            array[r][c] = rand() % 90 + 10;
        }
    }
}

Array2D::~Array2D(){
    //cout << "The destructor is now running.\n";
    for( int r = 0; r < nRows; r++ ){
        delete[] array[r];
    }
    delete[] array;
}

void Array2D::test(){
    for( int r = 0; r < nRows; r++ ){
        for( int c = 0; c < nCols; c++ ){
            cout << ( r * nCols + c ) << ", ";
        }
        cout<<endl;
    }
}

char* Array2D::toString(){
    char* chars = new char[nRows * nCols ];
    for( int r = 0; r < nRows; r++ ){
        for( int c = 0; c < nCols; c++ ){
            chars[r * nCols + c] = static_cast<char>( array[r][c] );
        }
    }
//    chars[0] = static_cast<char>( array[0][4] );
    return chars;
}

int Array2D::getNCols(){
    return nCols;
}

int Array2D::getNRows(){
    return nRows;
}

int** Array2D::getArray(){
    return array;
}

void Array2D::setNCols( int c ){
    nCols = c;
}

void Array2D::setNRows( int r ){
    nRows = r;
}
