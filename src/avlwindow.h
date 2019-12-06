#ifndef AVLWINDOW_H
#define AVLWINDOW_H

#include <QMainWindow>
#include <list>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

#include "avl.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class avlWindow; }
QT_END_NAMESPACE

extern AVL<int> avl_tree;

class avlWindow : public QMainWindow
{
    Q_OBJECT

public:
    avlWindow(QWidget *parent = nullptr);
    ~avlWindow();

    void read_as_num();
    void write_to_file();
    void insert_num_to_avl();
    void print_avl();

private slots:
    void on_pushButton_write_clicked();

    void on_pushButton_print_clicked();

    void on_pushButton_max_clicked();

    void on_pushButton_min_clicked();

    void on_pushButton_score_clicked();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionAbout_triggered();

private:
    Ui::avlWindow *ui;
    list<int> number;
    QString text;
    int tempnum;
    int rank;
    bool convertOK;

};
#endif // AVLWINDOW_H
