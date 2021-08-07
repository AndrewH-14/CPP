#ifndef MURACH_HEAPARRAY_H
#define MURACH_HEAPARRAY_H

class HeapArray {
private:
    int array_size;
    int* arr = nullptr;

public:
    // constructors 
    HeapArray(const int);
    HeapArray(const HeapArray& tocopy);     // copy constructor
    HeapArray(HeapArray&& tomove);          // move constructor

                                            // destructor
    ~HeapArray();

    // assignment operators
    HeapArray& operator= (const HeapArray& tocopy);  // copy assignment
    HeapArray& operator= (HeapArray&& tomove);       // move assignment

    // subscript operator 
    int& operator[] (int i);

    // Member functions
    int size() const;
    int* begin();
    int* end();
};

#endif /* MURACH_HEAPARRAY_H */
