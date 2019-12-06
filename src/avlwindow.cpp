#include "avlwindow.h"
#include "ui_avlwindow.h"
#include "main.cpp"
#include "constants.h"

avlWindow::avlWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::avlWindow)
{
    ui->setupUi(this);
}

avlWindow::~avlWindow()
{
    delete ui;
}

void avlWindow::read_as_num()
{
    QFile file("/Users/alex/Desktop/avlresult.txt");
    if (!file.open(QFile::ReadOnly| QFile::Text)){
        QMessageBox::warning(this, "title", "file not open");
    }else{
        number.clear();
        text="";

        QTextStream in(&file);
        //QString text = in.readAll();

        while (!in.atEnd())
        {
            QString line = in.readLine();
            tempnum= line.toULong(&convertOK);
            number.push_back(tempnum);
        }

        file.close();
    }
}

void avlWindow::write_to_file()
{
    QFile file("/Users/alex/Desktop/avlresult.txt");

    if (!file.open(QFile::WriteOnly| QFile::Text)){
        QMessageBox::warning(this, "title", "file not open");
    }

    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();

    out << text;
    file.flush();
    file.close();
}

void avlWindow::insert_num_to_avl()
{
    list<int>::const_iterator p;
    for (p= number.begin(); p!= number.end(); ++p){
        avl_tree.insert(*p);
    }
}

void avlWindow::print_avl()
{
    int temp;

    rank=0;
    text="";

    while (!avl_tree.is_empty()){
        rank++;

        temp=avl_tree.find_max();
        avl_tree.remove(temp);
        text=text+ "Rank "+ QString::number(rank)+ ": "+ QString::number(temp)+ "\n";
    }

    ui->plainTextEdit->setPlainText(text);
}

void avlWindow::on_pushButton_write_clicked(){
    write_to_file();

    read_as_num();

    insert_num_to_avl();
}

void avlWindow::on_pushButton_print_clicked(){
    print_avl();

    insert_num_to_avl();
}


void avlWindow::on_pushButton_max_clicked()
{
    text=QString::number(avl_tree.find_max());

    ui->plainTextEdit->setPlainText(text);
}

void avlWindow::on_pushButton_min_clicked()
{
    text=QString::number(avl_tree.find_min());
    ui->plainTextEdit->setPlainText(text);
}

void avlWindow::on_pushButton_score_clicked()
{
    QString text = ui->plainTextEdit->toPlainText();

    QString boolText = avl_tree.contains(text.toULong(&convertOK)) ? "true" : "false";

    ui->plainTextEdit->setPlainText(boolText);

}

void avlWindow::on_actionOpen_triggered()
{ // TODO
    /* choose file */
}

void avlWindow::on_actionSave_triggered()
{ // TODO
    /* save to file */
}

void avlWindow::on_actionAbout_triggered()
{ /* new window with credits */
    QMessageBox::about(this, "About", ABOUT_MSG);
}
