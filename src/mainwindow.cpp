#include "mainwindow.h"
#include "avlwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_2_clicked()
{
    w= new avlWindow;
    w->show();
}

void MainWindow::on_pushButton_clicked()
{
    s= new GameScene;
    s->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    delete this;
    exit(0);
}
