#include "bird0.h"

bird0::bird0()
{
    People=0;
    avatar=new QLabel(this);
    role=new QLabel(this);
    skill=new QLabel(this);
    avatar->setGeometry(55,70,80,80);
    role->setGeometry(45,230,230,270);
    skill->setGeometry(305,315,40,40);
    QPixmap pixmap1(":/rc/bird0.png");
    pixmap1=pixmap1.scaled(80,80);
    avatar->setPixmap(pixmap1);
    QPixmap pixmap2(":/rc/role0.png");
    pixmap2=pixmap2.scaled(270,270);
    role->setPixmap(pixmap2);
    QPixmap pixmap3(":/rc/0.png");
    pixmap3=pixmap3.scaled(40,40);
    skill->setPixmap(pixmap3);
}

bird0::~bird0()
{
    delete avatar;
    delete role;
    delete skill;
}

void bird0::Skill()
{
    while(Num>=5)
    {
        for(int k=0;k<=1;k++)
        {
            Score+=3;
            int x=rand()%6;
            int y=rand()%6;
            for(int i=x;i<=x+1;i++)
            {
                for(int j=y;j<=y+1;j++)
                {
                    if(matrix[i][j]%5==People&&matrix[i][j]!=20)Num++;
                    if(matrix[i][j]<5)
                    {
                        matrix[i][j] = -1;
                        Score++;
                    }
                    else if (matrix[i][j] / 5 == 1)
                    {
                        matrix[i][j] = -1;
                        Score++;
                        Skillone(j);
                    }
                    else if (matrix[i][j] / 5 == 2)
                    {
                        matrix[i][j] = -1;
                        Score++;
                        Skilltwo(i);
                    }
                    else if(matrix[i][j] / 5 == 3)
                    {
                        matrix[i][j] = -1;
                        Score++;
                        Skillthree(i,j);
                    }
                }
            }
        }
        Num-=5;
        fall();
        skilltext->setText(QString::number(Num));
    }
}
