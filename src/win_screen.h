#ifndef WIN_SCREEN_H
#define WIN_SCREEN_H

#include <QDialog>
#include "gamescene.h"

extern GameScene* s;

namespace Ui {
class win_screen;
}

class win_screen : public QDialog
{
    Q_OBJECT

public:
    explicit win_screen(QWidget *parent = nullptr);
    ~win_screen();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::win_screen *ui;
};

#endif // WIN_SCREEN_H
