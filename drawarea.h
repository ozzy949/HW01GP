#ifndef DRAWAREA_H
#define DRAWAREA_H

#include "shapevector.h"
#include "Parser.h"
#include "circle.h"
#include "rectangle.h"
#include <QWidget>
#include <QMouseEvent>

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
    void loadShapes(const QString& filename);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

signals:
    void shapeDrawn(Shape* shape);

private:
    QString currentShapeType;
    QPoint startPoint;
    ShapeVector shapes; // Use ShapeVector to store shapes
    Parser parser;
};

#endif // DRAWAREA_H
