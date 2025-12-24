/********************************************************************************
** Form generated from reading UI file 'headsUpDisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEADSUPDISPLAY_H
#define UI_HEADSUPDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_headsUpDisplay
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *headsUpDisplay)
    {
        if (headsUpDisplay->objectName().isEmpty())
            headsUpDisplay->setObjectName(QString::fromUtf8("headsUpDisplay"));
        headsUpDisplay->resize(800, 600);
        centralwidget = new QWidget(headsUpDisplay);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        headsUpDisplay->setCentralWidget(centralwidget);
        menubar = new QMenuBar(headsUpDisplay);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        headsUpDisplay->setMenuBar(menubar);
        statusbar = new QStatusBar(headsUpDisplay);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        headsUpDisplay->setStatusBar(statusbar);

        retranslateUi(headsUpDisplay);

        QMetaObject::connectSlotsByName(headsUpDisplay);
    } // setupUi

    void retranslateUi(QMainWindow *headsUpDisplay)
    {
        headsUpDisplay->setWindowTitle(QCoreApplication::translate("headsUpDisplay", "headsUpDisplay", nullptr));
    } // retranslateUi

};

namespace Ui {
    class headsUpDisplay: public Ui_headsUpDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADSUPDISPLAY_H
