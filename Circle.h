#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <QPainter>
#include <QPoint>
#include <QSize>




class Circle : public Shape {
    int radius;
    QPen pen;
    QBrush brush;

public:
    Circle(int id,
           const QPoint& center,
           int radius,
           const QPen& pen,
           const QBrush& brush,
           const std::string& color = "black",
           int rotationAngle = 0)
        : Shape("Circle", center.x(), center.y(), color, rotationAngle),
        radius(radius),
        pen(pen),
        brush(brush) {}

    void setRadius(int r) { radius = r; }
    void setPenColor(const QColor& color) { pen.setColor(color); }
    void setPenWidth(int width) { pen.setWidth(width); }
    void setPenStyle(Qt::PenStyle style) { pen.setStyle(style); }
    void setBrushColor(const QColor& color) { brush.setColor(color); }
    void setBrushStyle(Qt::BrushStyle style) { brush.setStyle(style); }

    void draw(QPainter& painter) override {
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawEllipse(QPoint(getXPos(), getYPos()), radius, radius);
    }

    std::string toString() const override;

    // Function to instantiate class from String
    static Circle* fromString(const std::string& str);


};

#endif
