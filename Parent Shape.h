#ifndef SHAPE_H
#define SHAPE_H

#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QString>

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

    // Getters
    int getId() const;
    const QPoint& getPosition() const;
    const QPen& getPen() const;
    const QBrush& getBrush() const;

    // Setters
    void setPosition(const QPoint& position);
    void setPen(const QPen& pen);
    void setBrush(const QBrush& brush);

protected:
    int id;              // Unique ID for the shape
    QPoint position;     // Position of the shape
    QPen pen;            // Pen properties
    QBrush brush;        // Brush properties
};

#endif
