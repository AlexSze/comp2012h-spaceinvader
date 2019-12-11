#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <avlwindow.h>
#include <gamemode.h>
#include <gamescene.h>

extern avlWindow* w;
extern GameScene* s;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_game_clicked();
    void on_pushButton_scoreboard_clicked();
    void on_pushButton_quit_clicked();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
