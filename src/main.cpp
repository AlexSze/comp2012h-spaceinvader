#include "mainwindow.h"
#include "gamescene.h"
#include "avlwindow.h"
#include "win_screen.h"
#include "defeat_screen.h"
#include "win_scene_gs3.h"

#include <QApplication>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
//#include "KeyPress.h"

MainWindow* m;
GameScene* s;
avlWindow* w;
win_screen* a;
defeat_screen* n;
win_scene_gs3* u;

AVL<player_record> avl_tree;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    m= new MainWindow;
    m->show();

    //KeyPress *keyPress = new KeyPress();
    return a.exec();

}

