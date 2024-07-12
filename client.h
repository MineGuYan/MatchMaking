#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>>

namespace Ui {
class Client;
}

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();
    QTcpSocket *socket;

signals:
    void cancel();
    void succeed();

private slots:
    void on_connect_clicked();

    void on_cancel_clicked();

private:
    Ui::Client *ui;
};

#endif // CLIENT_H
