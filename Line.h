#include "shape.h"
#include <QPainter>
#include <QPoint>
#include <QSize>

class Line : public Shape {
private:
    int x2, y2; //Endpoint coordinates for the line

public: 
    Line() : Shape("Line", 0, 0, "Black", 0), x2(0), y2(0) {}

    Line(int x1, int y1, int x2, int y2, std::string color, int rotationAngle)
        : Shape("Line", x1, y1, color, rotationAngle), x2(x2), y2(y2) {}

    void draw() override {
        //drawing logic

    }

    double perimeter() const {
        return std::hypot(x2- getXPos(), y2 - getYPos()); // formula to find distance
    }

    double area() const {
        return 0; //line has no area
    }

    std::string getStringFormat() const override{
        return getType() + " " + to_string(getXPos())+ " " + to_string(getYPos()) + " " + getColor() + " " +
               to_string(getRotationAngle()) + " " + to_string(x2) + " " + to_string(y2);
        }
    };