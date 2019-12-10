#include "win_screen.h"
#include "ui_win_screen.h"
#include "gamescene.h"
#include "gamescene2.h"
#include "gamescene3.h"

win_screen::win_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win_screen)
{
    ui->setupUi(this);
}

win_screen::~win_screen()
{
    delete ui;
}

void win_screen::on_pushButton_clicked()
{
    //TODO change it for all three scene
    s->close();

    if (typeid (*s)==typeid(GameScene)){
        delete s;
        s= new GameScene;}
    if (typeid (*s)==typeid(gamescene2)){
        delete s;
        s= new gamescene2;}

    s->show();
    s->health->reset();

    this->close();
    delete this;
}

void win_screen::on_pushButton_2_clicked()
{
    //generate another game, there are three scene
    if (typeid (*s)==typeid(GameScene)){
        delete s;

        s= new gamescene2;
        s->show();

        s->health->reset();

        this->close();
        delete this;

    }else if (typeid (s)==typeid(gamescene2)){
        delete s;

        s= new gamescene3;
        s->show();

        s->health->reset();

        //TODO write score into record

        this->close();
        delete this;
    }
}

void win_screen::on_pushButton_3_clicked()
{
    delete this;
    exit(0);
}
