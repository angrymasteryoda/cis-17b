/*
 * Michael Risher
 * 08/26/14
 * GNU GENERAL PUBLIC LICENSE V3
 */


#include <qapplication>
// looks like jlabel
#include <QLabel>

int main( int argc, char** argv) {
    QApplication app( argc, argv );
    QLabel *label = new QLabel( "hello world" ); //qlabel cleans up after itself
    //label->show();
    (*label).show();
    return app.exec();
}


