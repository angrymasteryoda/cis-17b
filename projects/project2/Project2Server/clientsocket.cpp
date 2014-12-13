#include <QtNetwork>

#include "clientsocket.h"

ClientSocket::ClientSocket( QObject *parent ) : QTcpSocket(parent)  {


    connect(this, SIGNAL(readyRead()), this, SLOT(readClient()));
    connect(this, SIGNAL(disconnected()), this, SLOT(deleteLater()));

    nextBlockSize = 0;
}

void ClientSocket::readClient(){
    QDataStream in( this );
    in.setVersion( QDataStream::Qt_4_8 );

    if ( nextBlockSize == 0 ) {
        if ( bytesAvailable() < sizeof( quint16 ))
            return;
        in >> nextBlockSize;
    }

    if ( bytesAvailable() < nextBlockSize)
        return;

    quint8 requestType;

    in >> requestType;
    if (requestType == 'S') {
        int num = rand() % 8 + 1;
        for( int i = 0; i < num; i++ ){
            generateScores();
        }
        QDataStream out(this);
        out << quint16(0xFFFF);


        /*
        std::srand(from.length() * 3600 + to.length() * 60
                   + time.hour());
        int numTrips = std::rand() % 8;
        for (int i = 0; i < numTrips; ++i)
            generateRandomTrip(from, to, date, time);

        QDataStream out(this);
        out << quint16(0xFFFF);
        */
    }

    close();
}

void ClientSocket::generateScores(){
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    QString name = genName(9);
    quint16 duration = std::rand() % 200;
    out << quint16(0) << name << duration;
    out.device()->seek(0);
    out << quint16( block.size() - sizeof( quint16 ) );
    write( block );
}

QString ClientSocket::genName( int len ){
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    QString s;
    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return s;
}


/*
void ClientSocket::generateRandomTrip(const QString &  from,
        const QString &  to , const QDate &date, const QTime &time) {
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);
    quint16 duration = std::rand() % 200;
    out << quint16(0) << date << time << duration << quint8(1)
        << QString("InterCity");
    out.device()->seek(0);
    out << quint16(block.size() - sizeof(quint16));
    write( block );
}
*/
