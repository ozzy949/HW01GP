#ifndef PARSER_H_
#define PARSER_H_

#include "Polygon.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "Ellipse.h"
#include "Text.h"
#include "shapevector.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <qDebug>

class Parser {
public:
    // Save Shapes to File
    void saveToFile(ShapeVector& shapes, const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (Shape* shape : shapes.getShapes()) {
                file << shape->toString() << std::endl;
            }
        }
    }

    // Load Shapes from File
    void loadFromFile(ShapeVector& shapes, const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            qDebug() << "Unable to open file for reading.";
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            if (line.find("ShapeId:") == 0) { // Look for the "ShapeId" label
                std::string typeLine;
                if (std::getline(file, typeLine) && typeLine.find("ShapeType:") == 0) {
                    // Extract the shape type
                    std::string type = typeLine.substr(typeLine.find(":") + 1);
                    type.erase(type.begin(), std::find_if(type.begin(), type.end(), [](unsigned char ch) {
                                   return !std::isspace(ch);
                               }));

                    qDebug() << "Processing ShapeId: " << QString::fromStdString(line)
                             << ", ShapeType: " << QString::fromStdString(type);

                    // Create shape based on the type
                    Shape* shape = nullptr;
                    if (type == "Circle") {
                        shape = Circle::fromString(line);
                    } else if (type == "Rectangle") {
                        shape = Rectangle::fromString(line);
                    } else if (type == "Polygon") {
                        shape = Polygon::fromString(line);
                    } else if (type == "Line") {
                        shape = Line::fromString(line);
                    } else if (type == "Ellipse") {
                        shape = Ellipse::fromString(line);
                    } else if (type == "Text") {
                        shape = Text::fromString(line);
                    }

                    // Add the shape if valid
                    if (shape) {
                        shapes.addShape(shape);
                    }
                }
            }
        }
    }
};

#endif // PARSER_H_
