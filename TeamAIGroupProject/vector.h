#ifndef VECTOR_H_
#define VECTOR_H_

#include <algorithm> // std::copy
#include <memory> // std::allocator
using std::copy;

namespace myStd {

template <typename T>
class vector {
    int size_v;   // the size
    T* elem;      // pointer to the elements (or 0)
    int space;    // number of elements plus number of free slots

public:
    vector() : size_v{0}, elem{nullptr}, space{0} {} // default constructor

    explicit vector(int s) : size_v{s}, elem{new T[s]}, space{s} { // alternate constructor
        for (int i = 0; i < size_v; ++i)
            elem[i] = T(); // elements are initialized
    }

    vector(const vector& src) : size_v{src.size_v}, elem{new T[src.size_v]}, space{src.space} { // copy constructor
        copy(src.elem, src.elem + size_v, elem); // copy elements
    }

    vector& operator=(const vector& src) { // copy assignment
        if (this == &src) return *this; // self-assignment check
        T* p = new T[src.size_v]; // allocate new space
        copy(src.elem, src.elem + src.size_v, p); // copy elements
        delete[] elem; // deallocate old space
        elem = p; // now we can reset elem
        size_v = src.size_v;
        space = src.space;
        return *this; // return a self-reference
    }

    ~vector() {
        delete[] elem; // destructor
    }

    T& operator[](int n) {
        return elem[n]; // access: return reference
    }

    const T& operator[](int n) const {
        return elem[n];
    }

    int size() const {
        return size_v;
    }

    int capacity() const {
        return space;
    }

    void resize(int newsize) { // growth
        reserve(newsize);
        for (int i = size_v; i < newsize; ++i)
            elem[i] = T(); // initialize new elements
        size_v = newsize;
    }

    void push_back(const T& d) {
        if (space == 0)
            reserve(8); // start with space for 8 elements
        else if (size_v == space)
            reserve(2 * space); // get more space
        elem[size_v] = d; // add d at end
        ++size_v; // increase the size
    }

    void reserve(int newalloc) {
        if (newalloc <= space) return; // never decrease allocation
        T* new_elem = new T[newalloc]; // allocate new space
        for (int i = 0; i < size_v; ++i)
            new_elem[i] = elem[i]; // copy old elements
        delete[] elem; // deallocate old space
        elem = new_elem;
        space = newalloc;
    }

    using iterator = T*;
    using const_iterator = const T*;

    iterator begin() {
        return (size_v == 0) ? nullptr : &elem[0];
    }

    const_iterator begin() const {
        return (size_v == 0) ? nullptr : &elem[0];
    }

    iterator end() {
        return (size_v == 0) ? nullptr : &elem[size_v];
    }

    const_iterator end() const {
        return (size_v == 0) ? nullptr : &elem[size_v];
    }

    iterator insert(iterator p, const T& val) {
        int index = p - begin();
        if (size_v >= space)
            reserve(space == 0 ? 8 : 2 * space);
        p = begin() + index;
        for (iterator pos = end(); pos != p; --pos)
            *pos = *(pos - 1);
        *p = val;
        ++size_v;
        return p;
    }

    iterator erase(iterator p) {
        if (p == end()) return p;
        for (iterator pos = p + 1; pos != end(); ++pos)
            *(pos - 1) = *pos; // copy element one position to the left
        --size_v;
        return p;
    }
};

} // namespace myStd

#endif /* VECTOR_H_ */
