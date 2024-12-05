#ifndef SHAPE_H
#define SHAPE_H

#include <sstream>
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QString>
#include <QPoint>
#include <QRect>
#include <QDebug>

// Abstract Base Class for Shape
class Shape
{
public:
    // Constructor
    Shape(int id, const QPoint& position);

    // Virtual Destructor
    virtual ~Shape() = default;

    // Pure Virtual Functions
    virtual void draw(QPainter& painter) const = 0;
    virtual void move(const QPoint& newPosition) = 0;
    virtual double perimeter() const = 0;
    virtual double area() const = 0;

    // Serialization
    virtual std::string toString() const = 0;

    // Getters
    int getId() const;
    const QPoint& getPosition() const;
    const QPen& getPen() const;
    const QBrush& getBrush() const;

    // Setters
    void setPosition(const QPoint& position);
    void setPen(const QPen& pen);
    void setBrush(const QBrush& brush);

    // Virtual function to return the bounding box of the shape (for selection, etc.)
    virtual QRect getRect() const = 0;

protected:
    int id;              // Unique ID for the shape
    QPoint position;     // Position of the shape
    QPen pen;            // Pen properties
    QBrush brush;        // Brush properties

    // toString() helper functions
    // Qt enums to String
    std::string penStyleToString(Qt::PenStyle style) const;
    std::string penCapStyleToString(Qt::PenCapStyle capStyle) const;
    std::string penJoinStyleToString(Qt::PenJoinStyle joinStyle) const;
    std::string brushStyleToString(Qt::BrushStyle brushStyle) const;


    // String to Qt enums
    static Qt::PenStyle stringToPenStyle(const std::string& style);
    static Qt::PenCapStyle stringToPenCapStyle(const std::string& style);
    static Qt::PenJoinStyle stringToPenJoinStyle(const std::string& style);
    static Qt::BrushStyle stringToBrushStyle(const std::string& styleStr);
};

#endif
