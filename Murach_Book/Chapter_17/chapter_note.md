How to work with memory and pointers
====================================

An introduction to memory and pointers
--------------------------------------

**How to allocate memory by defining two variables:**
```C++
char letter; // sets aside 1 byte of memory (usually) for variable letter
int num;     // sets aside 4 bytes of memory (usually) for variable num
```

**How to allocate memory by defining a array variable:**
```C++
int nume[5]; // sets aside enough memory for variable nums
             // (usually 20 bytes, 4 bytes times 5 elements)
```

**How to use the address of operator to get the memory address of an object:**
```C++
cout << &num  << endl; // displays memory address of first of 4 bytes
cout << &nums << endl; // displays memory address of first of 20 bytes
```

**Code that defines an int variable and a pointer to that int object:**
```C++
int   num = 200;   // defines and initializes int variable named num
int * ptr = &num;  // defines and initializes pointer to int named ptr
```

**How to display the value stored by the pointer:**
```C++
cout << ptr << endl; // displays 0x28ff2c
```

**How to use the indirection operator to work with a pointer:**

**To retrieve the underlying value**
```C++
cout << *ptr << endl; // displays 200
```

**To change the underlying value**
```C++
*ptr = 1000;            // assigns new value to underlying object
cout << num << endl;    // displays 1000
```

**Code that defines a string variable and a pointer to the string object:**
```C++
string s = "hello"; // defines and initializes string variable
string * sptr = &s;  // defines and initializes pointer to string variable
```

**How to use the member access operator to call a function:**
```C++
cout << sptr->size() endl;  // displays 5
```

More skills for defining and using pointers
-------------------------------------------

**Three variables used in this figure**
```C++
int num   = 200;
int grade = 88;
double pi = 3.14;
```

**How to define multiple pointers on one line**
```C++
int *p1 = &num, *p2 = &grade; // each declaraton must have a * symbol
```

**Three ways to define a null pointer**
```C++
int* ip1 = nullptr; //C++11 and later
int* ip2 = NULL;    // prior to C++11
int* ip3 = 0;       // prior to C++11
```

**How to change the object a pointer points to**
```C++
iptr = &grade;          // iptr now points to the grade object
cout << *iptr << endl;  // displays 88
```

**An error that can occur when changing the object pointer points to**
```C++
iptr = &pi; // ERROR: cannot convert from double* to int*
```

How pointer variables compare to reference variable
---------------------------------------------------

**Define and initialize a regularm reference, and pointer variable**
```C++
double  pi   = 3.14; // regular variable
double& dref = pi;   // referenve variable
double* dptr = &pi;  // pointer variable - requires address of operator
```

**Display the underlying value of each variable**
```C++
cout <<  pi   << endl; // displays 3.14
cout <<  dref << endl; // displays 3.14
cout << *dptr << endl; // displays 3.14 - requires indirectoin operator
```

**Display the memory address of each variable**
```C++
cout << &pi   << endl; // displays memory address of pi
cout << &dref << endl; // displays memory address of pi
cout << &dptr << endl; // displays memory address of dptr
```

How to use pointers with functions
----------------------------------

**The square() function with a pointer parameter**
```C++
void square(double * val)
{
    if (val != nullptr)
    {
        *val *= *val; // perform calculation
    }
}
```

**Code that calls the function**
```C++
double d = 4.0;
square(&d);         // use address of operator to pass argument
cout << d << endl;  // displays 16
```

**The square function with a reference parameter**
```C++
void square(double& val)
{
    val *= val;  // perform calculation
}
```

**Code that calls the function**
```C++
double d = 4.0;
square(d);          // pass argument normally
cout << d << endl;  // displays 16
```

**The display_array() function with a pointer parameter for a built-in array**
```C++
void display_array(int* arr, int size)
{
    if (arr) // smae as (arr != nullptr)
    {
        for (int i = 0; i < size; ++i)
        {
            cout << arr[i] << ' '; // can subscript without dereference
        }
        cout << endl;
    }
}
```

**Code that calls the function**
```C++
const int size = 10;
int arr[size]  = { 0 };
display_array(arr, size); // pass argument normally
                          // displays 0 0 0 0 0 0 0 0 0 0
```

How to use the *this* pointer in a member function
--------------------------------------------------

