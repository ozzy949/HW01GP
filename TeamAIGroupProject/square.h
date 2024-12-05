#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape {
public:
    // Constructor that takes an initial position (top-left corner) and side length
    Square(int id, const QPoint& topLeft, int sideLength);

    // Override the pure virtual methods from Shape
    void draw(QPainter& painter) const override;
    void move(const QPoint& newPosition) override;
    double perimeter() const override;
    double area() const override;
    QRect getRect() const override;  // Get the bounding box of the square

    // Shape Serialization
    std::string toString() const override;

    // Function to instantiate class from String
    static Square* fromString(const std::string& str);

private:
    QPoint topLeft;  // The top-left corner of the square
    int sideLength;  // The length of a side of the square
};

#endif // SQUARE_H
