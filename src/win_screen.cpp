#include "win_screen.h"
#include "ui_win_screen.h"

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

    s= new GameScene;
    s->show();

    this->close();
    delete this;
}

void win_screen::on_pushButton_2_clicked()
{
    //generate another game, lets say there are three scene
}

void win_screen::on_pushButton_3_clicked()
{
    delete this;
    exit(0);
}
