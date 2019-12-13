#include "win_scene_gs3.h"
#include "ui_win_scene_gs3.h"

#include "gamescene.h"
#include "gamescene2.h"
#include "gamescene3.h"
#include "cleanup.h"

#include <QInputDialog>

extern win_scene_gs3* u;
win_scene_gs3::win_scene_gs3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win_scene_gs3)
{
    // delete existing if exist
    delete u;
    ui->setupUi(this);
}

win_scene_gs3::~win_scene_gs3()
{
    delete ui;
    u=nullptr;
}

void win_scene_gs3::on_pushButton_restart_game_clicked()
{
        s = new GameScene;
        s->show();

        // reset game state
        score->reset();
        s->health->reset();
        lifes->reset();

        this->close();
        delete this;
}

void win_scene_gs3::on_pushButton_record_score_clicked()
{
    QStringList playerName;

    // prompt for player name
    playerName.append(QInputDialog::getText(this,
                                            "Record Score", //&title
                                            "Player Name:" //&label
                                            //QLineEdit::EchoMode mode = QLineEdit::Normal, const QString &text = QString(), bool *ok = nullptr, Qt::WindowFlags flags = Qt::WindowFlags(), Qt::InputMethodHints inputMethodHints = Qt::ImhNone)
                                            ));

    avl_tree.insert(player_record(score->get_score(), playerName));

    if (w==nullptr) {
        // create avl window if doesn't already exist
        w = new avlWindow(this);
        w->show();
    }
}

void win_scene_gs3::on_pushButton_backToMenu_clicked()
{
    s->player->reset_atk();
    score->reset();
    lifes->reset();
    m = new MainWindow;
    this->close();
    m->show();

    delete s;
    delete this;
}

void win_scene_gs3::on_pushButton_quit_clicked()
{
    // cleanup
    cleanup(0);
}
