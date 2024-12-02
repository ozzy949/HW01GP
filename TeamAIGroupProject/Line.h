#ifndef LINE_H_
#define LINE_H_

#include "Shape.h"
#include <QPainter>
#include <QPoint>
#include <QSize>

class Line : public Shape {
    QPoint startPoint, endPoint;

public:
    Line(int id, const QPoint& p1, const QPoint& p2, const QPoint& position);

    void setStartPoint(const QPoint& point) { startPoint = point; }
    void setEndPoint(const QPoint& point) { endPoint = point; }
    void setPenColor(const QColor& color) { pen.setColor(color); }
    void setPenWidth(int width) { pen.setWidth(width); }
    void setPenStyle(Qt::PenStyle style) { pen.setStyle(style); }
    void setPenCapStyle(Qt::PenCapStyle capStyle) { pen.setCapStyle(capStyle); }
    void setPenJoinStyle(Qt::PenJoinStyle joinStyle) { pen.setJoinStyle(joinStyle); }

    void draw(QPainter& painter) const override;
    void move(const QPoint& newPosition) override;
    double perimeter() const override;
    double area() const override;

    // Get the bounding rectangle for collision detection
    QRect getRect() const override;

    std::string toString() const override;

    // Function to instantiate class from String
    static Line* fromString(const std::string& str);
};

#endif
