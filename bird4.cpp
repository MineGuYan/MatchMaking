#include "bird4.h"

bird4::bird4()
{
    People=4;
    avatar=new QLabel(this);
    role=new QLabel(this);
    skill=new QLabel(this);
    avatar->setGeometry(55,70,80,80);
    role->setGeometry(45,230,230,270);
    skill->setGeometry(305,315,40,40);
    QPixmap pixmap1(":/rc/bird4.png");
    pixmap1=pixmap1.scaled(80,80);
    avatar->setPixmap(pixmap1);
    QPixmap pixmap2(":/rc/role4.png");
    pixmap2=pixmap2.scaled(270,270);
    role->setPixmap(pixmap2);
    QPixmap pixmap3(":/rc/4.png");
    pixmap3=pixmap3.scaled(40,40);
    skill->setPixmap(pixmap3);
    nextbg->raise();
    nexttext->raise();
    gameStart();
}

bird4::bird4(int)
{
    network=new Network;
    People=4;
    avatar=new QLabel(this);
    role=new QLabel(this);
    skill=new QLabel(this);
    avatar->setGeometry(55,70,80,80);
    role->setGeometry(45,230,230,270);
    skill->setGeometry(305,315,40,40);
    QPixmap pixmap1(":/rc/bird4.png");
    pixmap1=pixmap1.scaled(80,80);
    avatar->setPixmap(pixmap1);
    QPixmap pixmap2(":/rc/role4.png");
    pixmap2=pixmap2.scaled(270,270);
    role->setPixmap(pixmap2);
    QPixmap pixmap3(":/rc/4.png");
    pixmap3=pixmap3.scaled(40,40);
    skill->setPixmap(pixmap3);
}

bird4::~bird4()
{
    delete avatar;
    delete role;
    delete skill;
}

void bird4::Skill()
{
    while(Num>=7)
    {
        Score+=15;
        for(int i=0;i<4;i++)
        {
            int x=rand()%7;
            int y=rand()%7;
            while(matrix[x][y]>=5)
            {
                x=rand()%7;
                y=rand()%7;
            }
            matrix[x][y]+=15;
        }
        Num-=7;
        skilltext->setText(QString::number(Num));
        draw();
    }
}
