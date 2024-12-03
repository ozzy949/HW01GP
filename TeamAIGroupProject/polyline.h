#ifndef POLYLINE_H
#define POLYLINE_H

#include "Shape.h"
#include <QVector>
#include <QPoint>

class Polyline : public Shape {
public:
    // Constructor that takes an ID, a vector of points, and a position for the polyline
    Polyline(int id, const QVector<QPoint>& points, const QPoint& position);

    // Disable copy operations
    Polyline(const Polyline&) = delete;
    Polyline& operator=(const Polyline&) = delete;

    // Override virtual functions from Shape
    void draw(QPainter& painter) const override;
    void move(const QPoint& newPosition) override;
    double perimeter() const override;
    double area() const override;

    // Get the bounding rectangle for collision detection
    QRect getRect() const override;

    // Convert the shape to a string for serialization
    std::string toString() const override;

    // Function to instantiate the class from a string
    static Polyline* fromString(const std::string& str);

private:
    QVector<QPoint> vertices; // Points that define the polyline
};

#endif // POLYLINE_H
