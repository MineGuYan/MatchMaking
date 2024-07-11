#include "bird2.h"

bird2::bird2()
{
    People=2;
    avatar=new QLabel(this);
    role=new QLabel(this);
    skill=new QLabel(this);
    avatar->setGeometry(55,70,80,80);
    role->setGeometry(45,230,230,270);
    skill->setGeometry(305,315,40,40);
    QPixmap pixmap1(":/rc/bird2.png");
    pixmap1=pixmap1.scaled(80,80);
    avatar->setPixmap(pixmap1);
    QPixmap pixmap2(":/rc/role2.png");
    pixmap2=pixmap2.scaled(270,270);
    role->setPixmap(pixmap2);
    QPixmap pixmap3(":/rc/2.png");
    pixmap3=pixmap3.scaled(40,40);
    skill->setPixmap(pixmap3);
}

bird2::~bird2()
{    
    delete avatar;
    delete role;
    delete skill;
}

void bird2::Skill()
{
    while(Num>=5)
    {
        for(int i=0;i<4;i++)
        {
            int x=rand()%7;
            int y=rand()%7;
            while(matrix[x][y]>=5)
            {
                x=rand()%7;
                y=rand()%7;
            }
            int size=rand()%2;           
            if(size)
            {
                matrix[x][y]+=5;
            }
            else matrix[x][y]+=10;
        }
        Num-=5;
        skilltext->setText(QString::number(Num));
        draw();
    }
}
