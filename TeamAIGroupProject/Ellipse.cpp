#include "Ellipse.h"

Ellipse::Ellipse(int id, const QPoint cen, const QSize r)
    : Shape(id, cen), center(cen), radii(r) {}

void Ellipse::draw(QPainter& painter) const {
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(center, radii.width(), radii.height());
}

// Override move method
void Ellipse::move(const QPoint& newPosition)  {
    center = newPosition;
}

// Override perimeter method
double Ellipse::perimeter() const {
    // Approximation using Ramanujan's formula
    double a = radii.width();
    double b = radii.height();
    return M_PI * (3 * (a + b) - std::sqrt((3 * a + b) * (a + 3 * b)));
}

// Override area method
double Ellipse::area() const {
    return M_PI * radii.width() * radii.height();
}

QRect Ellipse::getRect() const {
    // Calculate the top-left and bottom-right corners of the bounding rectangle
    QPoint topLeft = center - QPoint(radii.width(), radii.height());
    QPoint bottomRight = center + QPoint(radii.width(), radii.height());

    // Return the bounding rectangle, ensuring it is normalized
    return QRect(topLeft, bottomRight).normalized();
}


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
    Ellipse* t_Ellipse = new Ellipse(id, QPoint(x1, y1), QSize(rWidth, rHeight));
    t_Ellipse->setPen(t_pen);
    t_Ellipse->setBrush(t_brush);

    return t_Ellipse;
}
