#ifndef NETWORK_H
#define NETWORK_H

#include <QWidget>
#include "client.h"
#include "server.h"

namespace Ui {
class Network;
}

class Network : public QWidget
{
    Q_OBJECT

public:
    explicit Network(QWidget *parent = nullptr);
    ~Network();
    Client *client=nullptr;
    Server *server=nullptr;

signals:
    void cancel();
    void SStart();
    void CStart();

private slots:
    void on_serverButton_clicked();

    void on_clientButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::Network *ui;
};

#endif // NETWORK_H
