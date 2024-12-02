#include "Text.h"

Text::Text(int id, const int& width, const int& height, const QPoint& pos, const QString& text,
           const QColor& textColor, const Qt::Alignment& align, const QFont& font)
    : Shape(id, pos), text(text), width(width), height(height), textColor(textColor), alignment(align), font(font) {}

void Text::draw(QPainter& painter) const {
    painter.setPen(textColor);
    painter.setFont(font);
}

// Overridden move function
void Text::move(const QPoint& newPosition) {
    position = newPosition;
}

// Overridden perimeter function
double Text::perimeter() const {
    return (2 * width + 2 * height);
}

// Overridden area function
double Text::area() const {
    return (width * height);
}

QRect Text::getRect() const {
    QFontMetrics metrics(font);

    // Get text width and height using the font
    int textWidth = metrics.horizontalAdvance(text);
    int textHeight = metrics.height();

    // Start at the position
    int x = position.x();
    int y = position.y();

    // Adjust x and y based on alignment
    if (alignment & Qt::AlignHCenter) {
        x -= textWidth / 2;  // Center horizontally
    } else if (alignment & Qt::AlignRight) {
        x -= textWidth;      // Align to the right
    }

    if (alignment & Qt::AlignVCenter) {
        y -= textHeight / 2; // Center vertically
    } else if (alignment & Qt::AlignBottom) {
        y -= textHeight;     // Align to the bottom
    }

    // Return the bounding box (top-left corner and size)
    return QRect(QPoint(x, y), QSize(textWidth, textHeight));
}

std::string Text::toString() const {
    std::ostringstream oss;

    oss << "ShapeId: " << getId()
        << "\nShapeType: Text"
        << "\nShapeDimensions: " << position.x() << ", " << position.y() << ", " << width << ", " << height
        << "\nTextString: " << text.toStdString()
        << "\nTextColor: " << textColor.name().toStdString()
        << "\nTextAlignment: " << alignment
        << "\nTextPointSize: " << font.pointSize()
        << "\nTextFontFamily: " << font.family().toStdString()
        << "\nTextFontStyle: " << (font.italic() ? "StyleItalic" : "StyleNormal")
        << "\nTextFontWeight: " << (font.weight() == QFont::Normal ? "Normal" : "Bold")
        << "\n";

    return oss.str();
}

Text* Text::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string label, type, textStr, textColor, fontFamily, fontStyle, fontWeight, alignmentStr;
    int id, x1, y1, width, height, pointSize;

    iss >> label >> id;
    iss >> label >> type;
    iss >> label >> x1 >> y1 >> height >> width;
    iss >> label >> textStr;
    iss >> label >> textColor;
    iss >> label >> alignmentStr;
    iss >> label >> pointSize;
    iss >> label >> fontFamily;
    iss >> label >> fontStyle;
    iss >> label >> fontWeight;

    Qt::Alignment alignment = (alignmentStr == "AlignCenter") ? Qt::AlignCenter :
                                  (alignmentStr == "AlignRight") ? Qt::AlignRight : Qt::AlignLeft;

    QFont font(QString::fromStdString(fontFamily), pointSize);
    font.setItalic(fontStyle == "StyleItalic");
    font.setWeight(fontWeight == "Bold" ? QFont::Bold : QFont::Normal);

    return new Text(id, width, height, QPoint(x1, y1), QString::fromStdString(textStr),
                                QColor(QString::fromStdString(textColor)), alignment, font);
}

