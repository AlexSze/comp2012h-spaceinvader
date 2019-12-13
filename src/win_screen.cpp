#include "win_screen.h"
#include "ui_win_screen.h"
#include "gamescene.h"
#include "gamescene2.h"
#include "gamescene3.h"
#include "cleanup.h"

win_screen::win_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win_screen)
{
    ui->setupUi(this);
}

extern win_screen* a;
win_screen::~win_screen()
{
    delete ui;
    a = nullptr;
}

void win_screen::on_pushButton_restart_clicked()
{
    delete s;

    // create new game
    s = new GameScene;

    // show new scene
    s->show();

    // reset game state
    s->health->reset();
    score->reset();
    lifes->reset();

    this->close();
    delete this;
}

void win_screen::on_pushButton_next_clicked()
{
    //generate another game, there are two scenes after first level
    if (typeid (*s)==typeid(GameScene)) {
        delete s;
        s = new gamescene2;
    }
    else {
        delete s;
        s = new gamescene3;
    }

    s->show();

    s->health->reset();

    this->close();
    delete this;
}

void win_screen::on_pushButton_quit_clicked()
{
    // cleanup
    cleanup(0);
}
