#include "gamemode.h"
#include "ui_game_mode.h"

GameMode::GameMode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameMode)
{
    ui->setupUi(this);
}

GameMode::~GameMode()
{
    delete ui;
}

void GameMode::on_pushButton_normal_clicked()
{
    s = new GameScene;
    this->close();
    s->show();
    delete this;
}

void GameMode::on_pushButton_infinity_clicked()
{
    s = new GameSceneInfinity;
    this->close();
    s->show();
    delete this;
}

void GameMode::on_pushButton_backToMain_clicked()
{/*
    m = new MainWindow;
    this->close();
    m->show();
    delete this;
*/}

