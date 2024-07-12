#include "bird3.h"

bird3::bird3()
{
    People=3;
    avatar=new QLabel(this);
    role=new QLabel(this);
    skill=new QLabel(this);
    avatar->setGeometry(55,70,80,80);
    role->setGeometry(45,230,230,270);
    skill->setGeometry(305,315,40,40);
    QPixmap pixmap1(":/rc/bird3.png");
    pixmap1=pixmap1.scaled(80,80);
    avatar->setPixmap(pixmap1);
    QPixmap pixmap2(":/rc/role3.png");
    pixmap2=pixmap2.scaled(270,270);
    role->setPixmap(pixmap2);
    QPixmap pixmap3(":/rc/3.png");
    pixmap3=pixmap3.scaled(40,40);
    skill->setPixmap(pixmap3);
    nextbg->raise();
    nexttext->raise();
    gameStart();
}

bird3::bird3(int)
{
    network=new Network;
    People=3;
    avatar=new QLabel(this);
    role=new QLabel(this);
    skill=new QLabel(this);
    avatar->setGeometry(55,70,80,80);
    role->setGeometry(45,230,230,270);
    skill->setGeometry(305,315,40,40);
    QPixmap pixmap1(":/rc/bird3.png");
    pixmap1=pixmap1.scaled(80,80);
    avatar->setPixmap(pixmap1);
    QPixmap pixmap2(":/rc/role3.png");
    pixmap2=pixmap2.scaled(270,270);
    role->setPixmap(pixmap2);
    QPixmap pixmap3(":/rc/3.png");
    pixmap3=pixmap3.scaled(40,40);
    skill->setPixmap(pixmap3);
}

bird3::~bird3()
{
    delete avatar;
    delete role;
    delete skill;
}

void bird3::Skill()
{
    while(Num>=6)
    {
        Score+=4;
        int x=rand()%7;
        int y=rand()%7;
        Skillone(y);
        Skilltwo(x);
        Num-=6;
        fall();
        skilltext->setText(QString::number(Num));
    }
}
