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

std::string Circle::toString() const {
    std::ostringstream oss;
    oss << "Circle " << getId() << " " << center.x() << " " << center.y() << " "
        << pen.color().name().toStdString() << " " << brush.color().name().toStdString()
        << " " << radius;
    return oss.str();
}

Circle* Circle::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string type, penColor, brushColor;
    int id, x, y, r;
    iss >> type >> id >> x >> y >> penColor >> brushColor >> r;

    return new Circle(id, QPoint(x, y), r,
                      QPen(QColor(QString::fromStdString(penColor))),
                      QBrush(QColor(QString::fromStdString(brushColor))));
}
