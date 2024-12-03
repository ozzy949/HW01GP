#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"
#include <QPainter>
#include <QPoint>
#include <QSize>

// Ellipse class that inherits from Shape
class Ellipse : public Shape {
public:
    // Constructor
    Ellipse(int id, const QPoint& center, const QSize& radii);

    // Implementing virtual functions from Shape
    void draw(QPainter& painter) const override;
    void move(const QPoint& newPosition) override;
    double perimeter() const override;
    double area() const override;

    // Get the bounding rectangle for collision detection
    QRect getRect() const override;

    // Shape Serialization
    std::string toString() const override;

    // Function to instantiate class from String
    static Ellipse* fromString(const std::string& str);

private:
    QPoint center; // Center of the ellipse
    QSize radii;   // Horizontal and vertical radii
};

#endif // ELLIPSE_H
