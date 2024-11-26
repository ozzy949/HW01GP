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

std::string Polygon::toString() const {
    std::ostringstream oss;
    oss << "Polygon " << getId() << " " << getPosition().x() << " " << getPosition().y() << " "
        << getPen().color().name().toStdString() << " "
        << getBrush().color().name().toStdString() << " "
        << vertices.size();
    for (const QPoint& vertex : vertices) {
        oss << " " << vertex.x() << " " << vertex.y();
    }
    return oss.str();
}

Polygon* Polygon::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string type, penColor, brushColor;
    int id, x, y, numVertices;
    iss >> type >> id >> x >> y >> penColor >> brushColor >> numVertices;

    QVector<QPoint> points;
    for (int i = 0; i < numVertices; ++i) {
        int vx, vy;
        iss >> vx >> vy;
        points.append(QPoint(vx, vy));
    }

    return new Polygon(id, points, QPoint(x, y), QPen(QColor(QString::fromStdString(penColor))), QBrush(QColor(QString::fromStdString(brushColor))));
}
