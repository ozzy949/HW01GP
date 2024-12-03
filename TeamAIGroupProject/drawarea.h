#ifndef DRAWAREA_H
#define DRAWAREA_H

#include "shapevector.h"
#include "circle.h"
#include "rectangle.h"
#include "ellipse.h"
#include "line.h"
#include "polygon.h"
#include <QWidget>
#include <QMouseEvent>
#include <QVector>

/****************************************
 * DrawArea Class
 *
 * This class represents the area used for drawing shapes and rendering them
 * **************************************/

class DrawArea : public QWidget {
    Q_OBJECT

public:
    explicit DrawArea(QWidget* parent = nullptr);
    void setShapeType(const QString& shapeType);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

signals:
    void shapeDrawn(Shape* shape);

private:
    QString currentShapeType;           // Current shape type selected
    QPoint startPoint;                  // Starting point for shapes
    ShapeVector shapes;                 // Use ShapeVector to store shapes

    // Variables for Polygon Drawing
    bool isDrawingPolygon = false;      // Tracks whether a polygon is being drawn
    QVector<QPoint> polygonVertices;    // Stores vertices of the polygon
};

#endif // DRAWAREA_H
