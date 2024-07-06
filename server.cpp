#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Server)
{
    ui->setupUi(this);
    this->setWindowTitle("等待客户端连接中");
    server=new QTcpServer;
    server->listen(QHostAddress::AnyIPv4,port);
    connect(server,SIGNAL(QTcpServer::newConnection()),this,SLOT(Server::clientConnect()));
}

Server::~Server()
{
    delete ui;
    delete server;
}

void Server::clientConnect()
{
    socket=server->nextPendingConnection();
}
void Server::on_cancle_clicked()
{
    this->close();
}

