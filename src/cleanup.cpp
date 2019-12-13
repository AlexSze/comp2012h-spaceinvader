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

void cleanup(int status) {
    delete m;
    delete s;
    delete w;
    delete n;
    delete u;
    //delete g;
    delete score;
    delete lifes;
    exit(status);
}
