#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <QDialog>
#include "gamescene.h"
#include "gamesceneinfinity.h"

extern GameScene* s;

namespace Ui {
class GameMode;
}

class GameMode : public QDialog
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

};

#endif // GAMEMODE_H
