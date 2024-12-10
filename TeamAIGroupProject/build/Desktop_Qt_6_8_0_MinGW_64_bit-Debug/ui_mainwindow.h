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
    QAction *actionSort_by_ID;
    QAction *actionSort_by_Type;
    QAction *actionSort_by_Area;
    QAction *actionSort_by_Perimeter;
    QAction *actionOpen;
    QAction *actionSave_as;
    QAction *actionNew;
    QWidget *centralwidget;
    QComboBox *ShapeComboBox;
    DrawArea *drawAreaWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuReports;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionSort_by_ID = new QAction(MainWindow);
        actionSort_by_ID->setObjectName("actionSort_by_ID");
        actionSort_by_Type = new QAction(MainWindow);
        actionSort_by_Type->setObjectName("actionSort_by_Type");
        actionSort_by_Area = new QAction(MainWindow);
        actionSort_by_Area->setObjectName("actionSort_by_Area");
        actionSort_by_Perimeter = new QAction(MainWindow);
        actionSort_by_Perimeter->setObjectName("actionSort_by_Perimeter");
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName("actionSave_as");
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ShapeComboBox = new QComboBox(centralwidget);
        ShapeComboBox->addItem(QString());
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
        menuReports = new QMenu(menubar);
        menuReports->setObjectName("menuReports");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuReports->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionOpen);
        menuReports->addAction(actionSort_by_ID);
        menuReports->addAction(actionSort_by_Area);
        menuReports->addAction(actionSort_by_Perimeter);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSort_by_ID->setText(QCoreApplication::translate("MainWindow", "Sort by ID", nullptr));
        actionSort_by_Type->setText(QCoreApplication::translate("MainWindow", "Sort by Perimeter", nullptr));
        actionSort_by_Area->setText(QCoreApplication::translate("MainWindow", "Sort by Area", nullptr));
        actionSort_by_Perimeter->setText(QCoreApplication::translate("MainWindow", "Sort by Perimeter", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        ShapeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Line", nullptr));
        ShapeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Polyline", nullptr));
        ShapeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Polygon", nullptr));
        ShapeComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        ShapeComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Square", nullptr));
        ShapeComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
        ShapeComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Circle", nullptr));

        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuReports->setTitle(QCoreApplication::translate("MainWindow", "Reports", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
