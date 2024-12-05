/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>
#include "drawarea.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *ShapeComboBox;
    DrawArea *drawAreaWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuReports;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ShapeComboBox = new QComboBox(centralwidget);
        ShapeComboBox->addItem(QString());
        ShapeComboBox->addItem(QString());
        ShapeComboBox->addItem(QString());
        ShapeComboBox->addItem(QString());
        ShapeComboBox->addItem(QString());
        ShapeComboBox->addItem(QString());
        ShapeComboBox->setObjectName("ShapeComboBox");
        ShapeComboBox->setGeometry(QRect(9, 9, 107, 32));
        QFont font;
        font.setPointSize(14);
        ShapeComboBox->setFont(font);
        drawAreaWidget = new DrawArea(centralwidget);
        drawAreaWidget->setObjectName("drawAreaWidget");
        drawAreaWidget->setGeometry(QRect(9, 49, 781, 521));
        drawAreaWidget->setMouseTracking(true);
        drawAreaWidget->setTabletTracking(false);
        drawAreaWidget->setAutoFillBackground(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuReports = new QMenu(menubar);
        menuReports->setObjectName("menuReports");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuReports->menuAction());
        menubar->addAction(menuHelp->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ShapeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Line", nullptr));
        ShapeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Polyline", nullptr));
        ShapeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Polygon", nullptr));
        ShapeComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        ShapeComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
        ShapeComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Circle", nullptr));

        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuReports->setTitle(QCoreApplication::translate("MainWindow", "Reports", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
