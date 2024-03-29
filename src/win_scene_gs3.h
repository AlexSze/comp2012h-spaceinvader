#ifndef WIN_SCENE_GS3_H
#define WIN_SCENE_GS3_H

#include <QDialog>
#include "gamescene.h"
#include "mainwindow.h"

extern GameScene* s;
extern MainWindow* m;

namespace Ui {
class win_scene_gs3;
}

class win_scene_gs3 : public QDialog
{
    Q_OBJECT

public:
    explicit win_scene_gs3(QWidget *parent = nullptr);
    ~win_scene_gs3();

private slots:
    void on_pushButton_record_score_clicked();

    void on_pushButton_restart_game_clicked();

    void on_pushButton_backToMenu_clicked();

    void on_pushButton_quit_clicked();

private:
    Ui::win_scene_gs3 *ui;
};

#endif // WIN_SCENE_GS3_H
