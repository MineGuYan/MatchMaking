#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    this->setWindowTitle("请输入房间信息");
    socket=new QTcpSocket;
}

Client::~Client()
{
    delete ui;
    delete socket;
}

void Client::on_connect_clicked()
{
    QString IP=ui->IPLine->text();
    QString port="25565";
    //QString port=ui->PortLine->text();
    socket->connectToHost(QHostAddress(IP),port.toShort());
    connect(socket,SIGNAL(TcpSocket::connected()),this,SLOT(on_pushButton_2_clicked()));
    connect(socket,SIGNAL(TcpSocket::disconnected()),this,SLOT(on_pushButton_2_clicked()));
}


void Client::on_cancel_clicked()
{
    this->close();
}

