#include <QtCore>

#include "clientsocket.h"
#include "server.h"

Server::Server( QObject *parent) : QTcpServer(parent){

}

void Server::incomingConnection(int socketId)
{
    ClientSocket *socket = new ClientSocket(this);
    socket->setSocketDescriptor(socketId);
}
