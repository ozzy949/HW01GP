#include "square.h"

// Constructor for the Square class
Square::Square(int id, const QPoint& topLeft, int sideLength)
    : Shape(id, topLeft), topLeft(topLeft), sideLength(sideLength) {
    // Initialize the shape with its ID and position from the top-left corner
}

// Draw the square
void Square::draw(QPainter& painter) const {
    painter.setPen(getPen());
    painter.setBrush(getBrush());
    painter.drawRect(QRect(topLeft, QSize(sideLength, sideLength)));  // Draw the square using the top-left position and side length
}

// Move the square to a new position
void Square::move(const QPoint& newPosition) {
    int dx = newPosition.x() - topLeft.x();  // Calculate the x offset
    int dy = newPosition.y() - topLeft.y();  // Calculate the y offset
    topLeft += QPoint(dx, dy);  // Move the top-left corner
}

// Calculate the perimeter of the square
double Square::perimeter() const {
    return 4 * sideLength;  // Perimeter of a square: 4 * sideLength
}

// Calculate the area of the square
double Square::area() const {
    return sideLength * sideLength;  // Area of a square: sideLength^2
}

// Return the bounding box (which is just the square itself)
QRect Square::getRect() const {
    return QRect(topLeft, QSize(sideLength, sideLength));  // Return the QRect representing the bounds of the square
}

// Convert the square's properties to a string
std::string Square::toString() const {
    std::ostringstream oss;

    oss << "ShapeId: " << getId()
        << "\nShapeType: Square"
        << "\nShapeDimensions: " << topLeft.x() << " " << topLeft.y() << " " << sideLength
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

// Parse a string to create a Square object
Square* Square::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string label, type;
    int id, x1, y1, sideLength;
    std::string penColor;
    int penWidth;
    std::string penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle;

    // Parse the labeled data
    iss >> label >> id;
    iss >> label >> type;
    iss >> label >> x1 >> y1 >> sideLength;
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

    // Create and return the Square object
    Square* t_square = new Square(id, QPoint(x1, y1), sideLength);
    t_square->setPen(t_pen);
    t_square->setBrush(t_brush);

    return t_square;
}
