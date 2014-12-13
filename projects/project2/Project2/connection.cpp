#include <QtGui>
#include <QtNetwork>

#include "connection.h"
#include "ui_connection.h"

Connection::Connection(QWidget *parent) : QDialog(parent), ui(new Ui::Connection) {
    ui->setupUi(this);

    connect( ui->get, SIGNAL( clicked() ), this, SLOT(connectToServer()) );
    connect( ui->stop, SIGNAL( clicked() ), this, SLOT( stopConnection() ) );
    connect(&tcpSocket, SIGNAL( connected() ), this, SLOT(sendRequest()));
    connect(&tcpSocket, SIGNAL( disconnected() ), this, SLOT( connectionClosedByServer() ) );
    connect(&tcpSocket, SIGNAL( readyRead() ), this, SLOT( updateUI() ) );
    connect(&tcpSocket, SIGNAL( error( QAbstractSocket::SocketError ) ), this, SLOT( error() ) );
}

Connection::~Connection(){
    delete ui;
}

void Connection::connectToServer(){
#if 1
    tcpSocket.connectToHost( QHostAddress::LocalHost, 6178);
#endif
    ui->get->setDisabled( true );
    ui->stop->setDisabled( false );
    nextBlockSize = 0;
}

void Connection::sendRequest(){
    QByteArray block;
    QDataStream out( &block, QIODevice::WriteOnly );
    out.setVersion( QDataStream::Qt_4_8 );
    out << quint16(0) << quint8('S');
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    tcpSocket.write(block);
}

void Connection::updateUI(){
    QDataStream in(&tcpSocket);
    in.setVersion(QDataStream::Qt_4_8);

    forever {
        int row = ui->tableWidget->rowCount();

        if (nextBlockSize == 0) {
            if (tcpSocket.bytesAvailable() < sizeof(quint16))
                break;
            in >> nextBlockSize;
        }

        if (nextBlockSize == 0xFFFF) {
            closeConnection();
            break;
        }

        if (tcpSocket.bytesAvailable() < nextBlockSize)
            break;

        QString name;
        quint16 duration;

        in >> name >> duration;

        ui->tableWidget->setRowCount( row + 1 );

        QStringList fields;
        fields << name << QString::number( duration );
        for( int i = 0; i < fields.count(); ++i ){
            ui->tableWidget->setItem( row, i, new QTableWidgetItem( fields[i] ) );
        }
        nextBlockSize = 0;
    }
}


void Connection::closeConnection() {
    tcpSocket.close();
}

void Connection::connectionClosedByServer(){
    if (nextBlockSize != 0xFFFF)
        qDebug() << "Error: Connection closed by server";
    closeConnection();
}

void Connection::stopConnection(){
    ui->get->setDisabled( false );
    ui->stop->setDisabled( true );
    closeConnection();
}

void Connection::error() {
    qDebug() << tcpSocket.errorString();
    closeConnection();
}

