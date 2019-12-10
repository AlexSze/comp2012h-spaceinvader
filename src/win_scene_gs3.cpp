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

win_scene_gs3::~win_scene_gs3()
{
    delete ui;
}

void win_scene_gs3::on_pushButton_clicked()
{
        delete s;

        s= new GameScene;
        s->show();

        s->score->reset();
        s->health->reset();
        s->lifes->reset();

        this->close();
        delete this;
}

void win_scene_gs3::on_pushButton_2_clicked()
{
    delete this;
    exit(0);
}

void win_scene_gs3::on_pushButton_3_clicked()
{
    delete s;

    s= new gamescene3;
    s->show();

    s->health->reset();

    this->close();
    delete this;
}
