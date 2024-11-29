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

    oss << "ShapeId: " << getId()
        << "\nShapeType: Polygon"
        << "\nShapeDimensions: ";
        for (int i = 0; i < vertices.size(); ++i) {
            oss << vertices[i].x() << " " << vertices[i].y() << " ";
        }
    oss << "\nPenColor: " << pen.color().name().toStdString()
        << "\nPenWidth: " << pen.width()
        << "\nPenStyle: " << Shape::penStyleToString(pen.style())
        << "\nPenCapStyle: " << Shape::penCapStyleToString(pen.capStyle())
        << "\nPenJoinStyle: " << Shape::penJoinStyleToString(pen.joinStyle())
        << "\nBrushColor: " << brush.color().name().toStdString()
        << "\nBrushStyle: " << Shape::brushStyleToString(brush.style())
        << "\n";

    return oss.str();
}

Polygon* Polygon::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string label, type;
    int id;
    QVector<QPoint> vertices;
    std::string penColor;
    int penWidth;
    std::string penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle;

    // Parse the labeled data
    iss >> label >> id;
    iss >> label >> type;
    while (iss >> label) {
        int x, y;
        if (label == "PenColor:") break;

        iss >> x >> y;
        vertices.append(QPoint(x, y));
    }
    iss /*>> label*/ >> penColor;
    iss >> label >> penWidth;
    iss >> label >> penStyle;
    iss >> label >> penCapStyle;
    iss >> label >> penJoinStyle;
    iss >> label >> brushColor;
    iss >> label >> brushStyle;

    // Create temporary pen object
    QPen t_pen;
    t_pen.setColor(QString::fromStdString(penColor));
    t_pen.setWidth(penWidth);
    t_pen.setStyle(Shape::stringToPenStyle(penStyle));
    t_pen.setCapStyle(Shape::stringToPenCapStyle(penCapStyle));
    t_pen.setJoinStyle(Shape::stringToPenJoinStyle(penJoinStyle));

    // Create temporary brush object
    QBrush t_brush;
    t_brush.setColor(QString::fromStdString(brushColor));
    t_brush.setStyle(Shape::stringToBrushStyle(brushStyle));

    QPoint position = vertices.empty() ? QPoint(0, 0) : vertices[0];

    // Create and return the Polygon object
    return new Polygon(id, vertices, position, t_pen, t_brush);

}
