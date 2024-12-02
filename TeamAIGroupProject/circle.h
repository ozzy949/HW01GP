#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

// Circle class that inherits from Shape
class Circle : public Shape {
public:
    // Constructor
    Circle(int id, const QPoint& center, int radius);

    // Implementing virtual functions from Shape

    void draw(QPainter& painter) const override;
    void move(const QPoint& newPosition) override;
    double perimeter() const override;
    double area() const override;

    // Get the bounding rectangle for collision detection
    QRect getRect() const;

private:
    int radius;  // Radius of the circle
};

#endif // CIRCLE_H
