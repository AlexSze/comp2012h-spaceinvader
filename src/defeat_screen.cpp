#include "defeat_screen.h"
#include "ui_defeat_screen.h"

extern Score* score;
defeat_screen::defeat_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::defeat_screen)
{
    ui->setupUi(this);
    // reset score
    score->reset();
}

defeat_screen::~defeat_screen()
{
    delete ui;
}

void defeat_screen::on_pushButton_restart_clicked()
{
    //TODO change it for all three scene
    //TODO player cannot move, player health is not acting normal
    s->close();

    if (typeid (*s)==typeid(GameScene)){
        delete s;
        s= new GameScene;}
    if (typeid (*s)==typeid(gamescene2)){
        delete s;
        s= new gamescene2;}
    if (typeid (*s)==typeid(gamescene3)){
        delete s;
        s= new gamescene3;}

    s->show();

    s->health->reset();

    this->close();
    delete this;
}

void defeat_screen::on_pushButton_quit_clicked()
{
    delete s;
    this->close();
    delete this;
    exit(0);
}

void defeat_screen::on_pushButton_backToMain_clicked()
{
    s->player->reset_atk();
    score->reset();
    while (lifes->get_life() > 2)
        lifes->decrease();
    while (lifes->get_life() < 2)
        lifes->increase();
    m = new MainWindow;
    this->close();
    m->show();
    delete s;
    delete this;
}
