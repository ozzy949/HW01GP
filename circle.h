#include "shape.h"
#include <QPainter>
#include <QPoint>
#include <QSize>

class Circle : public Shape {
    private:
    int radius;

    public:
        Circle() : Shape("Circle", 0, 0, "Black", 0), radius(1) {}

        Circle (int x, int y, std::string color, int rotationAngle, int _radius)
            :Shape{"Circle", x, y, color, rotationAngle}, radius{_radius} {}

    void draw() override {
            //draw logic 

    }

    double perimeter() const  {
        return 2 * M_PI * radius;      // 2 pr r is formula for circumference/ perimeter 
    }

    std::string getStringFormat() const override {
        return getType() + " " + to_string(getXPos()) + " " + to_string(getYPos()) + " " + getColor() + " " +
            to_string(getRotationAngle()) + " " + to_string(radius);

    }
};

#endif