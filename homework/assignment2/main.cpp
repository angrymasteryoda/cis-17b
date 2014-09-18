#include <QApplication>
#include <QLabel>
#include <cstdlib>
#include <iostream>
#include <ctime>

#include "derarray2d.h"

using namespace std;

int main( int argc, char** argv ){
    derArray2d array(5,5);
    cout << array.toString();
    return 0;
//    srand( time( NULL ) );
//    QApplication app( argc, argv );
//    derArray2d array2d( 5, 5 );
////    Array2D array2d( 5, 5 );
//    QLabel *label = new QLabel( array2d.toString() );
//    label->show();
//    return app.exec();
}
