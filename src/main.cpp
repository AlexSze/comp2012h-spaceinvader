#include "mainwindow.h"
#include "gamescene.h"
#include "avlwindow.h"

#include <QApplication>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
//#include "KeyPress.h"

MainWindow* m;
GameScene* s;
avlWindow* w;
AVL<int> avl_tree;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    m= new MainWindow;
    m->show();

    //KeyPress *keyPress = new KeyPress();
    return a.exec();

}

