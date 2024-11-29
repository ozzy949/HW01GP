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
    Ellipse(int id, const QPen p, const QBrush b, const QPoint c, const QSize r);

    // Override draw method
    void draw(QPainter& painter) const override {
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawEllipse(center, radii.width(), radii.height());
    }

    // Override move method
    void move(const QPoint& newPosition) override {
        center = newPosition;
    }

    // Override perimeter method
    double perimeter() const override{
        // Approximation using Ramanujan's formula
        double a = radii.width();
        double b = radii.height();
        return M_PI * (3 * (a + b) - std::sqrt((3 * a + b) * (a + 3 * b)));
    }

    // Override area method
    double area() const override {
        return M_PI * radii.width() * radii.height();
    }

    std::string toString() const override;

    // Function to instantiate class from String
    static Ellipse* fromString(const std::string& str);
};

#endif
