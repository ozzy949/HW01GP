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

std::string Text::toString() const {
    std::ostringstream oss;
    oss << "Text " << getId() << " "
        << text.toStdString() << " "
        << position.x() << " " << position.y() << " "
        << textColor.name().toStdString() << " "
        << alignment << " "
        << font.toString().toStdString();
    return oss.str();
}

Text* Text::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string type, textString, colorName, fontString;
    int id, x, y, alignValue;

    iss >> type >> id >> textString >> x >> y >> colorName >> alignValue;
    std::getline(iss, fontString);  // Read remaining font details

    return new Text(id,
                    QPen(),
                    QString::fromStdString(textString),
                    QPoint(x, y),
                    QColor(QString::fromStdString(colorName)),
                    static_cast<Qt::Alignment>(alignValue),
                    QFont(QString::fromStdString(fontString)));
}
