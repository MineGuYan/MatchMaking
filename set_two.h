#ifndef SET_TWO_H
#define SET_TWO_H

#include <QWidget>
#include<QIcon>
#include<QPainter>
#include<QSoundEffect>

namespace Ui {
class Set_two;
}

class Set_two : public QWidget
{
    Q_OBJECT

public:
    explicit Set_two(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *) override;
    ~Set_two();

signals:
    void back();
    void Music_1(int number);
    void Music_2(int number);

private slots:
    void on_Button_main_clicked();

    void on_Slider_1_sliderMoved(int position);

    void on_Slider_2_sliderMoved(int position);

private:
    Ui::Set_two *ui;
    QSoundEffect *soundEffect;
};

#endif // SET_TWO_H
