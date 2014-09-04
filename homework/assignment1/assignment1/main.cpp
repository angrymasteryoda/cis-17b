
#include <QApplication>
#include <QLabel>
#include <cstdlib>
#include <iostream>
#include <ctime>

#include "array2d.h"

using namespace std;

void trash( int** a, int rows );

int main( int argc, char** argv ){
    srand( time( NULL ) );
    QApplication app( argc, argv );
    Array2D array2d( 5, 5 );
    QLabel *label = new QLabel( array2d.toString() );
    label->show();
    return app.exec();
}
