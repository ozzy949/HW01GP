#include "ellipse.h"

void GraphicsWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    // Example pen and brush
    QPen pen(Qt::blue, 2, Qt::SolidLine);
    QBrush brush(Qt::yellow, Qt::SolidPattern);

    // Create an Ellipse
    Ellipse ellipse(1, pen, brush, QPoint(100, 100), QSize(50, 30));

    // Render the Ellipse
    ellipse.draw(painter);
}

Ellipse::Ellipse(int id, const QPen p, const QBrush b, const QPoint c, const QSize r)
    : Shape(id, c), center(c), radii(r) {}

std::string Ellipse::toString() const {
    std::ostringstream oss;

    oss << "ShapeId: " << getId()
        << "\nShapeType: Ellipse"
        << "\nShapeDimensions: " << center.x() << " " << center.y() << " " << radii.width() << " " << radii.height();
    oss << "\nPenColor: " << pen.color().name().toStdString()
        << "\nPenWidth: " << pen.width()
        << "\nPenStyle: " << Shape::penStyleToString(pen.style())
        << "\nPenCapStyle: " << Shape::penCapStyleToString(pen.capStyle())
        << "\nPenJoinStyle: " << Shape::penJoinStyleToString(pen.joinStyle())
        << "\nBrushColor: " << brush.color().name().toStdString()
        << "\nBrushStyle: " << Shape::brushStyleToString(brush.style())
        << "\n";

    return oss.str();
}

Ellipse* Ellipse::fromString(const std::string& str) {
    std::istringstream iss(str);
    std::string label, type;
    int id, x1, y1, rWidth, rHeight;
    std::string penColor;
    int penWidth;
    std::string penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle;

    // Parse the labeled data
    iss >> label >> id;
    iss >> label >> type;
    iss >> label >> x1 >> y1 >> rWidth >> rHeight;
    iss >> label >> penColor;
    iss >> label >> penWidth;
    iss >> label >> penStyle;
    iss >> label >> penCapStyle;
    iss >> label >> penJoinStyle;
    iss >> label >> brushColor;
    iss >> label >> brushStyle;

    // Create temporary pen object
    QPen t_pen;
    t_pen.setColor(QString::fromStdString(penColor));
    t_pen.setWidth(penWidth);
    t_pen.setStyle(Shape::stringToPenStyle(penStyle));
    t_pen.setCapStyle(Shape::stringToPenCapStyle(penCapStyle));
    t_pen.setJoinStyle(Shape::stringToPenJoinStyle(penJoinStyle));

    // Create temporary brush object
    QBrush t_brush;
    t_brush.setColor(QString::fromStdString(brushColor));
    t_brush.setStyle(Shape::stringToBrushStyle(brushStyle));

    // Create and return the Line object
    return new Ellipse(id, t_pen, t_brush, QPoint(x1, y1), QSize(rWidth, rHeight));
}
