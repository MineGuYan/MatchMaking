#ifndef PLAY_H
#define PLAY_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <functional>
#include <QTest>
#include <QFont>
#include <QSoundEffect>
#include <QUrl>
#include <QTimer>
#include <QMovie>
#include <QByteArray>
#include "network.h"

namespace Ui {
class play;
}

class play : public QWidget
{
    Q_OBJECT

public:
    explicit play(QWidget *parent = nullptr);
    ~play();

    void Skillone(int y);
    void Skilltwo(int x);
    void Skillthree(int x,int y,int r=1);
    void Skillfour(int num);
    void Delete1(int x,int y,int num);
    void Delete2(int x, int y,int num);
    bool Judge();
    int Judgecolumn(int x, int y,int num);
    int Judgerow(int x, int y,int num);
    void fall();
    void Sound();
    void SkillSoundone();
    void SkillSoundtwo();
    void SkillSoundfour();
    virtual void Skill()=0;
    int Num=0;
    int People=0;
    int Score=0;
    int CPRole;
    int CPScore=0;
    int Step=18;
    int CPStep=18;
    int HP=300;
    int CPHP=300;
    int round=1;
    void draw();
    bool judgeStart();
    void gameover();
    void win();
    void lose();
    void nextgame();
    void gameStart();
    void drawCP();
    int Selected=-1;
    int matrix[7][7];
    int timeCount=0;
    bool first=true;
    QLabel *score,*cpscore,*step,*cpstep,*hp,*cphp,*hptext,*cphptext,*skilltext,*cpavatar,*cprole,*pk,*losebg,*winbg,*nextbg,*wintext1,*wintext2,*nexttext;
    QMovie *pkgif;
    Network *network=nullptr;

public slots:
    void swap(int);
    void cpplay();
    void pkstop();
    void quit();
    void cpGetScore();
    void sendScore();

signals:
    void back();

private:
    Ui::play *ui;
    QPushButton *fruit,*quitButton;
    QTimer *timer;
    QString nor="QPushButton{background-color: transparent;border-radius: 10px;}";
    QString sel="QPushButton{background-color: rgb(85, 255, 127);border-radius: 10px;}";
};

#endif // PLAY_H
