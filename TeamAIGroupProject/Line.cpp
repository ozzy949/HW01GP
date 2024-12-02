#include "Line.h"
#include <sstream>

Line::Line(int id, const QPoint& p1, const QPoint& p2, const QPoint& position)
    : Shape(id, position), startPoint(p1), endPoint(p2) {}


void Line::draw(QPainter& painter) const {
    painter.setPen(pen);
    painter.drawLine(startPoint + position, endPoint + position);
}

void Line::move(const QPoint& newPosition) {
    position = newPosition;
}

double Line::perimeter() const {
    return std::hypot(endPoint.x() - startPoint.x(), endPoint.y() - startPoint.y());
}

double Line::area() const {
    return 0.0; // A line has no area
}

// Get the bounding rectangle for collision detection
QRect Line::getRect() const {
    // Adjust the points based on the position
    QPoint adjustedStart = startPoint + position;
    QPoint adjustedEnd = endPoint + position;

    // Use QRect to construct a bounding rectangle
    return QRect(adjustedStart, adjustedEnd).normalized();
}


std::string Line::toString() const {
    std::ostringstream oss;

    oss << "ShapeId: " << getId()
        << "\nShapeType: Line"
        << "\nShapeDimensions: " << startPoint.x() << " " << startPoint.y() << " " << endPoint.x() << " " << endPoint.y()
        << "\nPenColor: " << pen.color().name().toStdString()
        << "\nPenWidth: " << pen.width()
        << "\nPenStyle: " << Shape::penStyleToString(pen.style())
        << "\nPenCapStyle: " << Shape::penCapStyleToString(pen.capStyle())
        << "\nPenJoinStyle: " << Shape::penJoinStyleToString(pen.joinStyle())
        << "\n";

    return oss.str();
}

Line* Line::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string label, type;
    int id, x1, y1, x2, y2;
    std::string penColor;
    int penWidth;
    std::string penStyle, penCapStyle, penJoinStyle;

    // Parse the labeled data
    iss >> label >> id;
    iss >> label >> type;
    iss >> label >> x1 >> y1 >> x2 >> y2;
    iss >> label >> penColor;
    iss >> label >> penWidth;
    iss >> label >> penStyle;
    iss >> label >> penCapStyle;
    iss >> label >> penJoinStyle;

    // Create temporary pen object
    QPen t_pen;
    t_pen.setColor(QString::fromStdString(penColor));
    t_pen.setWidth(penWidth);
    t_pen.setStyle(Shape::stringToPenStyle(penStyle));
    t_pen.setCapStyle(Shape::stringToPenCapStyle(penCapStyle));
    t_pen.setJoinStyle(Shape::stringToPenJoinStyle(penJoinStyle));

    // Create and return the Line object
    Line* t_Line = new Line(id, QPoint(x1, y1), QPoint(x2, y2), QPoint(x1, y1));
    t_Line->setPen(t_pen);

    return t_Line;
}
