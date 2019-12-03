#include "mainwindow.h"
#include <QApplication>
#include "gamescene.h"
//#include "KeyPress.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    GameScene s;
    s.show();

    //KeyPress *keyPress = new KeyPress();
    return a.exec();
}

