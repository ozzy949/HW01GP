#include "drawarea.h"
#include "mainwindow.h"

DrawArea::DrawArea(QWidget* parent)
    : QWidget(parent), currentShapeType("Circle") {
    qDebug() << "DrawArea constructor called";
}

void DrawArea::setShapeType(const QString& shapeType) {
    qDebug() << "Initial setShapeType called - Shape type: " << currentShapeType;
    currentShapeType = shapeType;
    qDebug() << "After setShapeType called - Shape type: " << currentShapeType;
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
    qDebug() << "Initial mousePressEvent called - Shape type: " << currentShapeType;

    startPoint = event->pos();  // Record the starting point

    qDebug() << "After mousePressEvent called - Shape type: " << currentShapeType;
}

void DrawArea::mouseReleaseEvent(QMouseEvent* event) {
    qDebug() << "Initial mouseReleaseEvent called - Shape type: " << currentShapeType;

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
        emit shapeDrawn(shape);  // Emit the shapeDrawn signal
        update();  // Request a repaint to show the new shape
    }

    qDebug() << "After mouseReleaseEvent called - Shape type: " << currentShapeType;
}
