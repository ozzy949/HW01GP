#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
public:
    // Constructor that takes an initial position and size (QRect)
    Rectangle(const QRect& rect);

    // Override the pure virtual methods from Shape
    void draw(QPainter& painter) const override;
    void move(const QPoint& newPosition) override;
    double perimeter() const override;
    double area() const override;
    QRect getRect() const override;  // Get the bounding box of the rectangle

private:
    QRect rect;  // The QRect representing the rectangle's position and size
};

#endif // RECTANGLE_H
