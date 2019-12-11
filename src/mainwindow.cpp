#include "mainwindow.h"
#include "avlwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_game_clicked()
{
    s= new GameScene;
    s->show();

    this->close();
    delete this;
}

void MainWindow::on_pushButton_scoreboard_clicked()
{
    w = new avlWindow(this);
    w->show();
}

void MainWindow::on_pushButton_quit_clicked()
{
    delete this;
    exit(0);
}

void MainWindow::on_actionAbout_triggered()
{ /* new window with credits */
    QMessageBox::about(this, "About", ABOUT_MSG);
}
