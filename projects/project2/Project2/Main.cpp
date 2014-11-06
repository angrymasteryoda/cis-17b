
#include "mainwindow.h"
#include "gamewindow.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

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
}
