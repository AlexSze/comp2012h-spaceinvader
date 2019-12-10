#ifndef WIN_SCENE_GS3_H
#define WIN_SCENE_GS3_H

#include <QDialog>
#include "gamescene.h"

extern GameScene* s;

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::win_scene_gs3 *ui;
};

#endif // WIN_SCENE_GS3_H
