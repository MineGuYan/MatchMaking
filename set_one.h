#ifndef SET_ONE_H
#define SET_ONE_H

#define WHIDE 170
#define W_1 320
#define W_2 350
#define HEIGHT 350
#include <QWidget>
#include<QIcon>
#include<QPainter>
#include<QsoundEffect>
#include <QToolButton>
#include <QEvent>
#include <QPushButton>
#include<QApplication>
#include<QDebug>

namespace Ui {
class Set_one;
}

class Set_one : public QWidget
{
    Q_OBJECT

public:
    explicit Set_one(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *) override;
    int BirdId_;
    int MyId;
    ~Set_one();

private slots:
    void on_Button_main_clicked();

    void on_Button_1_clicked();

    void on_Button_2_clicked();

    void on_Button_3_clicked();

    void on_Button_4_clicked();

    void on_Button_5_clicked();

    void on_Button_left_clicked();

    void on_Button_right_clicked();

    void on_Button_ok_clicked();

    void on_Button_me_clicked();

signals:
    void back();
    void click_ok();

private:
    Ui::Set_one *ui;
    QSoundEffect *soundEffect;
};

#endif // SET_ONE_H
