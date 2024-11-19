#include "Shape.h"

// Constructor
Shape::Shape(int id, const QPoint& position)
    : id(id), position(position), pen(Qt::black, 1), brush(Qt::NoBrush) {}

// Getters
int Shape::getId() const {
    return id;
}

const QPoint& Shape::getPosition() const {
    return position;
}

const QPen& Shape::getPen() const {
    return pen;
}

const QBrush& Shape::getBrush() const {
    return brush;
}

// Setters
void Shape::setPosition(const QPoint& position) {
    this->position = position;
}

void Shape::setPen(const QPen& pen) {
    this->pen = pen;
}

void Shape::setBrush(const QBrush& brush) {
    this->brush = brush;
}
