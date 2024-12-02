#ifndef ELLIPSE_H
#define ELLIPSE_H


#include "Shape.h"
#include <QPainter>
#include <QPoint>
#include <QSize>

class Ellipse : public Shape {
private:
    QPoint center; // Center of the ellipse
    QSize radii;   // Horizontal and vertical radii

public:
    // Constructor
    Ellipse(int id, const QPoint cen, const QSize r);

    // Overridden Virtual Functions
    void draw(QPainter& painter) const override;
    void move(const QPoint& newPosition) override;
    double perimeter() const override;
    double area() const override;

    // Get the bounding rectangle for collision detection
    QRect getRect() const override;

    std::string toString() const override;

    // Function to instantiate class from String
    static Ellipse* fromString(const std::string& str);
};

#endif
