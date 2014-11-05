
#include <QtCore>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>

void read( QString filename ){
    QFile file( filename );
    if( !file.open( QFile::ReadOnly | QFile::Text ) ){
        qDebug() << "could not read file";
        return;
    }

    QTextStream in( &file );
    QString text = in.readAll();

    qDebug() << text;
    file.close();
}

int main( int argc, char *argv[] ) {

    read( ":/res/test-board.pro" );

    return 0;

}
