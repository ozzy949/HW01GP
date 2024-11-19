#include "shapeswindow.h"
#include "ui_shapeswindow.h"

shapesWindow::shapesWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::shapesWindow)
{
    ui->setupUi(this);
}

shapesWindow::~shapesWindow()
{
    delete ui;
}
