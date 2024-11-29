#include "circle.h"


void GraphicsWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    // Example pen and brush
    QPen pen(Qt::red, 2, Qt::SolidLine);       // Red pen with a width of 2
    QBrush brush(Qt::green, Qt::SolidPattern); // Green solid brush

    // Create a Circle
    Circle circle(1, pen, brush, QPoint(100, 100), 50); // Circle at (100, 100) with radius 50

    // Render the Circle
    circle.draw(painter);
}

Circle(int id, const QPoint& position, const int& r, const QPen& pen, const QBrush& brush)
    : Shape(id, position), radius(r) {
    this->pen = pen;
    this->brush = brush;
}

void Circle::draw(QPainter& painter) const {
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(position, radius, radius);
}

void Circle::move(const QPoint& newPosition) {
    position = newPosition;
}

double Circle::perimeter() const {

}

double Circle::area() const {

}

std::string Circle::toString() const {
    std::ostringstream oss;

    oss << "ShapeId: " << getId()
        << "\nShapeType: Circle"
        << "\nShapeDimensions: " << position.x() << position.y() << radius
        << "\nPenColor: " << pen.color().name().toStdString()
        << "\nPenWidth: " << pen.width()
        << "\nPenStyle: " << Shape::penStyleToString(pen.style())
        << "\nPenCapStyle: " << Shape::penCapStyleToString(pen.capStyle())
        << "\nPenJoinStyle: " << Shape::penJoinStyleToString(pen.joinStyle())
        << "\nBrushColor: " << brush.color().name().toStdString()
        << "\nBrushStyle: " << Shape::brushStyleToString(brush.style())
        << "\n";

    return oss.str();
}

Circle* Circle::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string label, type;
    int id, x1, y1, radius;
    std::string penColor;
    int penWidth;
    std::string penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle;

    // Parse the labeled data
    iss >> label >> id;
    iss >> label >> type;
    iss >> label >> x1 >> y1 >> radius;
    iss >> label >> penColor;
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

    // Create and return the Line object
    return new Circle(id, QPoint(x1, y1), radius, t_pen, t_brush);
}
