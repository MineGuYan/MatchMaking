//#include "mainmenu.h"
//#include "client.h"
//#include "server.h"
#include "play.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Server w;
    //Client w;
    //MainMenu w;
    play w;
    w.show();
    return a.exec();
}
