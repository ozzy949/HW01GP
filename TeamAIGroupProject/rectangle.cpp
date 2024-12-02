#include "rectangle.h"

// Constructor for the Rectangle class
Rectangle::Rectangle(const QRect& rect)
    : Shape(0, rect.topLeft()), rect(rect) {
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
