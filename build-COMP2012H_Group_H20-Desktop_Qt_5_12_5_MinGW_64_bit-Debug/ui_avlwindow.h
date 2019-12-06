/********************************************************************************
** Form generated from reading UI file 'avlwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AVLWINDOW_H
#define UI_AVLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_avlWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *avlWindow)
    {
        if (avlWindow->objectName().isEmpty())
            avlWindow->setObjectName(QString::fromUtf8("avlWindow"));
        avlWindow->resize(629, 459);
        centralwidget = new QWidget(avlWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);


        verticalLayout_2->addLayout(verticalLayout);

        avlWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(avlWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 629, 22));
        avlWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(avlWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        avlWindow->setStatusBar(statusbar);

        retranslateUi(avlWindow);

        QMetaObject::connectSlotsByName(avlWindow);
    } // setupUi

    void retranslateUi(QMainWindow *avlWindow)
    {
        avlWindow->setWindowTitle(QApplication::translate("avlWindow", "avlWindow", nullptr));
        pushButton_2->setText(QApplication::translate("avlWindow", "Write", nullptr));
        pushButton->setText(QApplication::translate("avlWindow", "Print", nullptr));
        pushButton_4->setText(QApplication::translate("avlWindow", "find max", nullptr));
        pushButton_5->setText(QApplication::translate("avlWindow", "find min", nullptr));
        pushButton_6->setText(QApplication::translate("avlWindow", "find score", nullptr));
    } // retranslateUi

};

namespace Ui {
    class avlWindow: public Ui_avlWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AVLWINDOW_H
