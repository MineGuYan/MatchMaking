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
    QTcpServer *server;
    QTcpSocket *socket;
    quint16 port=25565;

signals:
    void cancel();
    void succeed();

private slots:
    void clientConnect();

    void on_cancle_clicked();

private:
    Ui::Server *ui;    
};

#endif // SERVER_H
