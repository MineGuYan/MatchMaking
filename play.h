#ifndef PLAY_H
#define PLAY_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <functional>
#include <QTest>
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
    //virtual void Skill();
    int Num=0;
    int People=0;
    int Score=0;

    void draw();
    bool judgeStart();
    int Selected=-1;
    int matrix[7][7];

private slots:
    void swap(int);

private:
    Ui::play *ui;
    QPushButton *fruit;
    QString nor="QPushButton{background-color: transparent;border-radius: 10px;}";
    QString sel="QPushButton{background-color: rgb(85, 255, 127);border-radius: 10px;}";
};

#endif // PLAY_H
