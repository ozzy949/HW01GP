#include "ellipse.h"
#include <QPainter>
#include <QDebug>
#include <cmath>

// Constructor implementation
Ellipse::Ellipse(int id, const QPoint& center, const QSize& radii)
    : Shape(id, center), center(center), radii(radii) {}

// Draw function: Draws the ellipse on the painter
void Ellipse::draw(QPainter& painter) const {
    qDebug() << "Drawing Ellipse"; // Debugging output
    painter.setPen(getPen());     // Set the pen for the ellipse
    painter.setBrush(getBrush()); // Set the brush for the ellipse
    painter.drawEllipse(center, radii.width(), radii.height());
}

// Move function: Moves the ellipse by updating its position
void Ellipse::move(const QPoint& newPosition) {
    center = newPosition; // Update the center of the ellipse
    setPosition(newPosition); // Update the position in the base class
}

// Perimeter function: Returns an approximate perimeter of the ellipse
double Ellipse::perimeter() const {
    // Approximation using Ramanujan's formula
    double a = radii.width();
    double b = radii.height();
    return M_PI * (3 * (a + b) - std::sqrt((3 * a + b) * (a + 3 * b)));
}

// Area function: Returns the area of the ellipse
double Ellipse::area() const {
    return M_PI * radii.width() * radii.height(); // π * a * b
}

// getRect function: Returns the bounding rectangle of the ellipse
QRect Ellipse::getRect() const {
    QPoint topLeft = center - QPoint(radii.width(), radii.height());
    QPoint bottomRight = center + QPoint(radii.width(), radii.height());
    return QRect(topLeft, bottomRight).normalized(); // Ensure rectangle is normalized
}

// toString function: Serializes the ellipse's data to a string
std::string Ellipse::toString() const {
    std::ostringstream oss;

    oss << "ShapeId: " << getId()
        << "\nShapeType: Ellipse"
        << "\nShapeDimensions: " << center.x() << " " << center.y() << " "
        << radii.width() << " " << radii.height()
        << "\nPenColor: " << getPen().color().name().toStdString()
        << "\nPenWidth: " << getPen().width()
        << "\nPenStyle: " << Shape::penStyleToString(getPen().style())
        << "\nPenCapStyle: " << Shape::penCapStyleToString(getPen().capStyle())
        << "\nPenJoinStyle: " << Shape::penJoinStyleToString(getPen().joinStyle())
        << "\nBrushColor: " << getBrush().color().name().toStdString()
        << "\nBrushStyle: " << Shape::brushStyleToString(getBrush().style())
        << "\n";

    return oss.str();
}

// fromString function: Deserializes a string to create an Ellipse object
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

    // Create and return the Ellipse object
    Ellipse* t_ellipse = new Ellipse(id, QPoint(x1, y1), QSize(rWidth, rHeight));
    t_ellipse->setPen(t_pen);
    t_ellipse->setBrush(t_brush);

    return t_ellipse;
}
