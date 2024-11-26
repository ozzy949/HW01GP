#include "shape.h"
#include <QPainter>
#include <QString>
#include <QPoint>
#include <QFont>

class Text : public Shape {
private:
    QString text;         // The text to display
    QPoint position;      // Position of the text
    QColor textColor;     // Color of the text
    Qt::Alignment alignment; // Text alignment
    QFont font;           // Font of the text

public:
    // Constructor
    Text(int id, QPen p, QString t, QPoint pos, QColor color, Qt::Alignment align, QFont f)
        : Shape(id, p, QBrush()), text(t), position(pos), textColor(color), alignment(align), font(f) {}

    // Override draw method
    void draw(QPainter& painter) const override {
        painter.setPen(textColor);
        painter.setFont(font);

        // Draw text at the specified position
        painter.drawText(position, text);
    }

    // Override move method
    void move(int dx, int dy) override {
        position += QPoint(dx, dy);
    }

    // Override perimeter method (not applicable to text, return 0)
    double perimeter() const override {
        return 0.0;
    }

    // Override area method (not applicable to text, return 0)
    double area() const override {
        return 0.0;
    }

    std::string toString() const override;

    // Function to instantiate class from String
    static Text* fromString(const std::string& str);

    // Setters for text properties
    void setText(const QString& t) { text = t; }
    void setPosition(const QPoint& pos) { position = pos; }
    void setTextColor(const QColor& color) { textColor = color; }
    void setAlignment(Qt::Alignment align) { alignment = align; }
    void setFont(const QFont& f) { font = f; }

    // Getters for text properties
    QString getText() const { return text; }
    QPoint getPosition() const { return position; }
    QColor getTextColor() const { return textColor; }
    Qt::Alignment getAlignment() const { return alignment; }
    QFont getFont() const { return font; }
};
