#include "network.h"
#include "ui_network.h"

Network::Network(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Network)
{
    ui->setupUi(this);
}

Network::~Network()
{
    delete ui;
    if(client!=nullptr)delete client;
    if(server!=nullptr)delete server;
}

void Network::on_serverButton_clicked()
{
    server=new Server;
    connect(server,&Server::cancel,this,&Network::on_cancelButton_clicked);
    connect(server,&Server::succeed,[=](){
        emit SStart();
    });
    this->hide();
    server->show();
}


void Network::on_clientButton_clicked()
{
    client=new Client;
    connect(client,&Client::cancel,this,&Network::on_cancelButton_clicked);
    connect(client,&Client::succeed,[=](){
        emit CStart();
    });

    this->hide();
    client->show();
}


void Network::on_cancelButton_clicked()
{
    emit cancel();
}

