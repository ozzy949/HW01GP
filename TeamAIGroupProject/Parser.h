#ifndef PARSER_H_
#define PARSER_H_

#include "Line.h"
#include "Polyline.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Square.h"
#include "Ellipse.h"
#include "Circle.h"
#include "Text.h"
#include "shapevector.h"

#include <fstream>
#include <iostream>
#include <sstream>

class Parser {
private:
    // Helper function to compact shape data into a single string
    std::string compactShapeData(std::ifstream& file) {
        std::ostringstream compacted;
        std::string line;
        std::string shapeTypeLine;

        while (std::getline(file, line)) {

            // If the line contains "ShapeType:", stores a separate string of this line
            if (line.find("ShapeType:") != std::string::npos) {
                // If the line contains "ShapeType:", store it in shapeTypeLine
                shapeTypeLine = line;
                compacted << shapeTypeLine << "\n"; // Add the ShapeType line to compacted data
            }
            // If the line contains "ShapeDimensions:", handle its values properly
            else if (line.find("ShapeDimensions:") != std::string::npos) {
                // Parse the ShapeDimensions (e.g., "20, 90, 100, 20")
                std::string dimensions = line.substr(line.find(":") + 1);  // Get the part after "ShapeDimensions:"
                std::replace(dimensions.begin(), dimensions.end(), ',', ' '); // Replace commas with spaces
                compacted << "ShapeDimensions: " << dimensions << "\n";  // Add it to the compacted data
            }
            else {
                compacted << line << "\n"; // Add line to compacted data
            }

            // Based on the ShapeType line, stop at the last known property of a shape
                if (shapeTypeLine == "ShapeType: Line") { // Line
                    if (line.find("PenJoinStyle:") != std::string::npos)
                    break;
                } else if (shapeTypeLine == "ShapeType: Polyline") { // Polyline
                    if (line.find("PenJoinStyle:") != std::string::npos)
                    break;
                } else if (shapeTypeLine == "ShapeType: Polygon") { // Polygon
                    if (line.find("BrushStyle:") != std::string::npos)
                        break;
                } else if (shapeTypeLine == "ShapeType: Square") { // Square
                    if (line.find("BrushStyle:") != std::string::npos)
                        break;
                } else if (shapeTypeLine == "ShapeType: Rectangle") { // Rectangle
                    if (line.find("BrushStyle:") != std::string::npos)
                        break;
                } else if (shapeTypeLine == "ShapeType: Ellipse") { // Ellipse
                    if (line.find("BrushStyle:") != std::string::npos)
                        break;
                } else if (shapeTypeLine == "ShapeType: Circle") { // Circle
                    if (line.find("BrushStyle:") != std::string::npos)
                        break;
                } else if (shapeTypeLine == "ShapeType: Text") { // Text
                    if (line.find("TextFontWeight:") != std::string::npos)
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
        if (type == "Line") {
            return Line::fromString(data);
        } else if (type == "Polyline") {
            return Polyline::fromString(data);
        } else if (type == "Polygon") {
            return Polygon::fromString(data);
        } else if (type == "Rectangle") {
            return Rectangle::fromString(data);
        } else if (type == "Square") {
            return Square::fromString(data);
        } else if (type == "Ellipse") {
            return Ellipse::fromString(data);
        } else if (type == "Circle") {
            return Circle::fromString(data);
        } else if (type == "Text") {
            return Text::fromString(data);
        }
        return nullptr;
    }

    // Save Shapes to File using a Comparator to sort Shapes and a filter to select shapes
    void saveToFile(ShapeVector& shapes, const std::string& filename,
                    bool (*Comparator)(Shape*, Shape*),
                    bool (*Filter)(Shape*) = nullptr,
                    bool showArea = false, bool showPerimeter = false) {
        shapeVec shapeList = shapes.getShapes();
        // Get the list of shapes from the shape vector

        // Filter shapes based on the provided filter condition if a filter is provided
        if (Filter) {
            // Use remove_if to reorder the vector and find the end of elements that should be removed
            auto newEnd = std::remove_if(shapeList.begin(), shapeList.end(),
                                         [&](Shape* shape) { return !Filter(shape); });
            // After the "newEnd", we have the elements to erase, so we can erase them one by one
            while (newEnd != shapeList.end()) {
                shapeList.erase(newEnd);  // Erase one element at a time
            }
        }

        // Sort the remaining shapes using the provided comparator if one is provided
        if (Comparator) {
            std::sort(shapeList.begin(), shapeList.end(), Comparator);
        }

        // Open the file to save the shapes
        std::ofstream file(filename);
        if (file.is_open()) {
            for (Shape* shape : shapeList) {
                // Write the shape's string representation
                file << shape->toString();

                // Conditionally append area or perimeter to the output
                if (showArea) {
                    file << "Area: " << shape->area() << std::endl;
                }
                if (showPerimeter) {
                    file << "Perimeter: " << shape->perimeter() << std::endl;
                }

                file << std::endl;
            }
        }
    }

    // Comparator function to sort by ID
    static bool compareById(Shape* shape1, Shape* shape2) {
        return shape1->getId() < shape2->getId();
    }

    // Comparator function to sort by area
    static bool compareByArea(Shape* shape1, Shape* shape2) {
        return shape1->area() < shape2->area();
    }

    // Comparator function to sort by perimeter
    static bool compareByPerimeter(Shape* shape1, Shape* shape2) {
        return shape1->perimeter() < shape2->perimeter();
    }

    // Filter function to include only shapes with non-zero area
    static bool filterNonZeroArea(Shape* shape) {
        return shape->area() > 0;
    }

public:

    void generateReportFiles(ShapeVector& shapes) {
        saveToFile(shapes, "reportSortedByID.txt", compareById);
        saveToFile(shapes, "reportSortedByArea.txt", compareByArea, filterNonZeroArea, true, false);
        saveToFile(shapes, "reportSortedByPerimeter.txt", compareByPerimeter, nullptr, false, true);
    }

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
        qDebug() << "File is open for reading.";

        std::string line;
        while (std::getline(file, line)) {
            if (line.find("ShapeId:") == 0) {
                // Handle the first line (ShapeId) explicitly
                std::string shapeIdLine = line;

                // Extract full shape data
                std::string shapeData = compactShapeData(file);
                // Combine ShapeId with the rest of the shape data
                std::string fullShapeData = shapeIdLine + "\n" + shapeData;

                Shape* shape = createShapeFromData(fullShapeData);

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
