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
private:
    // Helper function to compact shape data into a single string
    std::string compactShapeData(std::ifstream& file) {
        std::ostringstream compacted;
        std::string line;

        while (std::getline(file, line)) {
            compacted << line << "\n"; // Add line to compacted data
            // Stop at the last known property of a shape
            if (line.find("BrushStyle:") != std::string::npos ||
                (line.find("PenJoinStyle:") != std::string::npos && line.find("BrushStyle:") == std::string::npos)) {
                break;
            }
        }
        return compacted.str();
    }

    // Helper function to create a shape from its compacted data
    Shape* createShapeFromData(const std::string& data) {
        std::istringstream iss(data);
        std::string line;

        // Get the shape type
        std::getline(iss, line); // First line (ShapeId)
        std::getline(iss, line); // Second line (ShapeType)
        std::string type = line.substr(line.find(":") + 1);
        type.erase(type.begin(), std::find_if(type.begin(), type.end(), [](unsigned char ch) {
                       return !std::isspace(ch);
                   }));

        // Create shape based on the type
        if (type == "Circle") {
            return Circle::fromString(data);
        } else if (type == "Rectangle") {
            return Rectangle::fromString(data);
        } else if (type == "Polygon") {
            return Polygon::fromString(data);
        } else if (type == "Line") {
            return Line::fromString(data);
        } else if (type == "Ellipse") {
            return Ellipse::fromString(data);
        } else if (type == "Text") {
            return Text::fromString(data);
        }
        return nullptr;
    }

public:
    // Save Shapes to File
    void saveToFile(ShapeVector& shapes, const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (Shape* shape : shapes.getShapes()) {
                qDebug() << "Saving shape";
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
        qDebug() << "File is open for reading.";

        std::string line;
        while (std::getline(file, line)) {
            if (line.find("ShapeId:") == 0) {
                // Extract full shape data
                std::string shapeData = compactShapeData(file);
                Shape* shape = createShapeFromData(line + "\n" + shapeData);

                if (shape) {
                    shapes.addShape(shape);
                } else {
                    qDebug() << "Invalid shape data, skipping.";
                }
            }
        }
    }
};

#endif // PARSER_H_
