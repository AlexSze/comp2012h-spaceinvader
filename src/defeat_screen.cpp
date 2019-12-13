#include "defeat_screen.h"
#include "ui_defeat_screen.h"
#include "cleanup.h"

extern Score* score;
defeat_screen::defeat_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::defeat_screen)
{
    ui->setupUi(this);
    // reset score
    score->reset();
}

extern defeat_screen* n;
defeat_screen::~defeat_screen()
{
    delete ui;
    n = nullptr;
}

void defeat_screen::on_pushButton_restart_clicked()
{
    //TODO change it for all three scene
    s->close();
    s->deleteLater();

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

void defeat_screen::on_pushButton_quit_clicked()
{
    // cleanup
    cleanup();
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
