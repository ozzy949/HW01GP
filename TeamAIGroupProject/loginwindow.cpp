#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->EmptyNameWarning->setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
    QString userName = ui->NameLineEdit->text();
    if (userName.size() == 0) {
        ui->EmptyNameWarning->setVisible(true);
    }
    else {
        this->hide();
        MainWindow *mainwindow = new MainWindow();
        mainwindow->show();
    }
}
