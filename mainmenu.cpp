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

    connect(this->gamestart,&play::back,this,[=](){
        qDebug()<<"2";
        this->show();
    });
}

void MainMenu::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pixmap("D:\\GitHubRemoteRepositories\\MatchMaking\\resorce\\开始菜单.png");
    painter.drawPixmap(rect(), pixmap);
}

MainMenu::~MainMenu()
{
    delete ui;
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
    if(gamestart!=nullptr)delete gamestart;
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
    gamestart->show();
}


void MainMenu::on_Button_Double_clicked()
{
    soundEffect->play();
    this->hide();
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

