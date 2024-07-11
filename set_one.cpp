#include "set_one.h"
#include "ui_set_one.h"

Set_one::Set_one(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Set_one)
{
    ui->setupUi(this);
    BirdId_=1;

    QIcon icon_1(":/resorce/小鸟1.png");
    ui->Image_1->setIcon(icon_1);
    ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
    QIcon icon_2(":/resorce/小鸟1技能.png");
    ui->Image_2->setIcon(icon_2);
    ui->Image_2->setIconSize(QSize(W_2,HEIGHT));

    QIcon icon(":resorce/小鸟选择按钮/开拓.png");
    ui->Button_me->setIcon(icon);
    ui->Button_me->setIconSize(QSize(WHIDE,WHIDE));

    setWindowTitle("小鸟消消乐");
    setWindowIcon(QIcon(":/resorce/icon.ico"));

    soundEffect = new QSoundEffect(this);
    soundEffect->setSource(QUrl::fromLocalFile(":/resorce/Button_music.wav")); // 设置音效文件的资源路径
    // 可选：设置音量
    soundEffect->setVolume(1.0);  // 设置音量，范围为0.0到1.0

}

Set_one::~Set_one()
{
    delete ui;
}

void Set_one::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pixmap(":/resorce/bg.png");
    painter.drawPixmap(rect(), pixmap);
}


void Set_one::on_Button_main_clicked()
{
    soundEffect->play();
    emit this->back();
}


void Set_one::on_Button_1_clicked()
{
    soundEffect->play();
    QIcon icon_1(":/resorce/小鸟1.png");
    ui->Image_1->setIcon(icon_1);
    ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
    QIcon icon_2(":/resorce/小鸟1技能.png");
    ui->Image_2->setIcon(icon_2);
    ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
    BirdId_=0;
}


void Set_one::on_Button_2_clicked()
{
    soundEffect->play();
    QIcon icon_1(":/resorce/小鸟4.png");
    ui->Image_1->setIcon(icon_1);
    ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
    QIcon icon_2(":/resorce/小鸟4技能.png");
    ui->Image_2->setIcon(icon_2);
    ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
    BirdId_=3;
}


void Set_one::on_Button_3_clicked()
{
    soundEffect->play();
    QIcon icon_1(":/resorce/小鸟3.png");
    ui->Image_1->setIcon(icon_1);
    ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
    QIcon icon_2(":/resorce/小鸟3技能.png");
    ui->Image_2->setIcon(icon_2);
    ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
    BirdId_=2;
}


void Set_one::on_Button_4_clicked()
{
    soundEffect->play();
    QIcon icon_1(":/resorce/小鸟2.png");
    ui->Image_1->setIcon(icon_1);
    ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
    QIcon icon_2(":/resorce/小鸟2技能.png");
    ui->Image_2->setIcon(icon_2);
    ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
    BirdId_=1;
}


void Set_one::on_Button_5_clicked()
{
    soundEffect->play();
    QIcon icon_1(":/resorce/小鸟5.png");
    ui->Image_1->setIcon(icon_1);
    ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
    QIcon icon_2(":/resorce/小鸟5技能.png");
    ui->Image_2->setIcon(icon_2);
    ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
    BirdId_=4;
}
void Set_one::on_Button_left_clicked()
{
    soundEffect->play();
    if(BirdId_==0)
    {
        QIcon icon_1(":/resorce/小鸟5.png");
        ui->Image_1->setIcon(icon_1);
        ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
        QIcon icon_2(":/resorce/小鸟5技能.png");
        ui->Image_2->setIcon(icon_2);
        ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
        BirdId_=4;
    }
    else if(BirdId_==1)
    {
        QIcon icon_1(":/resorce/小鸟1.png");
        ui->Image_1->setIcon(icon_1);
        ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
        QIcon icon_2(":/resorce/小鸟1技能.png");
        ui->Image_2->setIcon(icon_2);
        ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
        BirdId_=0;
    }
    else if(BirdId_==2)
    {
        QIcon icon_1(":/resorce/小鸟2.png");
        ui->Image_1->setIcon(icon_1);
        ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
        QIcon icon_2(":/resorce/小鸟2技能.png");
        ui->Image_2->setIcon(icon_2);
        ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
        BirdId_=1;
    }
    else if(BirdId_==3)
    {
        QIcon icon_1(":/resorce/小鸟3.png");
        ui->Image_1->setIcon(icon_1);
        ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
        QIcon icon_2(":/resorce/小鸟3技能.png");
        ui->Image_2->setIcon(icon_2);
        ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
        BirdId_=2;
    }
    else if(BirdId_==4)
    {
        QIcon icon_1(":/resorce/小鸟4.png");
        ui->Image_1->setIcon(icon_1);
        ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
        QIcon icon_2(":/resorce/小鸟4技能.png");
        ui->Image_2->setIcon(icon_2);
        ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
        BirdId_=3;
    }
}


