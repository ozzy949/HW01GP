#include "ellipse.h"

void GraphicsWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    // Example pen and brush
    QPen pen(Qt::blue, 2, Qt::SolidLine);
    QBrush brush(Qt::yellow, Qt::SolidPattern);

    // Create an Ellipse
    Ellipse ellipse(1, pen, brush, QPoint(100, 100), QSize(50, 30));

    // Render the Ellipse
    ellipse.draw(painter);
}

std::string Ellipse::toString() const {
    std::ostringstream oss;
    oss << "Ellipse " << getId() << " " << center.x() << " " << center.y() << " "
        << pen.color().name().toStdString() << " " << brush.color().name().toStdString()
        << " " << radii.width() << " " << radii.height();
    return oss.str();
}

Ellipse* Ellipse::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string type, penColor, brushColor;
    int id, x, y, rx, ry;
    iss >> type >> id >> x >> y >> penColor >> brushColor >> rx >> ry;

    return new Ellipse(id, QPen(QColor(QString::fromStdString(penColor))),
                       QBrush(QColor(QString::fromStdString(brushColor))),
                       QPoint(x, y), QSize(rx, ry));
}
