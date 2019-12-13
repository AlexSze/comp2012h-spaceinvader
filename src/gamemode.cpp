#include "gamemode.h"
#include "ui_gamemode.h"

GameMode::GameMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameMode)
{
    ui->setupUi(this);
}

GameMode::~GameMode()
{
    delete ui;
}

extern GameMode* g;
void GameMode::on_pushButton_normal_clicked()
{
    s = new GameScene();
    this->close();
    s->show();
    delete this;
    g = nullptr;
}

void GameMode::on_pushButton_infinity_clicked()
{
    /*
    s = new GameSceneInfinity();
    this->close();
    s->show();
    delete this;
    */
}
