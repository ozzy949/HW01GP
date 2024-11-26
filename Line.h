#ifndef LINE_H_
#define LINE_H_

#include "Shape.h"
#include <QPainter>
#include <QPoint>
#include <QSize>

class Line : public Shape {
    QPoint startPoint, endPoint;
    QPen pen;

public:
    Line(int id,
         const QPoint& start,
         const QPoint& end,
         const QPen& pen,
         const std::string& color = "black",
         int rotationAngle = 0)
        : Shape("Line", start.x(), start.y(), color, rotationAngle),
        startPoint(start),
        endPoint(end),
        pen(pen) {}

    void setStartPoint(const QPoint& point) { startPoint = point; }
    void setEndPoint(const QPoint& point) { endPoint = point; }
    void setPenColor(const QColor& color) { pen.setColor(color); }
    void setPenWidth(int width) { pen.setWidth(width); }
    void setPenStyle(Qt::PenStyle style) { pen.setStyle(style); }
    void setPenCapStyle(Qt::PenCapStyle capStyle) { pen.setCapStyle(capStyle); }
    void setPenJoinStyle(Qt::PenJoinStyle joinStyle) { pen.setJoinStyle(joinStyle); }

    void draw(QPainter& painter) override {
        painter.setPen(pen);
        painter.drawLine(startPoint, endPoint);
    }

    std::string toString() const override;

    // Function to instantiate class from String
    static Line* fromString(const std::string& str);
};

#endif
