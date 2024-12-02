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