**A calculator class whose member functions use the this pointer and return self-references**
```C++
class Calculator
{
    private:
        int result;
    public:
        Calculator& multiply(int a, int b)
        {
            this->result = a * b; // this-> is optional
            return *this;         // return a self-reference
        }

        Calculator& square_result()
        {
            this->result *= this->result; // this-> is optional
            return this*;                 // return a self-reference
        }

        int get_result()
        {
            return this->result; // this-> is optional
        }
}
```

**Code that uses the Calculator class**
```C++
Calculator calc;
calc.multiply(2, 5);
calc.square_result();
int result = calc.get_result();
cout << result << endl;  // displays 100
```

**Code that uses the Calculator class with function chaining**
```C++
Calculator calc;
int result = calc.multiply(2, 5).square_result().get_result();
cout << result << endl; // displays 100
```

How to use pointers to work with dynamic memory
-----------------------------------------------

### An overview of the types of storage

**Types of storage set aside for a program when it starts:**

**Code storage** - Memory allocated for the program code itself.

**Static storage** - Memory allocated for global variables.

**Automatic storage** - Memory allocated for local variables and functions. This memory uses a
                        last in first out (LIFO) *stack* to manage local variables and functions.
                        As a result. It's also called *stack storage*, *stack memory*, the
                        *call stack*, or the *stack*.

### How to allocate and deallocate free store memory

**How to use the new keyword to allocate free store memory**

**Allocate a single object of type double**
```C++
double * pi    = new double;       // returns pointer to double
double * price = new double(5.99); // include initial value
```
**Allocate a dynamic array of doubles**
```C++
double * arr    = new double[10];  // returns pointer to first element
double * prices = new double[3] { 5.99, 6.99, 7.99 }; // include initial value
```

**How to use the delete keyword to deallocate free store memory**

**Deallocate a single object**
```C++
delete pi;
```
**Deallocate an array**
```C++
delete[] arr;
```

**A function that could lead to a memory leak**
```C++
int * create_array(unsigned int size)
{
    return new int[size] { 0 }; // returns pointer to array on free store
}
```
**This code neglects to call delete[] on the pointer returned by the function**
```C++
void main(void)
{
    int * arr = create_array(20);
    // Code that works with the array
}
```

**A function that could lead to heap corruption**
```C++
void display_array(int * arr, unsigned int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << ' ';
    }
    delete[] arr; // deletes the array when done
}
```
**This code calls delete on a pointer to stack memory**
```C++
int arr[5] { 0 };    // allocates memory on stack
display_arr(arr, 5); // function calls delete on stack memory
```
**This code calls delete twice on a pointer to heap memory**
```C++
int * arr = new int[5] { 0 }; // allocate memory on heap
display_array(arr, 5);        // function calls delete on heap memory
delete[] arr;                 // statement calls delete on heap memory again
```
How to avoid memory leaks and corruption
----------------------------------------

### How to use RAII (Resource Acquisition Is Instantiation)

**RAII** - is a programming pattern that takes advantage of this process to safely allocate and
           deallocate free store memory used by an object. Basically it states that you should
           allocate free store memory in the constructor of an object and deallocate that memory in
           the destructor of that object.

**MyContainer class that uses RAII**
```C++
class MyContainer
{
    private:
        int * element;
        int   size = 10;

    public:
        // constructor
        MyContainer()
        {
            elements = new int[size]; // allocate memory
            cout << "Memory allocated for MyContainer object\n";
        }

        // destructor
        ~MyContainer()
        {
            delete[] elements; // deallocate memory
            cout << "memory deallocated for MyContainer object\n";
        }
}
```

**Code that uses the MyContainer class**
```C++
int main()
{
    cout << "main() function starting...\n";
    MyContainer mine;
    cout << "main() function ending...\n";
}
```

### How to implement the Rule of Three with RAII

The *Rule of Three* states that if you need to define your own destructor, copy constructor, or copy
assignment operator, you should define all of them as indicated below.

**destructor** - Deallocates the memory allocated for the container's data.

**copy constructor** - Copies the data in the container passed to the constructor. Copied container
                       is unchanged.

**copy assignment operator** - Copies the data in the container on the right side of the assignment
                               operator (=). Copied container is unchanged.

