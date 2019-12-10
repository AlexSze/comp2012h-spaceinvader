#-------------------------------------------------
#
# Project created by QtCreator 2019-11-30T10:31:10
#
#-------------------------------------------------

QT       += core gui
QT += multimedia
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = COMP2012H_Group_H20
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    abstractobjects.cpp \
    defeat_screen.cpp \
    gamescene2.cpp \
    gamescene3.cpp \
    health.cpp \
    life.cpp \
    main.cpp \
    mainwindow.cpp \
    abstractenemy.cpp \
    laser.cpp \
    player.cpp \
    gamescene.cpp \
    score.cpp \
    avlwindow.cpp \
    player_record.cpp \
    win_scene_gs3.cpp \
    win_screen.cpp \
    abstracttools.cpp


HEADERS += \
    abstractobjects.h \
    boss.h \
    defeat_screen.h \
    enemy.h \
    gamescene2.h \
    gamescene3.h \
    health.h \
    life.h \
    mainwindow.h \
    abstractenemy.h \
    laser.h \
    constants.h \
    player.h \
    gamescene.h \
    score.h \
    avl.h \
    avlwindow.h \
    player_record.h \
    win_scene_gs3.h \
    win_screen.h \
    abstracttools.h

FORMS += \
        defeat_screen.ui \
        mainwindow.ui \
        avlwindow.ui \
        win_scene_gs3.ui \
        win_screen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
