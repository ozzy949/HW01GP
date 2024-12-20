#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <QPainter>
#include <QPoint>
#include <QSize>


// Derived class for Rectangle 
class Rectangle : public Shape 
{
private:
    QPoint topLeft;
    int width;
    int height;

public:
    // Constructor 
    Rectangle(int id, QPen pen, QBrush brush, const QPoint& topLeft, int width, int height)
        : Shape(id, topLeft), width(width), height(height) {}

    // Virtual functions 
    void draw(QPainter& painter) const override;                
    void move(const QPoint& newPosition) override; 
    double perimeter() const override; 
    double area() const override;      

};

#endif 
