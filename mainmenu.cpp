#include "mainmenu.h"
#include "./ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    BirdId=0;
    Music=0.5;
    MusicEffect=0.5;
    setWindowTitle("小鸟消消乐");
    setWindowIcon(QIcon(":/resorce/icon.ico"));
    intro=new Intro;
    set1=new Set_one;
    set2=new Set_two;

    soundEffect = new QSoundEffect(this);
    soundEffect->setSource(QUrl::fromLocalFile(":/resorce/Button_music.wav")); // 设置音效文件的资源路径
    // 可选：设置音量
    soundEffect->setVolume(1.0);  // 设置音量，范围为0.0到1.0

    musicEffect = new QSoundEffect(this);
    musicEffect->setSource(QUrl::fromLocalFile(":/resorce/Button_music.wav")); // 设置音效文件的资源路径
    // 可选：设置音量
    musicEffect->setVolume(MusicEffect);  // 设置音量，范围为0.0到1.0

    audioOutput=new QAudioOutput;
    music=new QMediaPlayer(this);
    music->setSource(QUrl::fromLocalFile("D:\\qt\\project\\MatchMaking\\resorce\\music.wav"));
    //music->setVolume(Music);
    music->setAudioOutput(audioOutput);
    music->setLoops(-1);
    music->play();

    connect(this->intro,&Intro::back,[=](){
        this->intro->hide();
        this->show();
    });

    connect(this->set1,&Set_one::back,[=](){
        this->set1->hide();
        this->show();
    });
    connect(this->set1,&Set_one::click_ok,[=](){
        this->BirdId=this->set1->BirdId_;
    });


    connect(this->set2,&Set_two::back,[=](){
        this->set2->hide();
        this->show();
    });
    connect(this->set2, &Set_two::Music_1, this, &MainMenu::Music_Received);
    connect(this->set2, &Set_two::Music_2, this, &MainMenu::MusicEffect_Received);
}

void MainMenu::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pixmap(":/resorce/menu.png");
    painter.drawPixmap(rect(), pixmap);
}

MainMenu::~MainMenu()
{
    delete ui;
    if(gamestart!=nullptr)delete gamestart;
    delete intro;
    delete set1;
    delete set2;
    delete soundEffect;
    delete musicEffect;
    delete music;
    delete audioOutput;
}

void MainMenu::Music_Received(int number){
    Music=number/100.0;
    audioOutput->setVolume(Music);
}

void MainMenu::MusicEffect_Received(int number){
    MusicEffect=number/100.0;
    musicEffect->setVolume(MusicEffect);
}

void MainMenu::on_Button_Singal_clicked()
{
    soundEffect->play();
    this->hide();
    switch(BirdId)
    {
    case 0:
        gamestart=new bird0;
        break;
    case 1:
        gamestart=new bird1;
        break;
    case 2:
        gamestart=new bird2;
        break;
    case 3:
        gamestart=new bird3;
        break;
    case 4:
        gamestart=new bird4;
        break;
    }
    connect(this->gamestart,&play::back,[=](){this->show();});
    gamestart->show();
}


void MainMenu::on_Button_Double_clicked()
{
    soundEffect->play();
    if(gamestart!=nullptr)delete gamestart;
    switch(BirdId)
    {
    case 0:
        gamestart=new bird0(1);
        break;
    case 1:
        gamestart=new bird1(1);
        break;
    case 2:
        gamestart=new bird2(1);
        break;
    case 3:
        gamestart=new bird3(1);
        break;
    case 4:
        gamestart=new bird4(1);
        break;
    }
    connect(gamestart->network,&Network::cancel,[=](){gamestart->network->close();});
    connect(gamestart->network,&Network::SStart,[=](){
        this->hide();
        connect(gamestart->network->server->socket,&QTcpSocket::readyRead,gamestart,&play::cpGetScore);
        gamestart->show();
        gamestart->gameStart();
    });
    connect(gamestart->network,&Network::CStart,[=](){
        this->hide();
        connect(gamestart->network->client->socket,&QTcpSocket::readyRead,gamestart,&play::cpGetScore);
        gamestart->show();
        gamestart->gameStart();
    });
    gamestart->network->show();   
}


void MainMenu::on_Button_Intro_clicked()
{
    soundEffect->play();
    this->hide();
    this->intro->show();
}


void MainMenu::on_Button_Set_one_clicked()
{
    soundEffect->play();
    this->hide();
    this->set1->show();
}


void MainMenu::on_Button_Set_two_clicked()
{
    soundEffect->play();
    this->hide();
    this->set2->show();
}
