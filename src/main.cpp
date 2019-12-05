#include "mainwindow.h"
#include "gamescene.h"

#include <QApplication>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
//#include "KeyPress.h"

GameScene* s;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MainWindow* w;
    //w->show();

    s= new GameScene;
    s->show();

    //KeyPress *keyPress = new KeyPress();
    return a.exec();

}

