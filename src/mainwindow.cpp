#include "mainwindow.h"
#include "avlwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include "gamemode.h"
#include "cleanup.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

extern MainWindow* m;
MainWindow::~MainWindow()
{
    delete ui;
    m = nullptr;
}

void MainWindow::on_pushButton_game_clicked()
{
    g= new GameMode;
    g->show();

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
    // cleanup
    cleanup();
    exit(0);
}

void MainWindow::on_actionAbout_triggered()
{ /* new window with credits */
    QMessageBox::about(this, "About", ABOUT_MSG);
}
