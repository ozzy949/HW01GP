#include "Rectangle.h"

// Constructor
Rectangle::Rectangle(int id, QPen pen, QBrush brush, const QPoint& topLeft, int width, int height)
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
    oss << "Rectangle " << getId() << " " << topLeft.x() << " " << topLeft.y() << " "
        << pen.color().name().toStdString() << " " << brush.color().name().toStdString()
        << " " << width << " " << height;
    return oss.str();
}

Rectangle* Rectangle::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string type, penColor, brushColor;
    int id, x, y, w, h;
    iss >> type >> id >> x >> y >> penColor >> brushColor >> w >> h;

    return new Rectangle(id, QPen(QColor(QString::fromStdString(penColor))),
                         QBrush(QColor(QString::fromStdString(brushColor))),
                         QPoint(x, y), w, h);
}
