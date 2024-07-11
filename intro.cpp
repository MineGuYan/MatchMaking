#include "intro.h"
#include "ui_intro.h"

Intro::Intro(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Intro)
{
    ui->setupUi(this);
    setWindowTitle("小鸟消消乐");
    setWindowIcon(QIcon("D:\\qt\\MatchMaking\\resorce\\icon.ico"));

    IntroId=1;

    QIcon icon_image(":/resorce/intro1.png");
    ui->Image->setIcon(icon_image);
    ui->Image->setIconSize(QSize(800,480));

    soundEffect = new QSoundEffect(this);
    soundEffect->setSource(QUrl::fromLocalFile(":/resorce/Button_music.wav")); // 设置音效文件的资源路径
    // 可选：设置音量
    soundEffect->setVolume(1.0);  // 设置音量，范围为0.0到1.0
}

Intro::~Intro()
{
    delete ui;
}

void Intro::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pixmap(":/resorce/bg.png");
    painter.drawPixmap(rect(), pixmap);
}

void Intro::on_Button_main_clicked()
{
    soundEffect->play();
    emit this->back();
}


void Intro::on_Button_left_clicked()
{
    soundEffect->play();
    if(IntroId==1)
    {
        QIcon icon_image(":/resorce/intro4.png");
        ui->Image->setIcon(icon_image);
        ui->Image->setIconSize(QSize(800,480));
        IntroId=4;
    }
    else if(IntroId==2)
    {
        QIcon icon_image(":/resorce/intro1.png");
        ui->Image->setIcon(icon_image);
        ui->Image->setIconSize(QSize(800,480));
        IntroId=1;
    }
    else if(IntroId==3)
    {
        QIcon icon_image(":/resorce/intro2.png");
        ui->Image->setIcon(icon_image);
        ui->Image->setIconSize(QSize(800,480));
        IntroId=2;
    }
    else if(IntroId==4)
    {
        QIcon icon_image(":/resorce/intro3.png");
        ui->Image->setIcon(icon_image);
        ui->Image->setIconSize(QSize(800,480));
        IntroId=3;
    }
}


void Intro::on_Button_right_clicked()
{
    soundEffect->play();
    if(IntroId==1)
    {
        QIcon icon_image(":/resorce/intro2.png");
        ui->Image->setIcon(icon_image);
        ui->Image->setIconSize(QSize(800,480));
        IntroId=2;
    }
    else if(IntroId==2)
    {
        QIcon icon_image(":/resorce/intro3.png");
        ui->Image->setIcon(icon_image);
        ui->Image->setIconSize(QSize(800,480));
        IntroId=3;
    }
    else if(IntroId==3)
    {
        QIcon icon_image(":/resorce/intro4.png");
        ui->Image->setIcon(icon_image);
        ui->Image->setIconSize(QSize(800,480));
        IntroId=4;
    }
    else if(IntroId==4)
    {
        QIcon icon_image(":/resorce/intro1.png");
        ui->Image->setIcon(icon_image);
        ui->Image->setIconSize(QSize(800,480));
        IntroId=1;
    }
}

