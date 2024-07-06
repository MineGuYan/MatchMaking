#ifndef NETWORK_H
#define NETWORK_H

#include <QWidget>

namespace Ui {
class Network;
}

class Network : public QWidget
{
    Q_OBJECT

public:
    explicit Network(QWidget *parent = nullptr);
    ~Network();

private:
    Ui::Network *ui;
};

#endif // NETWORK_H
