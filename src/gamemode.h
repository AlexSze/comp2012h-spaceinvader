#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <QMainWindow>
#include "gamescene.h"
#include "gamesceneinfinity.h"
#include "mainwindow.h"

//extern MainWindow* m;
//extern GameScene* s;

namespace Ui {
class GameMode;
}

class GameMode : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameMode(QWidget *parent = nullptr);
    ~GameMode();

private:
    Ui::GameMode *ui;

private slots:
    void on_pushButton_normal_clicked();

    void on_pushButton_infinity_clicked();

    void on_pushButton_backToMain_clicked();
};

#endif // GAMEMODE_H
