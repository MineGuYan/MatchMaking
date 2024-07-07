#ifndef PLAY_H
#define PLAY_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <functional>
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
    void Skillthree(int x,int y);
    void Skillfour(int num);
    void Delete1(int x,int y,int num);
    void Delete2(int x, int y,int num);
    void Judge();
    void fall();
    //virtual void Skill();
    int Num=0;
    int People=0;

    void draw();
    bool judgeStart();
    int Selected=-1;
    int matrix[7][7];

private slots:
    void swap(int);

private:
    Ui::play *ui;
    //QLabel *fruit;
    QPushButton *fruit;
};

#endif // PLAY_H
