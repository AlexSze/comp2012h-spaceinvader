#ifndef AVLWINDOW_H
#define AVLWINDOW_H

#include <QMainWindow>
#include <list>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include "avl.h"
#include "player_record.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class avlWindow; }
QT_END_NAMESPACE

extern AVL<player_record> avl_tree;

class avlWindow : public QMainWindow
{
    Q_OBJECT

public:
    avlWindow(QWidget *parent = nullptr);
    ~avlWindow();

    void read_file(bool prompt = false);
    void write_file(bool prompt = false);
    //void insert_num_to_avl();
    void print_avl();

private slots:
    void on_pushButton_print_clicked();

    void on_pushButton_max_clicked();

    void on_pushButton_min_clicked();

    void on_pushButton_score_clicked();

    void on_actionImport_triggered();

    void on_actionExport_triggered();

    void on_actionAbout_triggered();

private:
    Ui::avlWindow *ui;

    //list<player_record> data;

    int tempnum;
    string temptext;
    player_record* tempdata;

    //QString text;
    //int rank;
    bool convertOK;

};
#endif // AVLWINDOW_H
