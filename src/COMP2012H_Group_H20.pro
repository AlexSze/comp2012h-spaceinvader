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
    button.cpp \
    health.cpp \
        main.cpp \
        mainwindow.cpp \
    abstractenemy.cpp \
    abstracttools.cpp \
    laser.cpp \
    player.cpp \
    gamescene.cpp \
    score.cpp \

HEADERS += \
    abstractobjects.h \
    button.h \
    health.h \
        mainwindow.h \
    abstractenemy.h \
    abstracttools.h \
    laser.h \
    constants.h \
    player.h \
    gamescene.h \
    score.h \
    avl.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
