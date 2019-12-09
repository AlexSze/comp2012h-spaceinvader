#ifndef DEFEAT_SCREEN_H
#define DEFEAT_SCREEN_H

#include <QDialog>

#include "gamescene.h"

extern GameScene* s;

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::defeat_screen *ui;
};

#endif // DEFEAT_SCREEN_H
