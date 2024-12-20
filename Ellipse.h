#include "shape.h"
#include <QPainter>
#include <QPoint>
#include <QSize>

class Ellipse : public Shape {
private:
    QPoint center; // Center of the ellipse
    QSize radii;   // Horizontal and vertical radii

public:
    // Constructor
    Ellipse(int id, QPen p, QBrush b, QPoint c, QSize r)
        : Shape(id, p, b), center(c), radii(r) {}

    // Override draw method
    void draw(QPainter& painter) const override {
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawEllipse(center, radii.width(), radii.height());
    }

    // Override move method
    void move(int dx, int dy) override {
        center += QPoint(dx, dy);
    }

    // Override perimeter method
    double perimeter() const override {
        // Approximation using Ramanujan's formula
        double a = radii.width();
        double b = radii.height();
        return M_PI * (3 * (a + b) - std::sqrt((3 * a + b) * (a + 3 * b)));
    }

    // Override area method
    double area() const override {
        return M_PI * radii.width() * radii.height();
    }
};
