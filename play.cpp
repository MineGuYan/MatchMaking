#include "play.h"
#include "ui_play.h"

play::play(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::play)
{
    ui->setupUi(this);
    this->setWindowTitle("小鸟消消乐");
    //fruit=new QLabel[49];
    fruit=new QPushButton[49];
    srand(time(0));
    for(int index=0;index<49;index++)
    {
        auto func = std::bind(&play::swap, this, index);
        connect(&fruit[index], &QPushButton::clicked, func);
    }
    do
    {
        for(int i=0;i<7;i++)
            for(int j=0;j<7;j++)
                matrix[i][j]=rand()%5;
    }while(judgeStart());
    draw();

}

play::~play()
{
    delete ui;
    delete[] fruit;
}

void play::draw()
{
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
        {
            QString path="D:\\Qt\\Project\\MatchMaking\\rc\\";
            path+=QString::number(matrix[i][j]);
            path+=".png";
            //fruit[i*7+j].setPixmap(QPixmap(path));
            fruit[i*7+j].setIcon(QIcon(path));
            fruit[i*7+j].setIconSize(QSize(70,70));
            ui->Grid->addWidget(&fruit[i*7+j], i, j);
        }
}

bool play::judgeStart()
{
    for(int i=0;i<7;i++)
        for(int j=0;j<5;j++)
            if(matrix[i][j]==matrix[i][j+1]&&matrix[i][j]==matrix[i][j+2])return true;
    for(int j=0;j<7;j++)
        for(int i=0;i<5;i++)
            if(matrix[i][j]==matrix[i+1][j]&&matrix[i][j]==matrix[i+2][j])return true;
    return false;
}

void play::swap(int i)
{
    if(Selected==-1)
    {
        //fruit[i].setIconSize(QSize(80,80));
        Selected=i;
    }
    else
    {
        int sx=Selected/7,sy=Selected%7,ix=i/7,iy=i%7;
        if(sx==ix&&sy==iy)
        {
            //fruit[i].setIconSize(QSize(70,70));
            Selected=-1;
        }
        else if(abs(sx-ix)+abs(sy-iy)==1)
        {
            int tem=matrix[sx][sy];
            matrix[sx][sy]=matrix[ix][iy];
            matrix[ix][iy]=tem;
            Selected=-1;
            draw();
        }
        else
        {
            //fruit[i].setIconSize(QSize(80,80));
            Selected=i;
        }
    }
}
