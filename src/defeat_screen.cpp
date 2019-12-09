#include "defeat_screen.h"
#include "ui_defeat_screen.h"

defeat_screen::defeat_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::defeat_screen)
{
    ui->setupUi(this);
}

defeat_screen::~defeat_screen()
{
    delete ui;
}

void defeat_screen::on_pushButton_clicked()//restart
{
    //TODO change it for all three scene
    //TODO player cannot move, player health is not acting normal
    delete s;

    s= new GameScene;
    s->show();

    s->health->reset();
    s->score->reset();

    this->close();
    delete this;
}

void defeat_screen::on_pushButton_2_clicked()//quit
{
    delete this;
    exit(0);
}
