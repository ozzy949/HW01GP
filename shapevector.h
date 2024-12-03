#ifndef SHAPEVECTOR_H
#define SHAPEVECTOR_H

#include "shape.h"
#include "vector.h"

// Define vector_t as a custom vector of Shape pointers
using shapeVec = myStd::vector<Shape*>;

// The ShapeVector class manages the collection of shapes
class ShapeVector {
public:
    // Constructor
    ShapeVector();

    // Destructor to clean up dynamically allocated shapes
    ~ShapeVector();

    // Add a shape to the storage
    void addShape(Shape* shape);

    // Remove a shape by its ID
    void removeShape(int id);

    // Get a shape by its ID
    Shape* getShape(int id) const;

    // Get the total number of shapes stored
    int size() const;

    // Get the shape at a specific index
    Shape* getShapeAt(int index) const;

    // Clear all shapes from storage
    void clear();

    // Getter for the shapes vector
    const shapeVec& getShapes() const;  // Provide a getter to access shapes

private:
    shapeVec shapes; // Vector to hold shapes
};

#endif // SHAPEVECTOR_H

