#include "Polygon.h"
#include <cmath>

// Constructor
Polygon::Polygon(int id, const QVector<QPoint>& points, const QPoint& position, 
                 const QPen& pen, const QBrush& brush)
    : Shape(id, position), vertices(points) {
    this->pen = pen;
    this->brush = brush;
}

// Overridden draw function
void Polygon::draw(QPainter& painter) const {
    painter.setPen(pen);
    painter.setBrush(brush);

    // Translate points based on the current position
    QVector<QPoint> translatedPoints;
    for (const QPoint& vertex : vertices) {
        translatedPoints.append(vertex + position);
    }

    // Draw the polygon
    painter.drawPolygon(translatedPoints);
}

// Overridden move function
void Polygon::move(const QPoint& newPosition) {
    position = newPosition;
}

// Overridden perimeter function
double Polygon::perimeter() const {
    if (vertices.size() < 2) return 0.0;

    double total = 0.0;
    for (int i = 0; i < vertices.size(); ++i) {
        const QPoint& p1 = vertices[i];
        const QPoint& p2 = vertices[(i + 1) % vertices.size()];
        total += std::hypot(p2.x() - p1.x(), p2.y() - p1.y());
    }
    return total;
}

// Overridden area function
double Polygon::area() const {
    if (vertices.size() < 3) return 0.0;

    double a = 0.0;
    for (int i = 0; i < vertices.size(); ++i) {
        const QPoint& p1 = vertices[i];
        const QPoint& p2 = vertices[(i + 1) % vertices.size()];
        a += p1.x() * p2.y() - p2.x() * p1.y();
    }
    return std::abs(a) / 2.0;
}
