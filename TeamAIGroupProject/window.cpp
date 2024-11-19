#include "window.h"
#include "./ui_window.h"

window::window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::window)
{
    ui->setupUi(this);
    ui->EmptyNameWarning->setVisible(false);
}

window::~window()
{
    delete ui;
}

void window::on_pushButton_clicked()
{
    QString userName = ui->NameLineEdit->text();
    if (userName.size() == 0) {
        ui->EmptyNameWarning->setVisible(true);
    }
    else {
        this->hide();
        shapesWindow *shapeswindow = new shapesWindow();
        shapeswindow->show();
    }
}

