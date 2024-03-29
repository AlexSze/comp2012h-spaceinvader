#include "defeat_screen.h"
#include "ui_defeat_screen.h"
#include "cleanup.h"

extern Score* score;
extern defeat_screen* n;
defeat_screen::defeat_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::defeat_screen)
{
    // delete existing if exist
    delete n;

    ui->setupUi(this);
    // reset score
    score->reset();
}

defeat_screen::~defeat_screen()
{
    delete ui;
    n = nullptr;
}

void defeat_screen::on_pushButton_restart_clicked()
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

void defeat_screen::on_pushButton_quit_clicked()
{
    // cleanup
    cleanup(0);
}

void defeat_screen::on_pushButton_backToMain_clicked()
{
    //s->player->reset_atk();
    score->reset();
    lifes->reset();
    m = new MainWindow;
    this->close();
    m->show();

    delete s;
    delete this;
}
