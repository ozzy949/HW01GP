#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "drawarea.h"
#include "shapevector.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QObject>

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

private:
    Ui::MainWindow* ui;
    ShapeVector shapeVector;  // Store all the shapes
};

#endif // MAINWINDOW_H
