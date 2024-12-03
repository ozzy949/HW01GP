#include "drawarea.h"
#include "mainwindow.h"
#include "ellipse.h"
#include "line.h"
#include "polygon.h"
#include "polyline.h"  // Include Polyline header

DrawArea::DrawArea(QWidget* parent)
    : QWidget(parent), currentShapeType("Circle"), isDrawingPolygon(false), isDrawingPolyline(false) {
    qDebug() << "DrawArea constructor called";
}

void DrawArea::setShapeType(const QString& shapeType) {
    qDebug() << "Initial setShapeType called - Shape type: " << currentShapeType;
    currentShapeType = shapeType;

    // Reset polygon and polyline drawing if the shape type changes
    if (currentShapeType != "Polygon" && currentShapeType != "Polyline") {
        isDrawingPolygon = false;
        isDrawingPolyline = false;
        polygonVertices.clear();
        polylinePoints.clear();
    }

    qDebug() << "After setShapeType called - Shape type: " << currentShapeType;
}

void DrawArea::paintEvent(QPaintEvent* /*event*/) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw all shapes in the ShapeVector
    const shapeVec& shapesList = shapes.getShapes();  // Get the shapes vector
    for (Shape* shape : shapesList) {
        shape->draw(painter);  // Call the draw method on each shape
    }

    // Draw in-progress polygon if necessary
    if (isDrawingPolygon && !polygonVertices.isEmpty()) {
        painter.setPen(Qt::DashLine); // Temporary dashed line
        painter.setBrush(Qt::NoBrush);

        QVector<QPoint> translatedPoints;
        for (const QPoint& vertex : polygonVertices) {
            translatedPoints.append(vertex);
        }

        painter.drawPolygon(translatedPoints);
    }

    // Draw in-progress polyline if necessary
    if (isDrawingPolyline && !polylinePoints.isEmpty()) {
        painter.setPen(Qt::DashLine); // Temporary dashed line
        painter.setBrush(Qt::NoBrush);

        QVector<QPoint> translatedPoints;
        for (const QPoint& point : polylinePoints) {
            translatedPoints.append(point);
        }

        painter.drawPolyline(translatedPoints);
    }
}

void DrawArea::mousePressEvent(QMouseEvent* event) {
    qDebug() << "Initial mousePressEvent called - Shape type: " << currentShapeType;

    startPoint = event->pos();

    if (currentShapeType == "Polygon") {
        if (!isDrawingPolygon) {
            // Start drawing a new polygon
            isDrawingPolygon = true;
            polygonVertices.clear();
        }

        // Add vertex to the in-progress polygon
        polygonVertices.append(startPoint);
        update(); // Redraw the area to show the new vertex
    }
    else if (currentShapeType == "Polyline") {
        if (!isDrawingPolyline) {
            // Start drawing a new polyline
            isDrawingPolyline = true;
            polylinePoints.clear();
        }

        // Add point to the in-progress polyline
        polylinePoints.append(startPoint);
        update(); // Redraw the area to show the new point
    }
}

void DrawArea::mouseReleaseEvent(QMouseEvent* event) {
    qDebug() << "Initial mouseReleaseEvent called - Shape type: " << currentShapeType;

    QPoint endPoint = event->pos();

    Shape* shape = nullptr;

    if (currentShapeType == "Circle") {
        int radius = (startPoint - endPoint).manhattanLength();
        shape = new Circle(0, startPoint, radius);
    } else if (currentShapeType == "Rectangle") {
        QRect rect(startPoint, endPoint);
        shape = new Rectangle(rect);
    } else if (currentShapeType == "Ellipse") {
        QSize radii = QSize(std::abs(startPoint.x() - endPoint.x()), std::abs(startPoint.y() - endPoint.y()));
        shape = new Ellipse(0, startPoint, radii);
    } else if (currentShapeType == "Line") {
        shape = new Line(0, startPoint, endPoint, QPoint(0, 0));
    } else if (currentShapeType == "Polygon" && event->button() == Qt::RightButton) {
        // Complete the polygon when right-click is detected
        if (polygonVertices.size() > 2) {
            shape = new Polygon(0, polygonVertices, QPoint(0, 0));
            isDrawingPolygon = false; // Reset polygon drawing state
            polygonVertices.clear(); // Clear vertices for the next polygon
        } else {
            qDebug() << "Polygon requires at least three vertices!";
        }
    } else if (currentShapeType == "Polyline" && event->button() == Qt::RightButton) {
        // Complete the polyline when right-click is detected
        if (polylinePoints.size() > 1) {
            shape = new Polyline(0, polylinePoints, QPoint(0, 0));
            isDrawingPolyline = false; // Reset polyline drawing state
            polylinePoints.clear(); // Clear points for the next polyline
        } else {
            qDebug() << "Polyline requires at least two points!";
        }
    }

    if (shape != nullptr) {
        shapes.addShape(shape);
        emit shapeDrawn(shape);
        update();
    }

    qDebug() << "After mouseReleaseEvent called - Shape type: " << currentShapeType;
}
