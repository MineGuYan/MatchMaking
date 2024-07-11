#ifndef INTRO_H
#define INTRO_H

#include <QWidget>
#include<QIcon>
#include<QPainter>
#include<QSoundEffect>

namespace Ui {
class Intro;
}

class Intro : public QWidget
{
    Q_OBJECT

public:
    int IntroId;
    explicit Intro(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *) override;
    ~Intro();

signals:
    void back();

private slots:
    void on_Button_main_clicked();

    void on_Button_left_clicked();

    void on_Button_right_clicked();

private:
    Ui::Intro *ui;
    QSoundEffect *soundEffect;
};

#endif // INTRO_H