**The MyContainer class updated to implement the Rule of Three**
```C++
class MyContainer
{
    private:
        int * elements = nullptr;
        int   size     = 10;

    public:
        // constructor
        MyContainer()
        {
            elements = new int[size];
        }

        // destructor
        ~MyContainer()
        {
            delete[] elements;
        }

        // copy constructor
        MyContainer(const MyContainer& tocopy)
        {
            elements = new int[size];

            for (int i = 0; i < size; ++i) // deep copy
            {
                elements[i] = tocopy.elements[i];
            }
        }

        // copy assignment operator
        MyContainer& operator= (const MyContainer& tocopy)
        {
            auto temp = new int[size]; // allocate new array

            for (int i = 0; i < size; ++i) // deep copy
            {
                temp[i] = tocopy.elements[i];
            }

            delete[] elements; // delete old
            elements = temp;   // assign new
            return *this;      // return self-reference
        }
}
```

### How to implement the Rule of Five with RAII

The *Rule of Five* states that if you need to define your own destructor, copy constructor, copy
assignment operator, move constructor, or move assignment operator, your should define all of them.

The move constructor accepts an *rvalue reference* to a MyContainer object. An rvalue reference
identifies an object that can be moved. To declare a rvalue reference, you can use the
*rvalue reference declarator* (&&).

**The additional member functions required by the Rule of Five**

**move constructor** - Moves the data from the constructor passed to the constructor.
                       Moved container is empty.

**move assignment operator** - Moves the data from the container on the right side of the assignment
                               operator (=). Moved container is emptied.

**The MyContainer class updated to implement the Rule of Five**
```C++
class MyContainer
{
    private:
        int * elements = nullptr;
        int   size = 10;

    public:
        // constructor is the same as in the previous figure
        // destructor is the same as in the previous figure
        // copy constructor is the same as in the previoues figure
        // copy assignment operator is the same as in the previous figure

        // move constructor
        MyContainer(MyContainer&& tomove)
        {
            elements = tomove.elements; // assign pointer to data
            tomove.elements = nullptr;  // remove pointer to data
        }

        // move assignment operator
        MyContainer& operator= (MyContainer&& tomove)
        {
            delete[] elements;          // deallocate existing memory
            elements = tomove.elements; // assign pointer to data
            tomove.elements = nullptr;  // remove pointer to data
            return  *this;              // return self-reference
        }
}
```

How to work with smart pointers
-------------------------------

**How to include the memory header file**
```C++
#include <memory>
```

**Three smart memory pointers in the memory header (C++11 and later)**

**unique_ptr** - Only one unique_ptr object can point to allocated memory. When unique_ptr is
                 destroyed or goes out of scope, memory is deallocated.

**shared_ptr** - Muliple shared_ptr objects can point to allocated memory. Maintains a reference
                 count and deallocates memory when count is zero.

**weak_ptr**   - Created as a copy of a shared_ptr, but does not add to the reference count.

**How to use the unique_ptr to work with free store memory:**

**Code that creates a smart pointer to a built-in array**
```C++
unique_ptr<int> ptr(new int); // create smart pointer to int
*ptr = 4;                     // dereference and assign value
*ptr *= *ptr;                 // dereference and square value
cout << *ptr << endl;         // displays 16
```

**Code that createsa smart pointer to a built-in array
```C++
unique_ptr<int[]> arr(new int[10]) // create smart pointer to array

for (int i = 0; i < 10; ++i) // set values of array elements
{
    arr[i] = i;
}
```

**How to use the make_unique() function (C++14 and later)**
```C++
auto ptr = make_unique<int>();     // create smart pointer to int
auto ptr = make_unique<int[]>(10); // create smart pointer to array
```

**A create_array() function that returns a smart pointer to a built-in array**
```C++
unique_ptr<int[]> create_array(unsigned int size)
{
    auto arr = make_unique<int[]>(size);
    return arr;
}
```

**Code that uses the create_array() function**
```C++
int main()
{
    unsigned int size = 0;
    cout << "Please enter the size of the array: ";
    cin  >> size;

    auto arr = create_array(size);

    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << ' ';
    }
    // the smart pointer automaticall deallocates memory for the array
}
```

More skills for working with pointers
-------------------------------------

**How to compare pointers**
```C++
double price = 89.99, score = 89.99;
double *p1 = &price, *p2 = &price, *s = &score;

cout << (p1 == p2);  // displays 1 - pointers point to the same object
cout << (p1 == s);   // displays 0 - values match but objects are different
cout << (*p1 == *s); // displays 1 - values match
```

