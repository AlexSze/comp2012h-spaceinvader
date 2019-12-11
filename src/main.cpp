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

MainWindow* m{nullptr};
GameScene* s{nullptr};
avlWindow* w{nullptr};
win_screen* a{nullptr};
defeat_screen* n{nullptr};
win_scene_gs3* u{nullptr};

Score* score;
life* lifes;

AVL<player_record> avl_tree;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    score=new Score;
    lifes=new life;

    m= new MainWindow;
    m->show();

    //KeyPress *keyPress = new KeyPress();
    return a.exec();

}

