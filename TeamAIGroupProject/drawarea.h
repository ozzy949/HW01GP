#ifndef DRAWAREA_H
#define DRAWAREA_H

#include "shapevector.h"
#include "circle.h"
#include "rectangle.h"
#include "ellipse.h"
#include "line.h"
#include "polygon.h"
#include "polyline.h"  // Include Polyline header
#include <QWidget>
#include <QMouseEvent>
#include <QVector>

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
    QString currentShapeType;
    QPoint startPoint;
    ShapeVector shapes;  // Use ShapeVector to store shapes
    QVector<QPoint> polygonVertices;  // Store vertices for Polygon
    QVector<QPoint> polylinePoints;   // Store points for Polyline
    bool isDrawingPolygon;  // Flag to track polygon drawing
    bool isDrawingPolyline;  // Flag to track polyline drawing
};

#endif // DRAWAREA_H
