#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <QPainter>
#include <QPoint>
#include <QSize>




class Circle : public Shape {
    int radius;
    QPoint center;

public:
    Circle(int id, const QPoint& position, const int& radius,
           const QPen& pen, const QBrush& brush);

    void setRadius(int r) { radius = r; }
    void setPenColor(const QColor& color) { pen.setColor(color); }
    void setPenWidth(int width) { pen.setWidth(width); }
    void setPenStyle(Qt::PenStyle style) { pen.setStyle(style); }
    void setBrushColor(const QColor& color) { brush.setColor(color); }
    void setBrushStyle(Qt::BrushStyle style) { brush.setStyle(style); }

    void draw(QPainter& painter) const override;
    void move(const QPoint& newPosition) override;
    double perimeter() const override;
    double area() const override;

    std::string toString() const override;

    // Function to instantiate class from String
    static Circle* fromString(const std::string& str);


};

#endif
