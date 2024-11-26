#include "Line.h"


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
    oss << "Line " << getId() << " " << startPoint.x() << " " << startPoint.y() << " "
        << endPoint.x() << " " << endPoint.y() << " " << pen.color().name().toStdString();
    return oss.str();
}

Line* Line::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string type, penColor;
    int id, x1, y1, x2, y2;
    iss >> type >> id >> x1 >> y1 >> x2 >> y2 >> penColor;

    return new Line(id, QPoint(x1, y1), QPoint(x2, y2),
                    QPen(QColor(QString::fromStdString(penColor))));
}
