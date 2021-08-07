More skill for object-oriented programming
==========================================

How to work with static members
-------------------------------

***Static data members*** and ***static member functions*** belong to the class itself, not the
object created from the class. As a result, they're sometimes called ***class data members*** or
***class member functions.***

### How to code static data members and functions

**The Product.h file**
```C++
#ifndef MURACH_PRODUCT_H
#define MURACH_PRODUCT_H

#include <string.h>

using namespace std;

class Product
{
    private:
        double price;
        int discount_percent;
        static int object_count; // static data member

    public:
        Product(string name = "",
                double price = 0.0,
                int    discount_percent = 0);

        string name;

        void   set_price(double);
        double get_price() const { return price; }
        void   set_discount_percent(int);
        int    get_discount_percent() const { return discount_percent; }
        double get_discount_amount() const;
        double get_discount_price() const;

        // static function
        static int get_object_count()
        {
            return object_count;
        }
}

#endif // MURACH_PRODUCT_H
```

**Code in the Product.cpp file that works with the static data member**
```C++
int Product::object_count = 0; // initialize static data member

Product::Product(string name_param, double price_param, int discount_pct_param)
{
    name = name_param;
    set_price(price);
    set_discount_percent(discount_pct);
    ++object_count; // increment static data function
}
```

### How to access static data members and function

**How to access a static data member from a class:**

**Syntax**
```C++
ClassName::data_member_name
```
**Example**
```C++
int product_count = Product::object_count; // if object_count is public
```

**How to access a static data member from an object:**

**Syntax**
```C++
object_name.data_member_name
```
**Example**
```C++
Product p;
int product_count = p.object_count; // if object_count is public
```

**How to call a static member function from a class:**

**Syntax**
```C++
ClassName::function_name([argument_list])
```
**Example**
```C++
int product_count = Product::get_object_count();
```

**How to call a static member function from an object:**

**Syntax**
```C++
object_name.function_name([argument_list])
```
**Example**
```C++
Product p;
int product_count = p.get_object_count();
```

### The Console class

**The Console.h file**
```C++
#ifndef MURACH_CONSOLE_H
#define MURACH_CONSOLE_H

#include <string>
#include <limits>

class Console
{
    public:
        Console() {}; // define default constructor

        // declare static functions
        static double get_double(string prompt,
                                 double min = numeric_limits<double>::min(),
                                 double max = numeric_limits<double>::max());

        static double get_int(string prompt,
                              int min = numeric_limits<int>::min(),
                              int max = numeric_limits<int>::max());

        static char get_char(string prompt, bool add_blank_line = true);
};

#endif
```

**The Console.cpp file**
```C++
#include <iostream>
#include <string>
#include <limits>

#include "console.h"

using namespace std;

// declare helper functions
void discard_remaining_chars();
void handle_invalid_number();
bool check_range(double num, double min, double max);

// define public functions
double Console::get_double(string prompt, double min, double max)
{
    // same as code from console namespace in chapter 7
}

int Console::get_int(string prompt, int min, int max)
{
   // same as code from console namespace in chapter 7
}

char Console::get_char(string prompt, bool add_blank_line)
{
    // same as code from console namespace in chapter 7
}

// define private functions
// same as code from console namespace in chapter 7
```

### Code that uses the Console class

**Code that calls static functions directly from the Console class**
```C++
double mi   = Console::get_double("Monthly Investment:    ", 0, 10000);
int years   = Console::get_int("Years:                ", 0, 100);
char choice = Console::get_char("Continue? (y/n): ");
```

**Code that calls static functions from a Console object**
```C++
Console c;
double mi   = c.get_double("Monthly Investment:    ", 0, 10000);
int years   = c.get_int("Years:                ", 0, 100);
char choice = c.get_char("Continue? (y/n): ");
```

How to work with a friend function
----------------------------------

When you want to allow a function outside of a class to access private data members of
a class, you can use a friend function that.

**Note:** Using a friend function breaks encapsulation. In some cases though, this may be the
best way to accomplish a task.

