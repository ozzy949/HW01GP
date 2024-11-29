#include "Rectangle.h"

// Constructor
Rectangle::Rectangle(int id, QPen pen, QBrush brush, const QPoint& topLeft, int height, int width)
    : Shape(id, topLeft), width(width), height(height)
{
    this->pen = pen;
    this->brush = brush;
}

void Rectangle::draw(QPainter& painter) const
{
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(topLeft.x(), topLeft.y(), width, height);
}

void Rectangle::move(const QPoint& newPosition)
{
    topLeft = newPosition;
}

double Rectangle::perimeter() const
{
    return 2.0 * (width + height);
}

double Rectangle::area() const {
    return static_cast<double>(width) * height;
}

std::string Rectangle::toString() const {
    std::ostringstream oss;

    oss << "ShapeId: " << getId()
        << "\nShapeType: Rectangle"
        << "\nShapeDimensions: " << topLeft.x() << " " << topLeft.y() << " " << height << " " << width
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

Rectangle* Rectangle::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string label, type;
    int id, x1, y1, height, width;
    std::string penColor;
    int penWidth;
    std::string penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle;

    // Parse the labeled data
    iss >> label >> id;
    iss >> label >> type;
    iss >> label >> x1 >> y1 >> height >> width;
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
    return new Rectangle(id, t_pen, t_brush, QPoint(x1, y1), height, width);
}
