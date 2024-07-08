#include "play.h"
#include "ui_play.h"

play::play(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::play)
{
    srand(time(0));
    ui->setupUi(this);   
    this->setWindowTitle("小鸟消消乐");
    ui->bg->setPixmap(QPixmap(":/rc/bg.png"));
    fruit=new QPushButton[49];
    for(int i=0;i<49;i++)
    {
        fruit[i].setParent(this);
        auto func = std::bind(&play::swap, this, i);
        connect(&fruit[i], &QPushButton::clicked, func);
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
            QString path=":/rc/";
            path+=QString::number(matrix[i][j]);
            path+=".png";
            fruit[i*7+j].setIcon(QIcon(path));
            fruit[i*7+j].setIconSize(QSize(70,70));
            fruit[i*7+j].move(360+i*80,80+j*80);
        }
    this->repaint();
    QTest::qSleep(100);
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
        fruit[i].setStyleSheet(sel);
        Selected=i;
    }
    else
    {
        int sx=Selected/7,sy=Selected%7,ix=i/7,iy=i%7;
        if(sx==ix&&sy==iy)
        {
            fruit[Selected].setStyleSheet(nor);
            Selected=-1;
        }
        else if(abs(sx-ix)+abs(sy-iy)==1)
        {
            int tem=matrix[sx][sy];
            matrix[sx][sy]=matrix[ix][iy];
            matrix[ix][iy]=tem;
            fruit[Selected].setStyleSheet(nor);
            int vectorx=ix-sx,vectory=iy-sy;
            for(int Distance=1;Distance<=40;Distance++)
            {
                fruit[i].move(360+ix*80-Distance*vectorx*2,80+iy*80-Distance*vectory*2);
                fruit[Selected].move(360+sx*80+Distance*vectorx*2,80+sy*80+Distance*vectory*2);
                this->repaint();
            }

            Selected=-1;            
            if(Judge())
            {
                matrix[ix][iy]=matrix[sx][sy];
                matrix[sx][sy]=tem;
            }
            draw();
        }
        else
        {
            fruit[i].setStyleSheet(sel);
            fruit[Selected].setStyleSheet(nor);
            Selected=i;
        }
    }
}

void play::Skillone(int y)
{
    for (int i = 0; i < 7; i++)
    {
        if(matrix[i][y]%5==People&&matrix[i][y]!=20)Num++;
        if(matrix[i][y]<5)
        {
            matrix[i][y] = -1;
        }
        else if (matrix[i][y] / 5 == 1)
        {
            matrix[i][y] = -1;
            Skillone(y);
        }
        else if (matrix[i][y] / 5 == 2)
        {
            matrix[i][y] = -1;
            Skilltwo(i);
        }
        else if(matrix[i][y]/5==3)
        {
            matrix[i][y] = -1;
            Skillthree(i,y);
        }
    }
}
void play:: Skilltwo(int x)
{
    for (int j = 0; j < 7; j++)
    {
        if(matrix[x][j]%5==People&&matrix[x][j]!=20)Num++;
        if(matrix[x][j]<5)
        {
            matrix[x][j] = -1;
        }
        else if (matrix[x][j] / 5 == 1)
        {
            matrix[x][j] = -1;
            Skillone(j);
        }
        else if (matrix[x][j] / 5 == 2)
        {
            matrix[x][j] = -1;
            Skilltwo(x);
        }
        else if(matrix[x][j]/5==3)
        {
            matrix[x][j] = -1;
            Skillthree(x,j);
        }
    }
}
void play::Skillthree(int x,int y)
{
    for(int i=(x-1>0?x-1:0);i<=(x+1>6?6:x+1);i++)
        for(int j=(y-1>0?y-1:0);j<(y+1>6?6:y+1);j++)
        {
            if(matrix[i][j]%5==People&&matrix[i][j]!=20)Num++;
            if(matrix[i][j]<5)
            {
                matrix[i][j] = -1;
            }
            else if (matrix[i][j] / 5 == 1)
            {
                matrix[i][j] = -1;
                Skillone(j);
            }
            else if (matrix[i][j] / 5 == 2)
            {
                matrix[i][j] = -1;
                Skilltwo(i);
            }
            else if (matrix[i][j] / 5 == 3)
            {
                matrix[i][j] = -1;
                Skillthree(i,j);
            }
        }
}

int play::Judgecolumn(int x,int y,int num)
{
    int columnNum=0;
    int starty;
    int flag=0;
    if(y!=0){
        starty=y-1;
        while(starty>=0)
        {
            if(matrix[x][starty]%5==num&&matrix[x][starty]!=20)
                columnNum++;
            else break;
            starty--;
        }
    }
    if(y!=6)
    {
        starty=y+1;
        while(starty<=6)
        {
            if(matrix[x][starty]%5==num&&matrix[x][starty]!=20)
                columnNum++;
            else break;
            starty++;
        }
    }
    if(columnNum>=2)
    {
        flag=1;
        if(y!=0){
            starty=y-1;
            while(starty>=0)
            {
                if(matrix[x][starty]%5==num&&matrix[x][starty]!=20)
                {
                    matrix[x][starty]=-1;
                    if(num==People)Num++;
                }
                else break;
                starty--;
            }
        }
        if(y!=6)
        {
            starty=y+1;
            while(starty<=6)
            {
                if(matrix[x][starty]%5==num&&matrix[x][starty]!=20)
                {
                    matrix[x][starty]=-1;
                    if(num==People)Num++;
                }
                else break;
                starty++;
            }
        }
    }
    return flag;
}

