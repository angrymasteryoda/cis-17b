#ifndef CONNECTION_H
#define CONNECTION_H

#include <QTcpSocket>
#include <QDialog>

namespace Ui {
class Connection;
}

class Connection : public QDialog
{
    Q_OBJECT

public:
    explicit Connection(QWidget *parent = 0);
    ~Connection();

private slots:
    void connectToServer();
    void sendRequest();
    void updateUI();
    void connectionClosedByServer();
    void error();
    void stopConnection();

private:
    Ui::Connection *ui;
    void closeConnection();

    QTcpSocket tcpSocket;
    quint16 nextBlockSize;
};

#endif // CONNECTION_H
