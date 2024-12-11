/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QLabel *LoginLabel;
    QLabel *NameLabel;
    QLineEdit *NameLineEdit;
    QPushButton *pushButton;
    QLabel *EmptyNameWarning;
    QPushButton *contactUsButton;
    QLabel *TeamAILogo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginWindow->sizePolicy().hasHeightForWidth());
        LoginWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        LoginLabel = new QLabel(centralwidget);
        LoginLabel->setObjectName("LoginLabel");
        LoginLabel->setGeometry(QRect(360, 220, 81, 36));
        LoginLabel->setMinimumSize(QSize(81, 36));
        LoginLabel->setMaximumSize(QSize(81, 36));
        QFont font;
        font.setPointSize(20);
        LoginLabel->setFont(font);
        LoginLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        NameLabel = new QLabel(centralwidget);
        NameLabel->setObjectName("NameLabel");
        NameLabel->setGeometry(QRect(130, 320, 61, 41));
        NameLabel->setMinimumSize(QSize(61, 0));
        NameLabel->setMaximumSize(QSize(61, 41));
        QFont font1;
        font1.setPointSize(16);
        NameLabel->setFont(font1);
        NameLineEdit = new QLineEdit(centralwidget);
        NameLineEdit->setObjectName("NameLineEdit");
        NameLineEdit->setGeometry(QRect(200, 320, 401, 41));
        NameLineEdit->setMinimumSize(QSize(401, 41));
        NameLineEdit->setMaximumSize(QSize(401, 41));
        NameLineEdit->setFont(font1);
        NameLineEdit->setEchoMode(QLineEdit::EchoMode::Normal);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(620, 320, 51, 41));
        pushButton->setMinimumSize(QSize(51, 41));
        pushButton->setMaximumSize(QSize(51, 41));
        pushButton->setFont(font1);
        EmptyNameWarning = new QLabel(centralwidget);
        EmptyNameWarning->setObjectName("EmptyNameWarning");
        EmptyNameWarning->setGeometry(QRect(200, 370, 211, 21));
        EmptyNameWarning->setMinimumSize(QSize(211, 21));
        EmptyNameWarning->setMaximumSize(QSize(211, 21));
        QFont font2;
        font2.setPointSize(10);
        EmptyNameWarning->setFont(font2);
        contactUsButton = new QPushButton(centralwidget);
        contactUsButton->setObjectName("contactUsButton");
        contactUsButton->setGeometry(QRect(620, 490, 141, 41));
        contactUsButton->setMinimumSize(QSize(141, 41));
        contactUsButton->setMaximumSize(QSize(141, 41));
        TeamAILogo = new QLabel(centralwidget);
        TeamAILogo->setObjectName("TeamAILogo");
        TeamAILogo->setGeometry(QRect(288, 15, 231, 201));
        LoginWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "LoginWindow", nullptr));
        LoginLabel->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        NameLabel->setText(QCoreApplication::translate("LoginWindow", "Name", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginWindow", "OK", nullptr));
        EmptyNameWarning->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p><span style=\" color:#ff0000;\">Please enter a name.</span></p></body></html>", nullptr));
        contactUsButton->setText(QCoreApplication::translate("LoginWindow", "Need help? Contact us!", nullptr));
        TeamAILogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
