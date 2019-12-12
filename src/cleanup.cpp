#include "cleanup.h"

#include "mainwindow.h"
#include "gamescene.h"
#include "avlwindow.h"
#include "defeat_screen.h"
#include "win_scene_gs3.h"
#include "win_screen.h"

extern MainWindow* m;
extern GameScene* s;
extern avlWindow* w;
extern win_screen* a;
extern defeat_screen* n;
extern win_scene_gs3* u;
extern GameMode* g;
extern Score* score;
extern life* lifes;

void cleanup() {
    delete m;
    qDebug() << "m";
    delete s;
    qDebug() << "s";
    delete w;
    qDebug() << "w";
    delete n;
    qDebug() << "n";
    delete u;
    qDebug() << "u";
    //delete g;
    qDebug() << "g";
    delete score;
    qDebug() << "score";
    delete lifes;
    qDebug() << "lifes";

}