**How to use pointer arithmetic in an array**
```C++
int arr[] { 2, 4, 6, 8, 10 };
int * i = arr;      // i points to first element
cout << *i << endl; // displays 2

++i;                // advances 1 element to point to second element
cout << *i << endl; // displays 4

i = i + 2;          // advances 2 elements to point to fourth element
cout << *i << endl; // displays 8

i = i - 3;          // moves back 3 elements to point to first element
cout << *i << endl; // displays 2

--i;                // DANGER! you've moved outside the array bounds!
cout << *i << endl; // displays ????
```

**How to define a void pointer and point to different types**
```C++
double pi = 3.14;
int    i  = 0;

void * ptr =  &pi;    // define void pointer that points to a double
ptr = &i;             // change void pointer to point to an int
cout << *ptr << endl; // ERROR - can't dereference - data type unknown
```

**How to cast a void pointer to a pointer to a type**
```C++
int * iptr = static_cast<int*>(ptr);
cout << *iptr << endl; // SUCCESS - displays 0
```

### How to use pointers with inheritance

**The Product hierarchy**
```
Product - defines virtual get_description() function
Book    - overrides virtual get_description function to add author
Movie   - overrides virtual get_description function to add year
```

**How to use a superclass pointer to store addresses of subclass objects**
```C++
Product * p1 = new Product("Stanley 13 Ounce Wood Hammer", 12.99, 62);
Product * p2 = new Book("The Big Short", 15.95, 34, "Michael Lewis");
Product * p3 = new Movie("The Wizard of Oz", 14.99, 50, 1939);
```

**How to code a function that accepts a superclass pointer**
```C++
void show_product(const Product * p)
{
    cout << "Name:             " << p->get_description()      << endl
         << "Product:          " << p->get_price()            << endl
         << "Discount percent: " << p->get_discount_percent() << "\n\n";
}
```
**Code that call this function**
```C++
show_product(p1); // calls get_description() function of the Product class
show_product(p2); // calls get_description() function of the Book class
show_product(p3); // calls get_description() function of the Movie class
```

**How to create a vector of superclass pointers**
```C++
vector<Product*> products = vector<Product*>();
products.push_back(new Product("Stanley 13 Ounce Wood Hammer", 12.99, 62));
products.push_back(Book("The Big Short", 15.95, 34, "Michael Lewis"));
products.push_back(new Movie("The Wizard of Oz", 14.99, 50, 1939));
```

**How to code a function that accepts a vector of superclass pointers**
```C++
void show_products(const vector<Product*>& products)
{
    int number = 0;

    for (int i = 0; i < products.size(); ++i)
    {
        Product * p = products[i];
        cout << ++number << ". " << p->get_description() << endl;
    }
    cout << endl;
}
```

**Code that calls this function**
```C++
show_products(products);
```

### How complex compound types work

**How to define a pointer to a pointer**
```C++
int i     = 2000; // an int (value = 2000)
int *  p  = &i;   // a pointer to int (value = address of i)
int ** pp = &p    // a pointer to pointer to int (value = address of p)
```

**How to dereference a pointer to a pointer**
```C++
cout << *pp  << endl;  // one indirection operator - displays address of p
cout << **pp << enld;  // two indirection operators - displays 2000
```

**How to code a reference to a pointer**
```C++
int*& ref = p;       // a reference to p
cout << p   << endl; // displays the address of 1
cout << ref << endl; // also displays the address of i
```

**Examples that use the const keyword with pointers**
```C++
double price    = 5.99;  // a double
const double pi = 3.14;  // a constant double

double* const p1 = &price;    // a constant pointer to a double
const double* p2 = &pi;       // a pointer to a constant double
const double* const p3 = &pi; // a constant pointer to a constant double
```

**Examples that use compound types**
```C++
const int ci = 2000;         // a constant int
const int * p4 = &ci;        // a pointer to a constant int
const int*& r1 = p4;         // a reference to a pointer to a constant int
int* const p5 = &i;          // a constant pointer to an int
const int* const p6 = &ci;   // a constant pointer to a constant int
const int* const & r2 = p6;  // a reference to a constant pointer to a constant int
```