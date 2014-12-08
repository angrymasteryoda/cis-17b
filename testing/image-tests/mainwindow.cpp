#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QDesktopServices>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->label->setScaledContents( true );
    QNetworkAccessManager *netMan = new QNetworkAccessManager( this );
    connect( netMan, SIGNAL( finished( QNetworkReply* ) ), this, SLOT( test( QNetworkReply* ) ) );

    QUrl url( "http://www.qtcentre.org/images/qtcentre/qt/Nokia_Certified_Qt_Developer_button.png" );
    QNetworkRequest request( url );
    netMan->get( request );

    //QPixmap pic( "C:/Users/Michael/Desktop/Michael Stuff/pics/logo1.png" );
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::test( QNetworkReply *reply){
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        return;
    }

    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    ui->label->setPixmap(pixmap); // or whatever your labels name is

}

void MainWindow::on_label_2_linkActivated(const QString &link) {
    QDesktopServices::openUrl( link );
}
