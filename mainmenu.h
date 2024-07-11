#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include "play.h"
#include "bird0.h"
#include "bird1.h"
#include "bird2.h"
#include "bird3.h"
#include "bird4.h"
#include "intro.h"
#include "set_one.h"
#include "set_two.h"
#include <QPixmap>
#include <QPainter>
#include <QIcon>
#include <QsoundEffect>
#include <QMediaPlayer>
#include <QApplication>
#include <QAudioOutput>
#include <QFile>
#include <QAudioFormat>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainMenu;
}
QT_END_NAMESPACE

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    int BirdId;
    float Music;
    float MusicEffect;
    MainMenu(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *) override;
    ~MainMenu();

private slots:

    void on_Button_Singal_clicked();

    void on_Button_Double_clicked();

    void on_Button_Intro_clicked();

    void on_Button_Set_one_clicked();

    void on_Button_Set_two_clicked();

    void Music_Received(int);

    void MusicEffect_Received(int);

private:
    Ui::MainMenu *ui;
    play *gamestart=nullptr;
    Intro* intro;
    Set_one* set1;
    Set_two* set2;
    QSoundEffect *soundEffect;
    QSoundEffect *musicEffect;
    QMediaPlayer *music;
    QAudioOutput* audioOutput;
};
#endif // MAINMENU_H
