/********************************************************************************
** Form generated from reading UI file 'shapeswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHAPESWINDOW_H
#define UI_SHAPESWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shapesWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *shapesWindow)
    {
        if (shapesWindow->objectName().isEmpty())
            shapesWindow->setObjectName("shapesWindow");
        shapesWindow->resize(800, 600);
        centralwidget = new QWidget(shapesWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 30, 221, 51));
        QFont font;
        font.setPointSize(26);
        label->setFont(font);
        shapesWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(shapesWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        shapesWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(shapesWindow);
        statusbar->setObjectName("statusbar");
        shapesWindow->setStatusBar(statusbar);

        retranslateUi(shapesWindow);

        QMetaObject::connectSlotsByName(shapesWindow);
    } // setupUi

    void retranslateUi(QMainWindow *shapesWindow)
    {
        shapesWindow->setWindowTitle(QCoreApplication::translate("shapesWindow", "TeamAIProject", nullptr));
        label->setText(QCoreApplication::translate("shapesWindow", "Shape Viewer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shapesWindow: public Ui_shapesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAPESWINDOW_H