### The FuelTank class

**A FuelTank class:**

**The FuelTank.h file**
```C++
#ifndef MURACH_FUEL_TANK_H
#define MURACH_FUEL_TANK_H

#include <iostrean>

class FuelTank
{
    private:
        double gallons;
    public:
        FuelTank(double gallons_param = 0.0) { gallons = gallons_param; }

        void set_gallons(double gallons_param) { gallons = gallons_param; }

        double get_gallons() const { return gallons; }
        double get_liters()  const;
}

#endif // MURACH_FUEL_TANK_H
```

**The FuelTank.cpp file**
```C++
#include <iostream>
#include "FuelTank.h"

using namespace std;

double FuelTank::get_liters() const
{
    double liters = gallons * 3.7854;

    return liters;
}
```

**Code that uses the FuelTank class**
```C++
FuelTank tank1(100);

cout << "TANK 1" << endl
     << "Gallons: " << tank1.get_gallons() << endl
     << "Liters:  " << tank1.get_liters()  << endl << endl;
```

### A friend function that works with two classes

**The header file for a FuelCan class that declares a friend function**
```C++
#ifndef MURACH_FUEL_CAN_H
#define MURACH_FUEL_CAN_H

class FuelTank; // forward declaration of a class

class FuelTank
{
    private:
        double gallons = 0;
    public:
        FuelCan(double gallons_param = 0) { gallons = gallons_param; }
        friend void pour(FuelTank& tank, FuelCan& can);
}

#endif // MURACH_FUEL_CAN_H
```

**The header file for a FuelTank class that declares a friend function**
```C++
#ifndef MURACH_FUEL_TANK_H
#define MURACH_FUEL_TANK_H

#include <iostrean>

class FuelTank
{
    private:
        double gallons;
    public:
        FuelTank(double gallons_param = 0.0) { gallons = gallons_param; }

        void set_gallons(double gallons_param) { gallons = gallons_param; }

        double get_gallons() const { return gallons; }
        double get_liters()  const;

        friend void pour(FuelTank& tank, FuelCan& can);
}

#endif // MURACH_FUEL_TANK_H
```

**The implementation for the friend function**
```C++
#include "FuelCan.h"
#include "FuelTank.h"

void pour(FuelTank& tank, FuelCan& can)
{
    tank.gallons += can.gallons; // access private data members
    can.gallons = 0;             // access private data member
}
```

**Code that uses the friend function**
```C++
FuelCan can(2);   // can has 2 gallons
FuelTank(500);    // tank has 500 gallons
pour(tank, can);  // tank has 502 gallons, can has 0 gallons
```

How to overload operators
-------------------------

### How to overload arithmetic binary operators

***operator function*** - defines the behavior of an operator for an object.

**The addition operator for the FuelTank class**

**The declaration in the FuelTank.h file**
```C++
FuelTank operator+ (const FuelTank& right);
```

**The same declaration but with a space after the operator keyword**
```C++
FuelTank operator + (const FuelTank& right);
```

**The definition in the FuelTank.cpp file**
```C++
FuelTank FuelTank::operator+ (const FuelTank& right)
{
    FuelTank t;
    t.set_gallons(gallons + right.gallons);
    return t;
}
```

**Code that uses the addition operator**
```C++
FuelTank tank1(100);
FuelTank tank2(200);

FuelTank tank3 = tank2 + tank1; // tank3 has 300 gallons
```

**Another way to code the third statement**
```C++
FuelTank tank3 = tank2.operator+(tank1);
```

**The subtraction operator for the FuelTank class**

**The declaration in the FuelTank.h file**
```C++
FuelTank operator- (const FuelTank& right);
```

**The definiton in the FuelTank.cpp file**
```C++
FuelTank FuelTank::operator- (const FuelTank& right)
{
    FuelTank t;
    t.set_gallons(gallons - right.gallons);

    return t;
}
```

**Code that uses the subtraction operator**
```C++
FuelTank tank1(100);
FuelTank tank2(200);
FuelTank tank3 = tank2 - tank1; // tank3 has 100 gallons
```

