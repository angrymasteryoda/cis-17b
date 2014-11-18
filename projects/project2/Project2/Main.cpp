#include "database.h"
#include "mainwindow.h"
#include "gamewindow.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <QtSql>

int random( int max, int min = 0 );

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    srand( time(NULL) );

    //data base test

//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("127.0.0.1");
//    db.setDatabaseName("48597");
//    db.setUserName("michael");
//    db.setPassword("mrisher");
//    if (!db.open()) {
//        return 255;
//    }

//    QSqlQuery derp;
//    derp.exec( "SELECT * FROM news_header" );
//    while( derp.next() ){
//        qDebug() << derp.value( 0 ).toString();
//    }
//    db.close();
    Database db;
    db.connect();
    db.createTable( "CREATE TABLE test(id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30))" );
    db.close();
    return 0;


    /*
    //set looks
    QFile File(":/res/css/style.css");
    if( !File.open( QFile::ReadOnly | QFile::Text ) ){
        qDebug() << "Could not read file";
    }
    QTextStream in( &File );
    QString style = in.readAll();
    app.setStyle( "plastique" );
    app.setStyleSheet( style );

    MainWindow w;
    w.show();

    return app.exec();
    //*/
}
