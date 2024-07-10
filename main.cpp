//#include "mainmenu.h"
//#include "client.h"
//#include "server.h"
//#include "play.h"
#include "bird0.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Server w;
    //Client w;
    //MainMenu w;
    //play w;
    bird0 w;
    w.show();
    return a.exec();
}
