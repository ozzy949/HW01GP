#include "Line.h"
#include <sstream>


void GraphicsWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    // Example pen
    QPen pen(Qt::blue, 3, Qt::DashLine); // Blue dashed line with a width of 3

    // Create a Line
    Line line(1, pen, QPoint(50, 50), QPoint(150, 150)); // Line from (50, 50) to (150, 150)

    // Render the Line
    line.draw(painter);
}

std::string Line::toString() const {
    std::ostringstream oss;

    oss << "ShapeId: " << getId()
        << "\nShapeType: Line"
        << "\nShapeDimensions: " << startPoint.x() << " " << startPoint.y() << " " << endPoint.x() << " " << endPoint.y()
        << "\nPenColor: " << pen.color().name().toStdString()
        << "\nPenWidth: " << pen.width()
        << "\nPenStyle: " << Shape::penStyleToString(pen.style())
        << "\nPenCapStyle: " << Shape::penCapStyleToString(pen.capStyle())
        << "\nPenJoinStyle: " << Shape::penJoinStyleToString(pen.joinStyle())
        << "\n";

    return oss.str();
}

Line* Line::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string label, type;
    int id, x1, y1, x2, y2;
    std::string penColor;
    int penWidth;
    std::string penStyle, penCapStyle, penJoinStyle;

    // Parse the labeled data
    iss >> label >> id;
    iss >> label >> type;
    iss >> label >> x1 >> y1 >> x2 >> y2;
    iss >> label >> penColor;
    iss >> label >> penWidth;
    iss >> label >> penStyle;
    iss >> label >> penCapStyle;
    iss >> label >> penJoinStyle;

    // Create temporary pen object
    QPen t_pen;
    t_pen.setColor(QString::fromStdString(penColor));
    t_pen.setWidth(penWidth);
    t_pen.setStyle(Shape::stringToPenStyle(penStyle));
    t_pen.setCapStyle(Shape::stringToPenCapStyle(penCapStyle));
    t_pen.setJoinStyle(Shape::stringToPenJoinStyle(penJoinStyle));

    // Create and return the Line object
    return new Line(id, QPoint(x1, y1), QPoint(x2, y2), QPoint(x1, y1), t_pen);
}

