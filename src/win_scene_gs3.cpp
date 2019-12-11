#include "win_scene_gs3.h"
#include "ui_win_scene_gs3.h"

#include "gamescene.h"
#include "gamescene2.h"
#include "gamescene3.h"

win_scene_gs3::win_scene_gs3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win_scene_gs3)
{
    ui->setupUi(this);
}

extern win_scene_gs3* u;
win_scene_gs3::~win_scene_gs3()
{
    delete ui;
    u=nullptr;
}

void win_scene_gs3::on_pushButton_restart_game_clicked()
{
        delete s;

        s= new GameScene;
        s->show();

        score->reset();
        s->health->reset();
        lifes->reset();

        this->close();
        delete this;
}

void win_scene_gs3::on_pushButton_restart_level_clicked()
{
    delete s;

    s= new gamescene3;
    s->show();

    s->health->reset();

    this->close();
    delete this;
}

void win_scene_gs3::on_pushButton_quit_clicked()
{
    delete s;
    delete this;
    exit(0);
}