void Set_one::on_Button_right_clicked()
{
    soundEffect->play();
    if(BirdId_==0)
    {
        QIcon icon_1(":/resorce/小鸟2.png");
        ui->Image_1->setIcon(icon_1);
        ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
        QIcon icon_2(":/resorce/小鸟2技能.png");
        ui->Image_2->setIcon(icon_2);
        ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
    }
    else if(BirdId_==1)
    {
        QIcon icon_1(":/resorce/小鸟3.png");
        ui->Image_1->setIcon(icon_1);
        ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
        QIcon icon_2(":/resorce/小鸟3技能.png");
        ui->Image_2->setIcon(icon_2);
        ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
    }
    else if(BirdId_==2)
    {
        QIcon icon_1(":/resorce/小鸟4.png");
        ui->Image_1->setIcon(icon_1);
        ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
        QIcon icon_2(":/resorce/小鸟4技能.png");
        ui->Image_2->setIcon(icon_2);
        ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
    }
    else if(BirdId_==3)
    {
        QIcon icon_1(":/resorce/小鸟5.png");
        ui->Image_1->setIcon(icon_1);
        ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
        QIcon icon_2(":/resorce/小鸟5技能.png");
        ui->Image_2->setIcon(icon_2);
        ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
    }
    else if(BirdId_==4)
    {
        QIcon icon_1(":/resorce/小鸟1.png");
        ui->Image_1->setIcon(icon_1);
        ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
        QIcon icon_2(":/resorce/小鸟1技能.png");
        ui->Image_2->setIcon(icon_2);
        ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
    }
    BirdId_=(BirdId_+1)%5;
}


void Set_one::on_Button_ok_clicked()
{
    soundEffect->play();
    if(BirdId_==0)
    {
        QIcon icon(":resorce/小鸟选择按钮/开拓.png");
        ui->Button_me->setIcon(icon);
        ui->Button_me->setIconSize(QSize(WHIDE,WHIDE));
    }
    else if(BirdId_==1)
    {
        QIcon icon(":resorce/小鸟选择按钮/银狼.png");
        ui->Button_me->setIcon(icon);
        ui->Button_me->setIconSize(QSize(WHIDE,WHIDE));
    }
    else if(BirdId_==2)
    {
        QIcon icon(":resorce/小鸟选择按钮/三月.png");
        ui->Button_me->setIcon(icon);
        ui->Button_me->setIconSize(QSize(WHIDE,WHIDE));
    }
    else if(BirdId_==3)
    {
        QIcon icon(":resorce/小鸟选择按钮/流萤.png");
        ui->Button_me->setIcon(icon);
        ui->Button_me->setIconSize(QSize(WHIDE,WHIDE));
    }
    else if(BirdId_==4)
    {
        QIcon icon(":resorce/小鸟选择按钮/知更.png");
        ui->Button_me->setIcon(icon);
        ui->Button_me->setIconSize(QSize(WHIDE,WHIDE));
    }
    MyId=BirdId_;
    emit this->click_ok();
}


void Set_one::on_Button_me_clicked()
{
    soundEffect->play();
    if(MyId==0)
    {
        QIcon icon_1(":/resorce/小鸟1.png");
        ui->Image_1->setIcon(icon_1);
        ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
        QIcon icon_2(":/resorce/小鸟1技能.png");
        ui->Image_2->setIcon(icon_2);
        ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
    }
    else if(MyId==1)
    {
        QIcon icon_1(":/resorce/小鸟2.png");
        ui->Image_1->setIcon(icon_1);
        ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
        QIcon icon_2(":/resorce/小鸟2技能.png");
        ui->Image_2->setIcon(icon_2);
        ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
    }
    else if(MyId==2)
    {
        QIcon icon_1(":/resorce/小鸟3.png");
        ui->Image_1->setIcon(icon_1);
        ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
        QIcon icon_2(":/resorce/小鸟3技能.png");
        ui->Image_2->setIcon(icon_2);
        ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
    }
    else if(MyId==3)
    {
        QIcon icon_1(":/resorce/小鸟4.png");
        ui->Image_1->setIcon(icon_1);
        ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
        QIcon icon_2(":/resorce/小鸟4技能.png");
        ui->Image_2->setIcon(icon_2);
        ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
    }
    else if(MyId==4)
    {
        QIcon icon_1(":/resorce/小鸟5.png");
        ui->Image_1->setIcon(icon_1);
        ui->Image_1->setIconSize(QSize(W_1,HEIGHT));
        QIcon icon_2(":/resorce/小鸟5技能.png");
        ui->Image_2->setIcon(icon_2);
        ui->Image_2->setIconSize(QSize(W_2,HEIGHT));
    }
}

