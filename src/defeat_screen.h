#ifndef DEFEAT_SCREEN_H
#define DEFEAT_SCREEN_H

#include <QDialog>

#include "gamescene.h"
#include "gamescene2.h"
#include "gamescene3.h"
#include "mainwindow.h"

extern GameScene* s;
extern MainWindow* m;

namespace Ui {
class defeat_screen;
}

class defeat_screen : public QDialog
{
    Q_OBJECT

public:
    explicit defeat_screen(QWidget *parent = nullptr);
    ~defeat_screen();

private slots:
    void on_pushButton_restart_clicked();

    void on_pushButton_quit_clicked();

    void on_pushButton_backToMain_clicked();

private:
    Ui::defeat_screen *ui;
};

#endif // DEFEAT_SCREEN_H
