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

void defeat_screen::on_pushButton_clicked()
{
    //TODO change it for all three scene

    s= new GameScene;
    s->show();

    this->close();
    delete this;
}

void defeat_screen::on_pushButton_2_clicked()
{
    delete this;
    exit(0);
}
