#ifndef PARSER_H_
#define PARSER_H_

#include "Polygon.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "Ellipse.h"
#include "Text.h"

#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

class Parser {
public:
    // Save Shapes to File
    void saveToFile(const std::vector<Shape*>& shapes, const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& shape : shapes) {
                file << shape->toString() << std::endl; // Adjusted to use toStdString
            }
        }
    }

    // Load Shapes from File
    void loadFromFile(std::vector<Shape*>& shapes, const std::string& filename) {
        std::ifstream file(filename);
        std::string line;

        if (file.is_open()) {

            // Read Each Line
            while (std::getline(file, line)) {

                // For each line, get the shape type
                std::istringstream iss(line);
                std::string type;
                iss >> type;

                // Create shape based off type
                if (type == "Rectangle") {
                    shapes.push_back(Rectangle::fromString(line));
                } else if (type == "Polygon") {
                    shapes.push_back(Polygon::fromString(line));
                } else if (type == "Circle") {
                    shapes.push_back(Circle::fromString(line));
                } else if (type == "Line") {
                    shapes.push_back(Line::fromString(line));
                } else if (type == "Ellipse") {
                    shapes.push_back(Ellipse::fromString(line));
                } else if (type == "Text") {
                    shapes.push_back(Text::fromString(line));
                }
            }
        }
    }
};

#endif // PARSER_H_
