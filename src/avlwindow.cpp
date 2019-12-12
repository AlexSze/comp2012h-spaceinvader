#include "avlwindow.h"
#include "avlwindow.h"
#include "ui_avlwindow.h"
#include "main.cpp"
#include "constants.h"
#include <QFileDialog>

avlWindow::avlWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::avlWindow)
{
    ui->setupUi(this);

    // read existing record into AVL tree
    read_file();
    // print out results
    print_avl();
}

avlWindow::~avlWindow()
{
    delete ui;
    // reset global pointer variable
    w = nullptr;
    // save data to file
    write_file();
}

void avlWindow::read_file(bool prompt)
{
    // create pop-up to prompt for filename with full directory
    QString filename = "./scoreboard.csv";
    if (prompt) {
        QString filename =
            QFileDialog::getOpenFileName(this,
                                     "Choose Scoreboard CSV", //&caption = QString()
                                     QString(), //&dir = QString()
                                     "*.csv" //&filter = QString()
                                     //*selectedFilter = Q_NULLPTR
                                     //options = Options())
                                     );
        // return if no file selected
        if (filename.trimmed().isEmpty())
            return;
    }
    // open such file
    QFile file(filename);
    // shows error if file cannot be opened
    if (!file.open(QIODevice::ReadOnly)) {
        // show error messages only if prompt is shown
        if (prompt) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
        }
        return;
    }
    // parse csv
    while (!file.atEnd()) {
        // parse line into array
        //QList<QString> wordList = static_cast<QString>(file.readLine()).split(',');
        QList<QByteArray> wordList = file.readLine().split(',');
        // parse first column into unsigned int
        unsigned int tmpScore = wordList[0].toUInt();
        // format the rest of the columns into usernames
        // cut off the first element
        //wordList = wordList.mid(0,1);
        // convert QList<QByteArray> to QStringList
        QStringList tmpNames;
        foreach (const QByteArray &item, wordList.mid(1)) {
            tmpNames.append(QString::fromLocal8Bit(item).trimmed()); // Assuming local 8-bit.
        }
        // remove null strings
        tmpNames.removeAll(QString(""));
        player_record* tmp_player = new player_record(tmpScore, tmpNames);
        // add to data
        avl_tree.insert(*tmp_player);
    }
    // close file
    file.close();
    // print what is read
    print_avl();
}

void avlWindow::write_file(bool prompt)
{ // TODO create popup dialog and write as csv
    QString filename = "./scoreboard.csv";
    if (prompt) {
        QString filename =
            QFileDialog::getSaveFileName(this,
                                     "Save Scoreboard CSV", //&caption = QString()
                                     QString(), //&dir = QString()
                                     "*.csv" //&filter = QString()
                                     //*selectedFilter = Q_NULLPTR
                                     //options = Options())
                                     );
        // return if no file selected
        if (filename.trimmed().isEmpty())
            return;
    }
    // open such file
    QFile file(filename);
    // shows error if file cannot be opened
    if (!file.open(QIODevice::WriteOnly)){// || QFile::Text) {
        QMessageBox::information(this,
                                 tr("Unable to save to file"),
                                 file.errorString());
        return;
    }
    // write to file
    QTextStream out(&file);
    QString text = avl_tree.dump_csv();
    //QString text = ui->plainTextEdit->toPlainText();
    out << text;
    // close file
    file.flush();
    file.close();
}

void avlWindow::print_avl()
{
    // create temp text string
    QString text;
    // read data
    QStringList treeData = avl_tree.dump_csv().split('\n');
    // iterate through it
    for (int rank=1; rank<treeData.size(); ++rank) {
        text.append(
                    "Rank: " + QString::number(rank) + " Score: "
                    + treeData[rank-1].split(",").first() + " Player: "
                    + treeData[rank-1].split(",").mid(1).join(" ") + "\n"
                    );
    }
    ui->plainTextEdit->setPlainText(text);
}

void avlWindow::on_pushButton_write_clicked(){
    write_file();

    //read_as_num();
}

void avlWindow::on_pushButton_print_clicked(){
    print_avl();
}


void avlWindow::on_pushButton_max_clicked()
{
    if (avl_tree.is_empty()) {
        ui->plainTextEdit->setPlainText("");
        return;
    }
    player_record temp= avl_tree.find_max();
    QString text = " Score: " + QString::number(temp.get_score())
            + " Player: " + temp.get_name().join(" ") + "\n";
    ui->plainTextEdit->setPlainText(text);
}

void avlWindow::on_pushButton_min_clicked()
{
    if (avl_tree.is_empty()) {
        ui->plainTextEdit->setPlainText("");
        return;
    }
    player_record temp= avl_tree.find_min();
    QString text = " Score: " + QString::number(temp.get_score())
            + " Player: " + temp.get_name().join(" ") + "\n";
    ui->plainTextEdit->setPlainText(text);
}

void avlWindow::on_pushButton_score_clicked()
{
    QString text = ui->plainTextEdit->toPlainText();

    player_record tmp_player(text.toULong(&convertOK));
    QString boolText = avl_tree.contains(tmp_player) ? "true" : "false";

    ui->plainTextEdit->setPlainText(boolText);

}
void avlWindow::on_actionImport_triggered()
{ // read file with prompt = true
    read_file(true);
}

void avlWindow::on_actionExport_triggered()
{ // write to file with prompt = true
    write_file(true);
}

void avlWindow::on_actionAbout_triggered()
{ /* new window with credits */
    QMessageBox::about(this, "About", ABOUT_MSG);
}
