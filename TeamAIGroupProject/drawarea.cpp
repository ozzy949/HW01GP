#include "drawarea.h"
#include "mainwindow.h"
#include <QDir>

DrawArea::DrawArea(QWidget* parent)
    : QWidget(parent), currentShapeType("Circle") {
}

void DrawArea::setShapeType(const QString& shapeType) {
    currentShapeType = shapeType;
}

void DrawArea::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw all shapes in the ShapeVector
    const shapeVec& shapesList = shapes.getShapes();  // Get the shapes vector
    for (Shape* shape : shapesList) {
        shape->draw(painter);  // Call the draw method on each shape
    }
}

void DrawArea::mousePressEvent(QMouseEvent* event) {
    startPoint = event->pos();  // Record the starting point
}

void DrawArea::mouseReleaseEvent(QMouseEvent* event) {
    QPoint endPoint = event->pos();  // Get the end point

    Shape* shape = nullptr;

    if (currentShapeType == "Circle") {
        int radius = (startPoint - endPoint).manhattanLength();
        shape = new Circle(0, startPoint, radius);
    } else if (currentShapeType == "Rectangle") {
        QRect rect(startPoint, endPoint);
        shape = new Rectangle(rect);
    }

    if (shape != nullptr) {
        shapes.addShape(shape);  // Add the shape to ShapeVector
        parser.saveToFile(shapes, "shapes.txt");

        emit shapeDrawn(shape);  // Emit the shapeDrawn signal
        update();  // Request a repaint to show the new shape
    }
}

void DrawArea::loadShapes(const QString& filename) {
    parser.loadFromFile(shapes, filename.toStdString());  // Pass ShapeVector to load
    update();
}
