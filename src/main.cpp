#include "mainwindow.h"
#include <QApplication>
#include "KeyPress.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    KeyPress *keyPress = new KeyPress();
    keyPress->show();
    return a.exec();
}

