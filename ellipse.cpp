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
