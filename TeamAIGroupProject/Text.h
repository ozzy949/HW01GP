#ifndef TEXT_H
#define TEXT_H

#include "shape.h"
#include <QPainter>
#include <QString>
#include <QFont>

class Text : public Shape {
private:
    QString text;         // The text to display
    int width;            // Width of the text bounding box
    int height;           // Height of the text bounding box
    QColor textColor;     // Color of the text
    Qt::Alignment alignment; // Text alignment
    QFont font;           // Font of the text

public:
    // Constructor
    Text(int id, const int& width, const int& height, const QPoint& pos, const QString& text,
         const QColor& textColor, const Qt::Alignment& align, const QFont& font);

    // Overridden Virtual Functions
    void draw(QPainter& painter) const override;
    void move(const QPoint& newPosition) override;
    double perimeter() const override;
    double area() const override;
    std::string toString() const override;

    // Get the bounding rectangle for collision detection
    QRect getRect() const override;

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

#endif
