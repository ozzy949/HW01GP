#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    drawArea(new DrawArea(this)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the combo box for shape selection
    connect(ui->ShapeComboBox, &QComboBox::currentTextChanged, this, &MainWindow::onShapeChanged);

    // Connect the signal for drawing a shape to store it in ShapeVector
    connect(drawArea, &DrawArea::shapeDrawn, this, &MainWindow::onShapeDrawn);
}

void MainWindow::onShapeChanged(const QString& shape) {
    // Pass the selected shape type to the DrawArea
    drawArea->setShapeType(shape);
}

void MainWindow::onShapeDrawn(Shape* shape) {
    // When a shape is drawn, add it to ShapeVector
    shapeVector.addShape(shape);

    // Optionally, update the DrawArea with the new list of shapes if you want to refresh
    // drawArea->updateShapes(shapeVector.getShapes());
}

MainWindow::~MainWindow() {
    delete ui;
}
