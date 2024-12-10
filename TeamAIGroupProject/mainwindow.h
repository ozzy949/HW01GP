#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "drawarea.h"
#include "shapevector.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QObject>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void onShapeChanged(const QString& shape);  // Slot to handle combo box shape changes
    void onShapeDrawn(Shape* shape);  // Slot to handle shape being drawn

    // "File" option functions
    void on_actionNew_triggered();
    void on_actionSave_as_triggered();
    void on_actionOpen_triggered();

    // "Reports" option functions
    void on_actionSort_by_ID_triggered();
    void on_actionSort_by_Area_triggered();
    void on_actionSort_by_Perimeter_triggered();

private:
    Ui::MainWindow* ui;
    ShapeVector shapeVector;  // Store all the shapes
};

#endif // MAINWINDOW_H
