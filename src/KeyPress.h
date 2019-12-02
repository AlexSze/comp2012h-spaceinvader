// KeyPress.h file copied from https://forum.qt.io/topic/20982/solved-how-to-handle-all-the-keys-in-key-press-release-event/2
// Reads keyboard event

#ifndef KEYPRESS_H
#define KEYPRESS_H

#include <QWidget>
#include <QtGui>
#include <QLabel>

class KeyPress : public QWidget
{
    Q_OBJECT

public:
    KeyPress(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QLabel *myLabelText;
};

#endif // KEYPRESS_H
