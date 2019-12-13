#include "win_screen.h"
#include "ui_win_screen.h"
#include "gamescene.h"
#include "gamescene2.h"
#include "gamescene3.h"
#include "cleanup.h"

extern win_screen* a;
win_screen::win_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win_screen)
{
    // delete existing if exist
    delete a;
    ui->setupUi(this);
}

win_screen::~win_screen()
{
    delete ui;
    a = nullptr;
}

void win_screen::on_pushButton_restart_clicked()
{
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
        s = new gamescene2;
    }
    else {
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
