#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"
#include <QVector>
#include <QPoint>

// Derived class for Polygon
class Polygon : public Shape {
public:
    // Constructor
    Polygon(int id, const QVector<QPoint>& points, const QPoint& position,
            const QPen& pen, const QBrush& brush);

    // Disable copy operations
    Polygon(const Polygon&) = delete;
    Polygon& operator=(const Polygon&) = delete;

    // Overridden Virtual Functions
    void draw(QPainter& painter) const override;
    void move(const QPoint& newPosition) override;
    double perimeter() const override;
    double area() const override;
    std::string toString() const override;

    // Function to instantiate class from String
    static Polygon* fromString(const std::string& str);

private:
    QVector<QPoint> vertices; // Vertices of the polygon relative to the position
};

#endif // POLYGON_H
