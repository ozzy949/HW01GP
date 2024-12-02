#include "circle.h"
#include <QPainter>
#include <QPoint>

// Constructor implementation
Circle::Circle(int id, const QPoint& center, int radius) : Shape(id, center), radius(radius) {}

// Draw function: Draws the circle on the painter
void Circle::draw(QPainter& painter) const {
    painter.setPen(getPen());            // Set the pen for the circle
    painter.setBrush(getBrush());        // Set the brush for the circle
    painter.drawEllipse(getPosition(), radius, radius);  // Draw the circle at the given position with the given radius
}

// Move function: Moves the circle by updating its position
void Circle::move(const QPoint& newPosition) {
    setPosition(newPosition);  // Update the position of the circle
}

// Perimeter function: Returns the perimeter (circumference) of the circle
double Circle::perimeter() const {
    return 2 * 3.141592653589793 * radius;  // 2πr
}

// Area function: Returns the area of the circle
double Circle::area() const {
    return 3.141592653589793 * radius * radius;  // πr²
}

// getRect function: Returns the bounding rectangle of the circle
QRect Circle::getRect() const {
    // Create a QRect that represents the bounding box for the circle
    return QRect(getPosition() - QPoint(radius, radius), QSize(2 * radius, 2 * radius));
}

std::string Circle::toString() const {
    std::ostringstream oss;

    oss << "ShapeId: " << getId()
        << "\nShapeType: Circle"
        << "\nShapeDimensions: " << position.x() << position.y() << radius
        << "\nPenColor: " << pen.color().name().toStdString()
        << "\nPenWidth: " << pen.width()
        << "\nPenStyle: " << Shape::penStyleToString(pen.style())
        << "\nPenCapStyle: " << Shape::penCapStyleToString(pen.capStyle())
        << "\nPenJoinStyle: " << Shape::penJoinStyleToString(pen.joinStyle())
        << "\nBrushColor: " << brush.color().name().toStdString()
        << "\nBrushStyle: " << Shape::brushStyleToString(brush.style())
        << "\n";

    return oss.str();
}

Circle* Circle::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string label, type;
    int id, x1, y1, radius;
    std::string penColor;
    int penWidth;
    std::string penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle;

    // Parse the labeled data
    iss >> label >> id;
    iss >> label >> type;
    iss >> label >> x1 >> y1 >> radius;
    iss >> label >> penColor;
    iss >> label >> penWidth;
    iss >> label >> penStyle;
    iss >> label >> penCapStyle;
    iss >> label >> penJoinStyle;
    iss >> label >> brushColor;
    iss >> label >> brushStyle;

    // Create temporary pen object
    QPen t_pen;
    t_pen.setColor(QString::fromStdString(penColor));
    t_pen.setWidth(penWidth);
    t_pen.setStyle(Shape::stringToPenStyle(penStyle));
    t_pen.setCapStyle(Shape::stringToPenCapStyle(penCapStyle));
    t_pen.setJoinStyle(Shape::stringToPenJoinStyle(penJoinStyle));

    // Create temporary brush object
    QBrush t_brush;
    t_brush.setColor(QString::fromStdString(brushColor));
    t_brush.setStyle(Shape::stringToBrushStyle(brushStyle));

    // Create and return the Circle object
    Circle* t_circle = new Circle(id, QPoint(x1, y1), radius);
    t_circle->setPen(t_pen);
    t_circle->setBrush(t_brush);

    return t_circle;
}
