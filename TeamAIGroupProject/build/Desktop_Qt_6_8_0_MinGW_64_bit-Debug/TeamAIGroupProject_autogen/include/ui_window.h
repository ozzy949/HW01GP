/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window
{
public:
    QWidget *centralwidget;
    QLabel *LoginLabel;
    QLabel *NameLabel;
    QPushButton *pushButton;
    QLineEdit *NameLineEdit;
    QLabel *EmptyNameWarning;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *window)
    {
        if (window->objectName().isEmpty())
            window->setObjectName("window");
        window->resize(800, 600);
        QFont font;
        font.setPointSize(16);
        window->setFont(font);
        window->setAutoFillBackground(true);
        centralwidget = new QWidget(window);
        centralwidget->setObjectName("centralwidget");
        LoginLabel = new QLabel(centralwidget);
        LoginLabel->setObjectName("LoginLabel");
        LoginLabel->setGeometry(QRect(366, 90, 71, 36));
        QFont font1;
        font1.setPointSize(20);
        LoginLabel->setFont(font1);
        LoginLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        NameLabel = new QLabel(centralwidget);
        NameLabel->setObjectName("NameLabel");
        NameLabel->setGeometry(QRect(130, 310, 61, 41));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(610, 310, 51, 41));
        NameLineEdit = new QLineEdit(centralwidget);
        NameLineEdit->setObjectName("NameLineEdit");
        NameLineEdit->setGeometry(QRect(220, 311, 351, 41));
        NameLineEdit->setEchoMode(QLineEdit::EchoMode::Normal);
        EmptyNameWarning = new QLabel(centralwidget);
        EmptyNameWarning->setObjectName("EmptyNameWarning");
        EmptyNameWarning->setGeometry(QRect(220, 360, 211, 21));
        QFont font2;
        font2.setPointSize(10);
        EmptyNameWarning->setFont(font2);
        EmptyNameWarning->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(window);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 34));
        window->setMenuBar(menubar);
        statusbar = new QStatusBar(window);
        statusbar->setObjectName("statusbar");
        window->setStatusBar(statusbar);

        retranslateUi(window);

        QMetaObject::connectSlotsByName(window);
    } // setupUi

    void retranslateUi(QMainWindow *window)
    {
        window->setWindowTitle(QCoreApplication::translate("window", "TeamAILogin", nullptr));
        LoginLabel->setText(QCoreApplication::translate("window", "Login", nullptr));
        NameLabel->setText(QCoreApplication::translate("window", "Name", nullptr));
        pushButton->setText(QCoreApplication::translate("window", "OK", nullptr));
        EmptyNameWarning->setText(QCoreApplication::translate("window", "<html><head/><body><p><span style=\" color:#ff0000;\">Please enter a name.</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class window: public Ui_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
