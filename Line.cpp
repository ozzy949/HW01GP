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