int play::Judgerow(int x,int y,int num)
{
    int rowNum=0;
    int startx;
    int flag=0;
    if(x!=0){
        startx=x-1;
        while(startx>=0)
        {
            if(matrix[startx][y]%5==num&&matrix[startx][y]!=20)
                rowNum++;
            else break;
            startx--;
        }
    }
    if(x!=6)
    {
        startx=x+1;
        while(startx<=6)
        {
            if(matrix[startx][y]%5==num&&matrix[startx][y]!=20)
                rowNum++;
            else break;
            startx++;
        }
    }
    if(rowNum>=2)
    {
        flag=1;
        if(x!=0){
            startx=x-1;
            while(startx>=0)
            {
                if(matrix[startx][y]%5==num&&matrix[startx][y]!=20)
                {
                    matrix[startx][y]=-1;
                    if(num==People)Num++;
                }
                else break;
                startx--;
            }
        }
        if(x!=6)
        {
            startx=x+1;
            while(startx<=6)
            {
                if(matrix[startx][y]%5==num&&matrix[startx][y]!=20)
                {
                    matrix[startx][y]=-1;
                    if(num==People)Num++;
                }
                else break;
                startx++;
            }
        }
    }
    return flag;
}

void play:: Delete1(int x,int y,int num)
{
    int startx = x-1;
    int number = 0;
    int flag=0;//判断列的
    while (startx <= 6)
    {
        if (matrix[startx][y]%5 == num&&matrix[startx][y]!=20)
        {
            number++;
            flag+=Judgecolumn(startx,y,num);
            if(matrix[startx][y]<5)
            {
                if(matrix[startx][y]==People)Num++;
                matrix[startx][y] = -1;
            }
            else if ((matrix[startx][y] - num) / 5 == 1)
            {
                Skillone(y);
            }
            else if ((matrix[startx][y] - num) / 5 == 2)
            {
                Skilltwo(startx);
            }
            else if((matrix[startx][y] - num) / 5 == 3)
            {
                Skillthree(startx,y);
            }
            startx++;
        }
        else break;
    }
    if(number==3)
    {
        if(flag>=1)matrix[x][y]=num+15;
    }
    else if (number == 4)
    {
        if(flag>=1)matrix[x][y]=num+15;
        else matrix[x][y]=num+10;
    }
    else if (number >= 5)
    {
        matrix[x][y] = 20;
    }
    fall();
}

void play:: Delete2(int x, int y,int num)
{
    int starty = y-1;
    int number = 0;
    int flag=0;//判断行的
    while (starty <= 6)
    {
        if (matrix[x][starty]%5 == num&&matrix[x][starty]!=20)
        {
            number++;
            flag+=Judgerow(x,starty,num);
            if(matrix[x][starty]<5)
            {
                if(matrix[x][starty]==People)Num++;
                matrix[x][starty] = -1;
            }
            else if ((matrix[x][starty] - num) / 5 == 1)
            {
                Skillone(starty);
            }
            else if ((matrix[x][starty] - num) / 5 == 2)
            {
                Skilltwo(x);
            }
            else if((matrix[x][starty] - num) / 5 == 3)
            {
                Skillthree(x,starty);
            }
            starty++;
        }
        else break;
    }
    if(number==3)
    {
        if(flag>=1)matrix[x][y]=num+15;
    }
    else if (number == 4)
    {
        if(flag>=1)matrix[x][y]=num+15;
        else matrix[x][y]=num+5;
    }
    else if (number >= 5)
    {
        matrix[x][y] = 20;
    }
    fall();
}

bool play:: Judge()
{
    for(int i=0;i<7;i++)
        for(int j=0;j<5;j++)
            if(matrix[i][j]%5==matrix[i][j+1]%5&&matrix[i][j]%5==matrix[i][j+2]%5)
            {
                if(matrix[i][j]!=20&&matrix[i][j+1]!=20&&matrix[i][j+2]!=20)
                {
                    Delete2(i,j+1,matrix[i][j]%5);
                       return false;
                }
            }
    for(int j=0;j<7;j++)
        for(int i=0;i<5;i++)
            if(matrix[i][j]%5==matrix[i+1][j]%5&&matrix[i][j]%5==matrix[i+2][j]%5)
            {
                if(matrix[i][j]!=20&&matrix[i+1][j]!=20&&matrix[i+2][j]!=20)
                {
                    Delete1(i+1,j,matrix[i][j]%5);
                    return false;
                }
            }
    return true;
}
void play::fall()
{
    draw();
    for (int i = 0; i < 7; i++)
    {
        for (int j = 6; j >= 0; j--)
        {
            if (matrix[i][j] == -1)
            {
                if(j)
                {
                    for (int p = j; p > 0; p--)
                    {
                        matrix[i][p] = matrix[i][p-1];
                    }
                    matrix[i][0] = rand()%5;                    
                    j++;
                    draw();
                }
                else {
                    matrix[i][0] = rand()%5;
                    draw();
                }
            }
        }
    }
    Judge();
}
