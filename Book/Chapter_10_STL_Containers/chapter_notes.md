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

### Basic skills for working with arrays

#### The header file for an array
`#include <array>`

#### The syntax for defining an array
The size parameter must be known at compile time
`array<type, size> array_name`

#### Two examples that define an array
`array<double, 5> prices`

```
int const size = 5;
array<double, size> prices;
```

#### How to loop through all of the values in an array
```
for (double price : prices)
{
    cout << price << ' ';
}
```

How to work with lists
----------------------

### An introduction to lists and forward lists

#### Two types of lists
1. list(doubly linked-list)         - list object can traverse the sequence forwards and backwards. 
2. forward-list(singly linked-list) - list can only travers the sequence in a forward direction.

#### The header files
```
#include <list>
#incldue <forward-list>
```

#### How to initialize a list and a forward list
```
list<int> numbers1 { 1, 2, 3, 4, 5 };
forward_list<int> numbers2 { 6, 7, 8, 9 };
```

#### How to use the values of a vector to initilize a list
```
vector<int> nums { 1, 2, 3, 4, 5, 6 };
list<int> numbers3 (nums.begin(), num.end());
```

#### How to assign the values of a vector to a list
Skips the first element.
`numbers3.assign(++nums.begin(), nums.end())` 

### Member functions of a list

#### Some member functions of the list container
1. `push_front(elem)` - Adds a new element to the front of the sequence.
2. `pop_front()` - Removes the element at the front of the sequence.
3. `reverse()` - Reverses the order of the elements.
4. `sort()` - Sorts elements in ascending order.
5. `splice(i, list)` - Transfers the elements in the list before the elements pointed to by i.
6. `splice(i, list, b, e)` - Transfers the elements in the list in interval [b,e) before the element
pointed to by i.
7. `merge(list)` - Merges two sorted lists. You should sort both lists before calling this function.
8. `remove(value)` - Removes the elements that are equal to value.

#### Examples
```
list<int> nums1 { 1, 2, 3, 4, 5 };
list<int> nums2 { 5, 6, 7, 8, 9 };
list<int> nums3 { 9, 10 };

nums1.splice(nums1.end(), nums3);
// nums1 now contains 1 2 3 4 5 9 10, and nums3 is empty

nums1.splice(nums1.begin(), nums2, ++nums2.begin(), --nums2.end());
// nums1 now contains 6 7 8 1 2 3 4 5 9 10

nums1.reverse();
// nums1 now contains 10 9 5 4 3 2 1 6 7 8

nums1.sort();
// nums1 now contains 1 2 3 4 5 6 7 8 9 10

nums2.sort();
nums1.merge(nums2);
// nums1 now contains 1 2 3 4 5 6 7 8 9 10, and nums2 is empty

nums1.remove(5);
// nums1 now contains 1 2 3 4 6 7 8 9 9 10
```

How to work with queues and stacks
----------------------------------

Both adapt the deque for specialized uses.

### How to work with queues (FIFO)

#### Some member functions of the queue container adapter
1. `push(value)` - Inserts an element at the back of the sequence.
2. `pop()` - Removes the first element in the sequence.
3. `front()` - Returns a reference to the value in the first element in the sequence.
4. `back()` - Returns a reference to the value in the last element in the sequence.

#### The header file for the queue container adapter
`#include <queue>`

#### An example of working with a queue
```
queue<int> q;
q.push(1);
q.push(2);

cout << "front = " << q.front() << " and back = " << q.back() << endl;
// displays "front = 1 and back = 2"

q.pop();

cout << "front = " << q.front() << " and back = " << q.back() << endl;
// displays "front = 2 and back = 2"
```

### How to work with stacks (LIFO)

#### Some member functions of the stack contatiner adapter
1. `push(value)` - Inserts an element at the front of the sequence.
2. `pop()` - Rmoves the first element in the sequence.
3. `top()` - Returns a reference to the value in the first element in the sequence.

#### The header file for the stack adapter
`#include <stack>`

#### An example of working with a stack
```
stack<int> s;
a.push(1);
a,push(2);

cout << "top = " << s.top() << endl
// displays "top = 2"

s.pop();
cout << "top = " << s.top() << endl;
// displays "top = 1"
```

### How to work with sets
* Only stores keys, which is often a string.
* Most C++ implementations of a set use a balaced binary search tree.
* When you add or remove a key, the pointers are rearranged to maintain the sort order, but the data
  itself isn't moved.

### Some member functions shared by the associative containers
1. `find(k)` - Returns an iterator to the first element with a specified key. Or, if the specified key
               isn't found, it returns the off end iterator.
2. `count(k)` - Returns the number of elements with a specifies key.

