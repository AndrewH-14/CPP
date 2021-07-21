#include "HeapArray.h"

// ----- CONSTRUCTORS ----- //
HeapArray::HeapArray(const int size) {
    array_size = size;                       // set array size property
    arr = new int[array_size] {0};           // allocate memory on heap
}

HeapArray::HeapArray(const HeapArray& tocopy) {                /* COPY */
    array_size = tocopy.array_size;         // copy size 
    arr = new int[array_size];              // allocate memory on heap

    for (int i = 0; i < array_size; i++) {  // copy array values
        arr[i] = tocopy.arr[i];
    }
}

HeapArray::HeapArray(HeapArray&& tomove) {                     /* MOVE */
    array_size = tomove.array_size;         // copy size
    arr = tomove.arr;                       // reset array pointer

    tomove.arr = nullptr;                   // empty HeapArray param
    tomove.array_size = 0;
}

// ----- DESTRUCTOR ----- //
HeapArray::~HeapArray() {
    delete[] arr;                          // deallocate memory 
}

// ----- ASSIGNMENT OPERATORS ----- //
HeapArray& HeapArray::operator= (const HeapArray& tocopy) {     /* COPY */
    array_size = tocopy.array_size;          // copy size 
    int* new_arr = new int[array_size];      // allocate memory on heap    

    for (int i = 0; i < array_size; ++i) {   // copy array values
        new_arr[i] = tocopy.arr[i];
    }

    delete[] arr;                            // deallocate old memory
    arr = new_arr;                           // assign pointer to new memory
    return *this;                            // return a self-reference
}

HeapArray& HeapArray::operator= (HeapArray&& tomove) {           /* MOVE */
    if (this != &tomove) {                  // don't move if passed self
        array_size = tomove.array_size;     // copy size
        delete[] arr;                       // deallocate old memory
        arr = tomove.arr;                   // reset array pointer

        tomove.arr = nullptr;               // empty HeapArray param
        tomove.array_size = 0;
    }
    return *this;                           // return a self-reference
}

// ----- SUBSCRIPT OPERATOR ----- //
int& HeapArray::operator[] (int i) { return arr[i]; }

// ----- MEMBER FUNCTIONS ----- //
int HeapArray::size() const { return array_size; }
int* HeapArray::begin() { return arr; }
int* HeapArray::end() { return arr + array_size; }