#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server( QObject *parent = 0 );
private:
    void incomingConnection(int socketId);
};

#endif // SERVER_H
