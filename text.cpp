#include "text.h"

// Example rendering method in your QWidget subclass
void GraphicsWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    // Example font and color
    QFont font("Arial", 14, QFont::Bold);
    QColor color(Qt::black);

    // Create a Text object
    Text text(2, QPen(), "Hello, 2D Graphics!", QPoint(50, 50), color, Qt::AlignLeft, font);

    // Render the Text
    text.draw(painter);
}