#### The header file for the set and multiset containers
`#include <set>`

#### How to create a set with an initiliazation list
`set<string> states { "CA", "OR", "AK" };`

#### How to add keys to the set
```
states.insert("FL");
states.insert("AK"); // Not added because the key already exists
states.insert("MN");
states.insert("IA");
```

#### How to iterate the elements in a set with a range based loop
```
for (string state : states)
{
    cout << state << ' ';
}
// displays "AK CA FL IA MN OR ";
```

#### How to find and remove a value from a set
```
aute iter = states.find("FL");
if (iter == states.end())
{
    cout << "Not found\n";
}
else
{
    states.erase(iter);
}
// states now contains AK CA IA MN OR
```

How to work with maps
---------------------
Like a set except a map stores key/value pairs.

### Some member functions of the map container
1. `at(k)` - Returns the value associated with the specified key. Throws an error if not found.
2. `insert(p)` - Inserts the specified key/value pair.
3. `insert_or_assign(k, v)` - Inserts an element with the specified key and value. If the key is already
                              in the map, this function modifies the value.

### One of the operators defined by the map container
1. `[k]` - subscript - Allows read/write access to the value with the specified key. In addition,
                       it allows you to insert a key/value pair.

### The header file for the map and multimap containers
`#include <map>`

### How to create a map with an initialization list
`map<string, int> states { ("CA", 1850), ("OR" 1859), ("AK", 1959) };`

### How to display the date in a map
```C++
for (pair<string, int> p : states)
{
    cout << p.first << '(' << p.second << ")" ";
}
// displays "AK(1959) CA(1850) OR(1859) "
```

### How to insert key/value pairs and work with values by key

#### The map of strings and ints used by the examples
`map<string, int> states { ("CA", 1850), ("OR", 1859), ("AK", 1959) };`

#### How to insert, read, and write values with the subscript operator
```
states["IA"] = 1946;                                      // adds key/value
states["IA"] = 1846;                                      // modifies value
cout << "Iowa entered union in " << states["IA"] << endl; // read value
```

#### How to insert values with the insert() member function

##### Create a pair structure and then insert it
```
pair<string, int> florida ("FL", 1845);
states.insert(florida);
```

##### Create and insert a pair structure in one statement
`states.insert(pair<string, int> ("FL" 1845));`

##### Use the `make_pair()` function
`states.insert(make_pair("FL", 1845));`

#### How to insert and write values with the insert_or_assign() function
```
states.insert_or_assign("IL", 1828); // adds key/value
states.insert_or_assign("IL", 1818); // modifies value
```

#### How you can accidentally insert a key/value pair with the subscript operator
```
// states contains AK/1959 CA/1850 FL/1845 IA/1846 IL/1818 OR/1859

// attempt to retrieve the year washington entered the union
int year = states("WA");

// states now contains AK/1959 CA/1850 FL/1845 IA/1846 IL/1818 OR/1859 WA/0
```

#### How to use the find() member function to check whether a key is in the map
```C++
auto iter = states.find("WA");

if (iter == states.end())
{
    cout << "Not found\n";
}
else
{
    int year = states("WA");
}
```

How to work with nested containers
----------------------------------

### How to work with a map of vectors

#### How to work with a vector of vectors

##### How to define a vector of vectors
`vector<vector<int> > student_grades;

##### How to add vectors to a vector of vectors
```C++
student_grades.push_back( {78, 56, 90 } );
student_grades.push_back( {89, 85, 87, 83 } );
```

##### How to iterate the elements in a vector of vectors
```C++
cout << "Total number of students: " << student_grades.size() << endl;

for (auto grades: student_grades)
{
    cout << "This student has " << grades.size() << " grades: "

    for (auto grades: grades)
    {
        cout << grade << ' ';
    }

    cout << endl;
}
```

##### How to access a specific value in a vector of vectors
```C++
int grade = student_grades[1][0]; // grade is 89
```

#### How to work with a map of vectors

##### How to define a map of vectors
```C++
map<string, vector<int> > student_grades;
```

##### How to add vectors to a map of vectors
```C++
student_grades["Joe"] = { 78, 56, 90 };
student_grades["Amy"] = { 89, 85, 87, 83 };
```

##### How to iterate the elements in a map of vectors
```C++
cout << "Total number og students: " << student_grades.size() << endl;

for (auto grades: student_grades)
{
    cout << grades.first << " has " << grades.second.size() << " grades: ";

    for (auto grade: grades.second)
    {
        cout << grade << ' ';
    }

    cout << endl;
}
```

##### How to access a specific value in a map of vectors
```C++
int grade = student_grades["amy"][0];
```
