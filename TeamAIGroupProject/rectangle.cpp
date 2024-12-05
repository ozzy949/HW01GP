#include "rectangle.h"

// Constructor for the Rectangle class
Rectangle::Rectangle(int id, const QRect& rect)
    : Shape(id, rect.topLeft()), rect(rect) {
    // Initialize the shape with its ID and position from the rectangle's top-left corner
}

// Draw the rectangle
void Rectangle::draw(QPainter& painter) const {
    painter.drawRect(rect);  // Draw the rectangle using the QRect's data
}

// Move the rectangle to a new position
void Rectangle::move(const QPoint& newPosition) {
    int dx = newPosition.x() - rect.topLeft().x();  // Calculate the x offset
    int dy = newPosition.y() - rect.topLeft().y();  // Calculate the y offset
    rect.moveTo(rect.topLeft() + QPoint(dx, dy));  // Move the rectangle
}

// Calculate the perimeter of the rectangle
double Rectangle::perimeter() const {
    return 2 * (rect.width() + rect.height());  // Perimeter of a rectangle: 2 * (width + height)
}

// Calculate the area of the rectangle
double Rectangle::area() const {
    return rect.width() * rect.height();  // Area of a rectangle: width * height
}

// Return the bounding box (which is just the rectangle itself)
QRect Rectangle::getRect() const {
    return rect;  // Return the QRect representing the bounds of the rectangle
}

std::string Rectangle::toString() const {
    std::ostringstream oss;

    oss << "ShapeId: " << getId()
        << "\nShapeType: Rectangle"
        << "\nShapeDimensions: " << rect.topLeft().x() << " " << rect.topLeft().y() << " " << rect.height() << " " << rect.width()
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

Rectangle* Rectangle::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string label, type;
    int id, x1, y1, height, width;
    std::string penColor;
    int penWidth;
    std::string penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle;

    // Parse the labeled data
    iss >> label >> id;
    iss >> label >> type;
    iss >> label >> x1 >> y1 >> height >> width;
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


    // Create and return the Rectangle object
    Rectangle* t_rect = new Rectangle(id, QRect(x1, y1, width, height));
    t_rect->setPen(t_pen);
    t_rect->setBrush(t_brush);

    return t_rect;
}
