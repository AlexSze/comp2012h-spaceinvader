#include "gamemode.h"
#include "ui_gamemode.h"

extern GameMode* g;

GameMode::GameMode(QWidget *parent) :
    QDialog(parent)
{
    // delete existing if exist
    delete g;

    ui = new Ui::GameMode;
    ui->setupUi(this);
}

GameMode::~GameMode()
{
    delete ui;
    g = nullptr;
}

void GameMode::on_pushButton_normal_clicked()
{
    s = new GameScene();
    this->close();
    s->show();
    delete this;
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
