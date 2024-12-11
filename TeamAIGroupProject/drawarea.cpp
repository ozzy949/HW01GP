#include "drawarea.h"
#include "mainwindow.h"
#include "ellipse.h"
#include "line.h"
#include "polygon.h"
#include "polyline.h"  // Include Polyline header

DrawArea::DrawArea(QWidget* parent)
    : QWidget(parent), currentShapeType("Line"), isDrawingPolygon(false), isDrawingPolyline(false) {
}

void DrawArea::setShapeType(const QString& shapeType) {
    currentShapeType = shapeType;

    // Reset polygon and polyline drawing if the shape type changes
    if (currentShapeType != "Polygon" && currentShapeType != "Polyline") {
        isDrawingPolygon = false;
        isDrawingPolyline = false;
        polygonVertices.clear();
        polylinePoints.clear();
    }
}

void DrawArea::paintEvent(QPaintEvent* /*event*/) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw all shapes in the ShapeVector
    const shapeVec& shapesList = shapesDrawn.getShapes();  // Get the shapes vector
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

    QPoint endPoint = event->pos();

    Shape* shape = nullptr;
    Shape* shapeFromList; // Shape object using data from shapes.txt to apply pen/brush styles

    if (currentShapeType == "Line") {
        // Make shapeFromList into a shape with the data of the shape with id 1 (line) from shapeList
        shapeFromList = shapeList.getShape(1);
        shape = new Line(1, startPoint, endPoint, QPoint(0, 0));
        shape->setPen(shapeFromList->getPen());
    } else if (currentShapeType == "Polyline" && event->button() == Qt::RightButton) {
        // Make shapeFromList into a shape with the data of the shape with id 2 (polyline) from shapeList
        shapeFromList = shapeList.getShape(2);
        // Complete the polyline when right-click is detected
        if (polylinePoints.size() > 1) {
            shape = new Polyline(2, polylinePoints, QPoint(0, 0));
            shape->setPen(shapeFromList->getPen());
            isDrawingPolyline = false; // Reset polyline drawing state
            polylinePoints.clear(); // Clear points for the next polyline
        } else {
            qDebug() << "Polyline requires at least two points!";
        }
    } else if (currentShapeType == "Polygon" && event->button() == Qt::RightButton) {
        // Make shapeFromList into a shape with the data of the shape with id 3 (polygon) from shapeList
        shapeFromList = shapeList.getShape(3);
        // Complete the polygon when right-click is detected
        if (polygonVertices.size() > 2) {
            shape = new Polygon(3, polygonVertices, QPoint(0, 0));
            shape->setPen(shapeFromList->getPen());
            shape->setBrush(shapeFromList->getBrush());
            isDrawingPolygon = false; // Reset polygon drawing state
            polygonVertices.clear(); // Clear vertices for the next polygon
        } else {
            qDebug() << "Polygon requires at least three vertices!";
        }
    } else if (currentShapeType == "Rectangle") {
        // Make shapeFromList into a shape with the data of the shape with id 4 (rectangle) from shapeList
        shapeFromList = shapeList.getShape(4);
        QRect rect(startPoint, endPoint);
        shape = new Rectangle(4, rect);
        shape->setPen(shapeFromList->getPen());
        shape->setBrush(shapeFromList->getBrush());
    } else if (currentShapeType == "Square") {
        // Make shapeFromList into a shape with the data of the shape with id 5 (square) from shapeList
        shapeFromList = shapeList.getShape(5);
        int sideLength = std::abs(startPoint.x() - endPoint.x());
        shape = new Square(5, startPoint, sideLength);
        shape->setPen(shapeFromList->getPen());
        shape->setBrush(shapeFromList->getBrush());
    } else if (currentShapeType == "Ellipse") {
        // Make shapeFromList into a shape with the data of the shape with id 6 (ellipse) from shapeList
        shapeFromList = shapeList.getShape(6);
        QSize radii = QSize(std::abs(startPoint.x() - endPoint.x()), std::abs(startPoint.y() - endPoint.y()));
        shape = new Ellipse(6, startPoint, radii);
        shape->setPen(shapeFromList->getPen());
        shape->setBrush(shapeFromList->getBrush());
    } else if (currentShapeType == "Circle") {
        // Make shapeFromList into a shape with the data of the shape with id 7 (circle) from shapeList
        shapeFromList = shapeList.getShape(7);
        int radius = (startPoint - endPoint).manhattanLength();
        shape = new Circle(7, startPoint, radius);
        shape->setPen(shapeFromList->getPen());
        shape->setBrush(shapeFromList->getBrush());
    }

    if (shape != nullptr) {
        qDebug() << "Adding Shape";
        shapesDrawn.addShape(shape);
        emit shapeDrawn(shape);
        update();
    }
}

// This function is specifically for getting pen/brush styles from shapes.txt and storing them in shapeList
void DrawArea::loadShapeList() {
    Parser myParser;
    myParser.loadFromFile(shapeList, "shapes.txt");  // Load in shape specifications (pens, brushes), store in shapeList only as a reference for the paint events
    update();
}

// Getter function for shapes drawn so far
ShapeVector& DrawArea::getShapesDrawn() {
    return shapesDrawn;
}

void DrawArea::clearShapesDrawn() {
    shapesDrawn.clear();
}
