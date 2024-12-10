#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qDir>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the combo box for shape selection
    connect(ui->ShapeComboBox, &QComboBox::currentTextChanged, this, &MainWindow::onShapeChanged);

    // Connect the signal for drawing a shape to store it in ShapeVector
    connect(ui->drawAreaWidget, &DrawArea::shapeDrawn, this, &MainWindow::onShapeDrawn);

    ui->drawAreaWidget->loadShapeList();
    qDebug() << QDir::currentPath();

}

void MainWindow::onShapeChanged(const QString& shape) {
    // Pass the selected shape type to the DrawArea
    ui->drawAreaWidget->setShapeType(shape);
}

void MainWindow::onShapeDrawn(Shape* shape) {
    // When a shape is drawn, add it to ShapeVector
    shapeVector.addShape(shape);

    // Optionally, update the DrawArea with the new list of shapes if you want to refresh
    // drawArea->updateShapes(shapeVector.getShapes());
}

void MainWindow::on_actionSort_by_ID_triggered()
{
  Parser myParser;
  myParser.generateSortByIDReportFile(ui->drawAreaWidget->getShapesDrawn());

  // Check if the file exists
  QFile file("reportSortedByID.txt");
  if (!file.exists()) {
      // If the file doesn't exist, show an error message
      QMessageBox::warning(this, "Error", "File not found: reportSortedByID.txt");
      return;
  }

  // Use QDesktopServices to open the file with the system's default text viewer
  QUrl fileUrl = QUrl::fromLocalFile("reportSortedByID.txt");  // Convert the file path to a QUrl
  if (!QDesktopServices::openUrl(fileUrl)) {
      // If unable to open the file, show an error message
      QMessageBox::warning(this, "Error", "Could not open the file.");
  }
}

void MainWindow::on_actionSort_by_Area_triggered()
{
  Parser myParser;
  myParser.generateSortByAreaReportFile(ui->drawAreaWidget->getShapesDrawn());

  // Check if the file exists
  QFile file("reportSortedByArea.txt");
  if (!file.exists()) {
    // If the file doesn't exist, show an error message
    QMessageBox::warning(this, "Error", "File not found: reportSortedByArea.txt");
    return;
  }

  // Use QDesktopServices to open the file with the system's default text viewer
  QUrl fileUrl = QUrl::fromLocalFile("reportSortedByArea.txt");  // Convert the file path to a QUrl
  if (!QDesktopServices::openUrl(fileUrl)) {
    // If unable to open the file, show an error message
    QMessageBox::warning(this, "Error", "Could not open the file.");
  }
}

void MainWindow::on_actionSort_by_Perimeter_triggered()
{
  Parser myParser;
  myParser.generateSortByPerimeterReportFile(ui->drawAreaWidget->getShapesDrawn());

  // Check if the file exists
  QFile file("reportSortedByPerimeter.txt");
  if (!file.exists()) {
    // If the file doesn't exist, show an error message
    QMessageBox::warning(this, "Error", "File not found: reportSortedByPerimeter.txt");
    return;
  }

  // Use QDesktopServices to open the file with the system's default text viewer
  QUrl fileUrl = QUrl::fromLocalFile("reportSortedByPerimeter.txt");  // Convert the file path to a QUrl
  if (!QDesktopServices::openUrl(fileUrl)) {
    // If unable to open the file, show an error message
    QMessageBox::warning(this, "Error", "Could not open the file.");
  }
}

void MainWindow::on_actionNew_triggered()
{
  // Clears the canvas and vector
  ui->drawAreaWidget->clearShapesDrawn();
  update();
}

void MainWindow::on_actionSave_as_triggered()
{
  // Open a Save As dialog to let the user choose the file path
  QString filename = QFileDialog::getSaveFileName(this, tr("Save As"), "", tr("Text Files (*.txt);;All Files (*)"));

  // Check if the user selected a file
  if (filename.isEmpty()) {
    return;  // User canceled the dialog, so we do nothing
  }

  // Saves the current shapes drawn to file
  Parser myParser;
  std::string myStringFilename = filename.toStdString();  // Convert QString to std::string
  myParser.saveToFile(ui->drawAreaWidget->getShapesDrawn(), myStringFilename);

  // Inform the user that the file was saved successfully
  QMessageBox::information(this, tr("Success"), tr("File saved successfully"));
}

void MainWindow::on_actionOpen_triggered()
{
  // Open a file dialog to let the user select a file
  QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;All Files (*)"));
  // Check if the user selected a file
  if (filename.isEmpty()) {
    return;  // User canceled the file dialog, so do nothing
  }

  // Check if the file exists
  QFile file(filename);
  if (!file.exists()) {
    // If the file doesn't exist, show an error message
    QMessageBox::warning(this, "Error", "File not found: " + filename);
    return;
  }
  else {
    // Clears the canvas and vector before loading in file
    ui->drawAreaWidget->clearShapesDrawn();
    update();

    // Loads in file and updates canvas
    Parser myParser;
    std::string myStringFilename = filename.toStdString();  // Convert QString to std::string
    myParser.loadFromFile(ui->drawAreaWidget->getShapesDrawn(), myStringFilename);
    update();
  }
}

MainWindow::~MainWindow() {
    delete ui;
}
