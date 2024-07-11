#include "bird1.h"

bird1::bird1()
{
    People=1;
    avatar=new QLabel(this);
    role=new QLabel(this);
    skill=new QLabel(this);
    avatar->setGeometry(55,70,80,80);
    role->setGeometry(45,230,230,270);
    skill->setGeometry(305,315,40,40);
    QPixmap pixmap1(":/rc/bird1.png");
    pixmap1=pixmap1.scaled(80,80);
    avatar->setPixmap(pixmap1);
    QPixmap pixmap2(":/rc/role1.png");
    pixmap2=pixmap2.scaled(270,270);
    role->setPixmap(pixmap2);
    QPixmap pixmap3(":/rc/1.png");
    pixmap3=pixmap3.scaled(40,40);
    skill->setPixmap(pixmap3);
}

bird1::~bird1()
{
    delete avatar;
    delete role;
    delete skill;
}

void bird1::Skill()
{
    while(Num>=10)
    {
        int x=rand()%7;
        int y=rand()%7;
        while(matrix[x][y]>=5)
        {
            x=rand()%7;
            y=rand()%7;
        }
        matrix[x][y]=20;
        Num-=10;
        skilltext->setText(QString::number(Num));
        draw();
    }
}
