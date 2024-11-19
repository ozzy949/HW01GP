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
