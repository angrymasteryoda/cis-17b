#include <QApplication>
#include <QtGui>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>

#include "mainwindow.h"

/*
void test( QNetworkReply *reply ){
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        return;
    }

    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    label->setPixmap(pixmap); // or whatever your labels name is
}
*/
int main( int argc, char* argv[] ){
    QApplication app( argc, argv );
    MainWindow w;
    w.show();
    return app.exec();
}
