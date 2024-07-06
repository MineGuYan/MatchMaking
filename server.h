#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();

private slots:
    void clientConnect();

    void on_cancle_clicked();

private:
    Ui::Server *ui;
    QTcpServer *server;
    QTcpSocket *socket;
    quint16 port=25565;
};

#endif // SERVER_H
