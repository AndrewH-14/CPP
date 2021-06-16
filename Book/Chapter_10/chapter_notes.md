Chapter 10: How to work with STL containers and iterators.
==========================================================

An Introduction to STL Containers and Iterators
-----------------------------------------------

### Two types of STL contatiners
1. sequence    - Elements are organized by index.
2. associative - Elements are organized by key.

### Five of the sequence containers
1. vector       - A collection of elements stored in continguous memory.
2. array        - A fixed size collection of elements stored in continguous memory.
3. list         - A doubly linked collection of elements linked to other elements.
4. forward_list - A singly linked collection of elements linked to other element.
5. deque        - A double-ended queue that allows elements to be added to the front or the back.

### Two container adaptors
1. queue - A first-in first-out (FIFO) container.
2. stack - A last-in first-out (LIFO) contatiner.

### Five of the associatve contatiners
1. pair     - A structure that holds a key/value pair.
2. map      - A collection of key/value pairs, sorted by key. They key values must be unique.
3. set      - A collection of keys, sorted by key. The key values must be unique.
4. multimap - A collection of key/value pairs, sorted by key. The key values do not need to be unique.
5. multiset - A collection of keys, sorted by key. The key values do not need to be unique.

### Two member functions shared by all STL containers
1. `begin()` - Returns an iterator that points to the first element.
2. `end()`   - Returns an iterator that points to one memory location past the last element.

### Examples
Defining an iterator
```
vector<double>::iterator b1 = prices.begin(); // explicitly define type
auto b2 = prices.begin(); // compiler infers vector<double>::iterator
```

### Some more member functions shared by the STL containers
1. `size()`          - Returns the number of elements in the container.
2. `empty()`         - Returns a boolean value indicating whether the container has any data.
3. `insert(i, val)`  - Inserts the value before the iterator specified by i.
4. `erase(i)`        - Removes the element at the iterator specified by i.
5. `clear()`         - Removes all the elements in the container.
6. `swap(container)` - Swaps the data with the data og the container passed to it.

### Examples

More Skills for working with vectors
------------------------------------

### Some member functions shared by the sequence containers
1. `front()` - Returns a refenece to the first element.
2. `back()` - Returns a reference to the last element.
3. `push_back(elem)` - Adds a new element to the end, or back, of the sequence.
4. `pop_back()` - Removes the element at the end, or back, of the sequence.
5. `resize(n)` - Changes the current size to the size specified by n, destroying elements if needed.
6. `assign(b, e)` - Replaces the current content with interval [b, e) and adjusts the size accordingly.

### Examples

### Some member function of the vector container
1. `at(i)` - Returns the element at index i. Throws an out_of_range exception if i is out of bounds.
2. `capacity()` - Returns the number of elements the vector can curretly store. This is different from `size()`,
which returns the number of elements the vector actually contains.
3. `reserve(n)` - Increases the capacity of the vector to n elements. If n is less than the current capacity,
this function doesn't do anything.

How to work with arrays
-----------------------