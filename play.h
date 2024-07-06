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
    void draw();
    bool judgeStart();

private slots:
    void swap(int);

private:
    Ui::play *ui;
    //QLabel *fruit;
    QPushButton *fruit;
    int Selected=-1;
    int matrix[7][7];
};

#endif // PLAY_H
