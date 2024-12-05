#include "Polyline.h"
#include <cmath>
#include <sstream>

// Constructor
Polyline::Polyline(int id, const QVector<QPoint>& points, const QPoint& position)
    : Shape(id, position), vertices(points) {}

// Draw the polyline
void Polyline::draw(QPainter& painter) const {
    painter.setPen(pen);
    painter.setBrush(brush);

    // Translate points based on the current position
    QVector<QPoint> translatedPoints;
    for (const QPoint& vertex : vertices) {
        translatedPoints.append(vertex + position);
    }

    // Draw the polyline by connecting the points
    painter.drawPolyline(translatedPoints);
}

// Move the polyline by adjusting its position
void Polyline::move(const QPoint& newPosition) {
    position = newPosition;
}

// Calculate the perimeter of the polyline (sum of distances between consecutive points)
double Polyline::perimeter() const {
    double totalPerimeter = 0.0;
    for (int i = 1; i < vertices.size(); ++i) {
        const QPoint& p1 = vertices[i - 1];
        const QPoint& p2 = vertices[i];
        totalPerimeter += std::hypot(p2.x() - p1.x(), p2.y() - p1.y());
    }
    return totalPerimeter;
}

// Calculate the area of the polyline (area is 0 for a polyline, as it's not a filled shape)
double Polyline::area() const {
    return 0.0; // A polyline has no area
}

// Get the bounding rectangle for collision detection
QRect Polyline::getRect() const {
    if (vertices.isEmpty()) return QRect();

    int minX = vertices[0].x();
    int minY = vertices[0].y();
    int maxX = vertices[0].x();
    int maxY = vertices[0].y();

    for (const QPoint& vertex : vertices) {
        minX = std::min(minX, vertex.x());
        minY = std::min(minY, vertex.y());
        maxX = std::max(maxX, vertex.x());
        maxY = std::max(maxY, vertex.y());
    }

    return QRect(QPoint(minX, minY) + position, QPoint(maxX, maxY) + position);
}

// Serialize the polyline to a string
std::string Polyline::toString() const {
    std::ostringstream oss;

    oss << "ShapeId: " << getId()
        << "\nShapeType: Polyline"
        << "\nShapeDimensions: ";
    for (const QPoint& vertex : vertices) {
        oss << vertex.x() << " " << vertex.y() << " ";
    }
    oss << "\nPenColor: " << pen.color().name().toStdString()
        << "\nPenWidth: " << pen.width()
        << "\nPenStyle: " << Shape::penStyleToString(pen.style())
        << "\nPenCapStyle: " << Shape::penCapStyleToString(pen.capStyle())
        << "\nPenJoinStyle: " << Shape::penJoinStyleToString(pen.joinStyle())
        << "\n";

    return oss.str();
}

// Instantiate the Polyline from a string (deserialize)
Polyline* Polyline::fromString(const std::string& str) {
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
        if (label == "PenColor:") break;
        int x, y;
        iss >> x >> y;
        vertices.append(QPoint(x, y));
    }
    iss >> penColor;
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

    // Create and return the Polyline object
    Polyline* t_polyline = new Polyline(id, vertices, position);
    t_polyline->setPen(t_pen);
    t_polyline->setBrush(t_brush);

    return t_polyline;
}