**Another way to code the third statement**
```C++
FuelTank tank3 = tank2.operator-(tank1); // tank3 has 100 gallons
```

### How to overload arithmetic unary operators

**The prefix increment operator for the FuelTank class**

**The declaration in the FuelTank.h file**
```C++
FuelTank& operator++ ();
```

**The definition in the FuelTank.cpp file**
```C++
FuelTank& FuelTank::operator++ ()
{
    ++gallons;      // increment data member
    return *this;   // return current object
}
```

**Code that uses the prefix increment operator**
```C++
FuelTank tank1(100);
cout << ++tank1.get_gallons() << endl; // displays 101
```

**The postfix increment operator for the FuelTank class**

**The declaration in the FuelTank.h file**
```C++
FuelTank operator++ (int unused_param);
```

**The definition in the FuelTank.cpp file**
```C++
FuelTank FuelTank::operator++ (int unused_param)
{
    FuelTank temp = *this; // make copy of current object
    ++gallons;             // increment the current object
    return temp;           // return the pre-increment copy
}
```

**Code that uses the postfix increment operator**
```C++
FuelTank tank1(100);
cout << tank1++.get_gallons() << endl; // displays 100
cout << tank1.get_gallons()   << endl; // displays 101
```

### How to overload relational operators

**The less than operator for the FuelTank class:**

**The declaration for in the FuelTank.h file**
```C++
bool operator< (const FuelTank& right);
```
**The definition in the FuelTank.cpp file**
```C++
bool FuelTank::operator< (const FuelTank& right)
{
    if (gallons < right.gallons)
    {
        return true;
    }
    else
    {
        return false;
    }
}
```
**A more concise definition for this operator**
```C++
bool FuelTank::operator< (const FuelTank& right)
{
    return (gallons < right.gallons);
}
```

**The greater than operator for the FuelTank class:**

**The declaration in the FuelTank.h file**
```C++
bool operator> (const FuelTank& right);
```
**The definition in the FuelTank.cpp file**
```C++
bool FuelTank::operator> (const FuelTank& right)
{
    return (gallons > right.gallons);
}
```

**The equality operator for the FuelTank class:**

**The declaration in the FuelTank.h file**
```C++
bool operator== (const FuelTank& right);
```
**The definition in the FuelTank.cpp file**
```C++
bool FuelTank::operator== (const FuelTank& right)
{
    return (gallons = right.gallons);
}
```

**Code that uses the relational operators**
```C++
if (tank1 < tank2)
{
    cout << "Tank 1 has less fuel than tank 2.\n\n";
}
else if (tank1 > tank2)
{
    cout << "Tank 1 has more fuel than tank 2.\n\n";
}
else if (tank1 == tank2)
{
    cout << "Tank 1 has the same amount fuel as tank 2.\n\n";
}
```

How to overload the insertion and extraction operators
------------------------------------------------------

**The insertion opertor for the FuelTank class:**

**The declaration in the FuelTank.h file**
```C++
friend std::ostream& operator<< (std::ostream&, const FuelTank&);
```
**The definition in the FuelTank.cpp file**
```C++
ostream& operator<< (ostream& out, const FuelTank& tank)
{
    out << "  Gallons: " << tank.gallons      << endl
        << "  Liters:  " << tank.get_liters() << endl
        << endl;

    return out;
}
```

**The extraction operator for the FuelTank class:**

**The declaration in the FuelTank.h file**
```C++
friend std::istream& opertor>> (std::stream&, FuelTank&);
```
**The definition in the Fueltank.cpp file**
```C++
istream& operator>> (istream& in, FuelTank &tank)
{
    cout << "Enter gallons: ";
    in   >> tank.gallons;
    return in;
}
```

**Code that uses the insertion and extraction operators**
```C++
FuelTank tank4, tank5;

cin >> tank4 >> tank5; // chains 2 extraction operators together

cout << "TANK 4\n" << tank4
     << "TANK 5\n" << tank5; // chains 4 insertion operators together
```