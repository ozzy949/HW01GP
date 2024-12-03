#include "shapevector.h"

// Constructor
ShapeVector::ShapeVector() = default;

// Destructor: Deletes all dynamically allocated shapes
ShapeVector::~ShapeVector() {
    for (Shape* shape : shapes) {
        delete shape; // Delete each shape
    }
}

// Add a shape to the ShapeVector
void ShapeVector::addShape(Shape* shape) {
    if (shape != nullptr) {
        shapes.push_back(shape);  // Add shape to vector
    }
}

// Remove a shape by its ID
void ShapeVector::removeShape(int id) {
    for (auto it = shapes.begin(); it != shapes.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it; // Delete the shape
            shapes.erase(it); // Remove it from the vector
            return;
        }
    }
}

// Get a shape by its ID
Shape* ShapeVector::getShape(int id) const {
    for (Shape* shape : shapes) {
        if (shape->getId() == id) {
            return shape;
        }
    }
    return nullptr; // Return nullptr if shape not found
}

// Get the number of shapes stored
int ShapeVector::size() const {
    return shapes.size();
}

// Get a shape at a specific index
Shape* ShapeVector::getShapeAt(int index) const {
    if (index >= 0 && index < size()) {
        return shapes[index];
    }
    return nullptr;
}

// Clear all shapes
void ShapeVector::clear() {
    for (Shape* shape : shapes) {
        delete shape; // Delete each shape
    }
    shapes.resize(0); // Resize the vector to zero
}

// Getter for the shapes vector
const shapeVec& ShapeVector::getShapes() const {
    return shapes;  // Return the shapes vector by reference
}
