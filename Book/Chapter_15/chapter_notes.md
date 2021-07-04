Chapter 15: How to work with inheritance
========================================

How to get started with inheritance
-----------------------------------

***Inheritance*** - allows your to create a new class that's based on an existing class.

### How inheritance works

With inheritance, a subclass inherits the public data members and member functions of a superclass.
When you create an object from the subclass, that object can use these data members and member functions.

It can change the data members and member functions of the superclass work by *overriding* them.

***superclass*** - refers to a class that another class inherits.
***subclass***   - refers to a class that inherits another class.

### How to define a superclass

**private**   - Availible only to the current class.
**protected** - Availible to the current class and its subclasses.
**public**    - Availible to the current class, its subclasses, and all other classes.

#### The Product.h file for the Product superclass
```C++
#ifndef HANKINS_PRODUCT_H
#define HANKINS_PRODUCT_H

#include <string>

using namespace std;

class Product
{
    protected:
        string name; // protected data member
    private:
        double price;
        int discount_percent;
    public:
        Product(string name = "", double price = 0.0, int discount_pct = 0);

        void set_price(double);
        double get_price() const { return price; }

        void set_dicount_pct(int);
        int  get_dicount_pct() const { return dicount_pct; }

        double get_dicount_amount() const;
        double get_discount_price() const;

        // virtual function - necessary for polymorphism
        // identifies this function as a function that subclasses can override
        virtual string get_description() const;
}
```

#### The get_description function in the Product.cpp file
```C++
string Product::get_description() const
{
    return name;
}
```

### How to define a subclass

#### The syntax for working with subclasses

##### To define a subclass
```C++
class SubclassName : public|protected|private SuperclassName {}
```

##### To define a subclass constructor that calls a superclass constructor
```C++
SubclassName([parameterList]) : SuperclassName(argumentList) {}
```

##### To call a superclass member function
```C++
SuperclassName::function_name(argumentList);
```

#### The Book.h file for the Book subclass
```C++
#ifndef HANKINS_BOOK_H
#define HANKINS_BOOK_H

#include <string>
#include "Product.h"

using namespace std;

class Book : public Product
{
    private:
        string author;
    public:
        Book(string name = "", double price = 0.0, int disc_pct = 0, string author_param = "") :
             Product(name, price, disc_pct) { author = author_param };
        void set_author(string author_param)
        {
            author = author_param;
        }
        string get_author() const { return author; }
        string get_description() const { return name + " by" + author; }

}

#endif // HANKINS_BOOK_H
```

#### Another way to code the get_description() function
```C++
string get_description() const { return Product::get_description() + " by " + author; }
```

### How to define another subclass

#### The Movie.h file for the Movie subclass
```C++
#ifndef HANKINS_MOVIE_H
#define HANKINS_MOVIE_H

#include <string>
#include "Product.h"

using namespace std;

class Movie : public Product
{
    private:
        int year;
    public:
        Movie(string name = "", double price = 0.0, int disc_pct = 0,
              int year_param = 1888) : Product(name, price, disc_pct)
        {
            year = year_param;
        }

        void set_year(int year_param) { year = year_param; }

        int get_year() const { return year; }

        string get_description() const { return name + " (" + to_string(year) + ')'; }
}

#endif // HANKINS_MOVIE_H

```

**NOTE:** No implementation files were necessary since the subclasses were implemented in their
          header files.


### How polymorphism works

***Polymorphism*** - lets you treat objects of different types as if they were the same type by
referring to a superclass that's common to the objects.

The key to polymorphism is that C++ decides which member function to call at runtime. This is known
as *dynamic building* or *late binding*, and it's made possible by the virtual keyword that's coded
in the superclass.

#### Three definitions of the get_description() fucntion

##### In the Product superclass
```C++
string Product::get_description() const
{
    return name;
}
```

##### In the Book subclass
```C++
string get_description() const
{
    return name + " by " + author;
}
```

##### In the Movie subclass
```C++
string get_description() const
{
    return name + " )" + std::to_string(year) + ')';
}
```

#### A function that calls the virtual function
```C++
void show_product(const Product& p)
{
    cout << "Description:    " << p.get_description()    << '\n';
    cout << "Discount Price: " << p.get_discount_price() << '\n\n';
}
```

#### Code that passes three different object types to the function
```C++
int main()
{
    Product product("Stanley 13 Ounce Wood Hammer", 12.99, 62);
    Book book("The Big Short", 15.95, 34, "Michael Lewis");
    Movie movie("The Wizard of Oz", 14.99, 50, 1939);

    show_product(product);
    show_product(book);
    show_product(movie);
}
```

More skills for working with inheritance
----------------------------------------

### How to define an abstract class

***abstract class*** - a class that can't be instantiated. In other words, you can't create an object
                       directly from an abstact class. Instead, you can code a class that inherits
                       an abstact class, and you can create an object from that class.

To make a class abstract, you declare one of its functions as a ***pure virtual function*** by coding
an [=] and a zero at the end of the function declarationand by not including a function definition.

#### A pure virtual function in the Product.h file
```C++
class Product
{
    protected:
        string name; // protected data member

    private:
        double price;
        int double_discount;

    public:
        // other public functions and constructors

        // pure virtual function
        virtual string get_description() const = 0;
}
```

#### Two subclasses that override the pure virtual function

**In the Book Subclass**
```C++
string get_description() const
{
    return name + " by " + author;
}
```

**In the Movie Subclass**
```C++
string get_description() const
{
    return name + " (" + to_string(year) + ')';
}
```

#### Code that attempts to create Product, Book, and Movie objects
```C++
// Compile-time error! Cannot instantiate abstract Product class
Product p1("Stanley 13 Ounce Wood Hammer", 12.99, 62);

// Success! Can instantiate Book and Movie classes
Book p2("The Big Short", 15.95, 34, "Michael Lewis");
Movie p3("The Wizard of Oz", 14.99, 50, 1939);
```

### How to control overriding

This involves using the `override` and `final` keywords to help control overriding. Both of these
keywords were introduces with C++11. Therefore, they don't work with older compilers.

**override** - use to explicitly identify a function as function that overrides a virtual function.

**final** - used to prevent subclasses from overriding an inherited virtual function.

#### Two functions that explicitly override another function
**In the Book Subclass**
```C++
string get_description() const override
{
    return name + " by " + author;
}
```

**In the Movie Subclass**
```C++
string get_description() const override
{
    return name + " (" + to_string(year) + ')';
}
```

#### A function that can't be overridden
**In the Book Subclass**
```C++
string get_description() const final
{
    return name + " by " + author;
}
```

**In the Movie Subclass**
```C++
string get_description() const final
{
    return name + " (" + to_string(year) + ')';
}
```

#### A function that explicitly overrides and can't be overridden
**In the Book Subclass**
```C++
string get_description() const override final
{
    return name + " by " + author;
}
```

How to work with multiple inheritance
-------------------------------------

**Multiple inheritance** - allows a class to inherit multiple classes.

### The Day Structure

```C++
#ifndef MURACH_DAY_H
#define MURACH_DAY_H

struct Day
{
    double low_temp;
    double high_temp;
};

#endif // MURACH_DAY_H
```

### The DayReader superclass

**The Dayreader.h file**
```C++
#ifndef MURACH_DAYREADER_H
#define MURACH_DAYREADER_H

#include <string>
#include <vector>
#include "Day.h"

using namespace std;

class DayReader
{
    private:
        string filename;
    public:
        DayReader(string filename = "");
        vector<Day> load_temp;
};

#endif // MURACH_DAYREADER_H
```

**The DayReader.cpp file**
```C++
#include <fstream>
#include <vector>
#include "DayReader.h"
#include "DayIOError.h"

using namespace std;

DayReader::DayReader(string filename_param)
{
    filename = filename_param;
}

vector<Day> DayReader::load_temps()
{
    vector<Day> days;
    Day day;

    ifstream input_file(filename);

    if (input_file)
    {
        while (input_file >> day.low_temp >> day.high_temp)
        {
            days.push_back(day);
        }

        input_file.close();
        return days;
    }
    else
    {
        throw DayIOError("Unable to open file: " + filename);
    }
}
```

### The DayWriter superclass

**The DayWriter.h file**
```C++
#ifndef MURACH_DAYWRITER_H
#define MURACH_DAYWRITER_H

#include <string>
#include <vector>
#include "Day.h"

using namespace std;

class DayWriter
{
    private:
        string filename;
    public:
        DayWriter(string filename = "");
        void save_temps(const vector<Day>& temps);
};

#endif // MURACH_DAYWRITER_H
```

**The Daywriter.cpp file**
```C++
#include <fstream>
#include <vector>
#include "DayWriter.h"

using namespace std;

DayWriter::DayWriter(string filename_param)
{
    filename = filename_param;
}

void DayWriter::save_temps(const vector<Day>& days)
{
    ofstream output_file(filename);

    for (Day day : days)
    {
        output_file << day.low_temp << '\t' << day.high_temp << '\n'
    }

    output_file.close();
}
```

### The DayIO subclass

**The DayIO.h file**
```C++
#ifndef MURACH_DAYIO_H
#define MURACH_DAYIO_H

#include <string>
#include "DayReader.h"
#include "DayWriter.h"

class DayIO : public DayReader, public DayWriter
{
    public:
        DayIO(string filename = "");
};

#endif // MURACH_DAYIO_H
```

**The DayIO.cpp file**
```C++
#include <string>
#include "DayIO.h"

DayIO::DayIO(string filename) : DayReader(filename), DayWriter(filename)
{

}
```

### Code that uses the DayIO subclass
**Code that creates a DayIO object**
```C++
DayIO dayIO("temps.txt");
```

**Code that uses the DayIO object to get a vector of Day objects**
```C++
vector<Day> days = dayIO.load_temps();
```

**Code that uses the DayIO object to save a vector of Day objects**
```C++
dayIO.save_temps(days);
```

When to use inheritance
-----------------------

### How to use inheritance with custom expectations

#### The hierarchy for some common exceptions
```
exception
    logic_error
        invalid_argument
        out_of_range
    runtime_error
        range_error
        overflow_error
        underflow_error
```

#### A DayIOError.h file that defines a class for a custum exception
```C++
#ifndef MURACH_DAYIOERROR_H
#define MURACH_DAYIOERROR_H

#include <iostrean>
#include <string>

using namespace std;

class DayIOERROR : public runtime_error
{
    public:
        DayIOError(string message = "") : runtime_error(message) {};
}

#endif // MURACH_DAYIOERROR_H
```

#### Code that throws the custom exception
```C++
vector<Day> DayReader::load_temps()
{
    vector<Day> days;
    Day day;

    ifstream input_file(filename);

    if (input_file)
    {
        // code that reads data from the file goes here
        return days;
    }
    else
    {
        throw DayIOError("Unable to open file: " + filename);
    }
}
```

#### Code that catches a custom exception
```C++
vector<Day> days;

try
{
    days = dayIO.load_temps();
}
catch (const DayIOError& e)
{
    cout << e.what() << "\n"
         << "Exiting program. Bye!\n\n";
    return 0;
}
```

### Guidelines for using inheritance

It makes sense to use inheritance when...
* One object is a type of another object.
* Both classes are part of the same logical domain.
* The subclass primarily adds features to the superclass.

#### A Dice class that inherits the vector class (not recommended)

**The Dice.h file**
```C++
#include <vector>
#include <Die.h>

using namespace std;

class Dice : public vector<Die>
{
    public:
        Dice() : vector<Die> () {};
        void roll_all();
};
```
**The Dice.cpp file**
```C++
#include "Dice.h"

void Dice::roll_all()
{
    for (int i = 0; i < size(); ++i) // calls vector size() function
    {
        Die& die = at(i); // calls vector at() function
        die.roll();
    }
}
```

#### Code that uses this Dice class
```C++
Dice dice = Dice();
dice.push_back(Die());            // function from vector class
dice.push_back(Die());            // function from vector class
dice.roll_all();
Die die = dice[0];                // operator from vector class
dice.insert(dice.begin(), Die()); // function from vector class
dice.pop_back();
cout << "Die value: "  << die.get_value() << endl;
cout << "Dice count: " << dice.size()     << endl;
```

#### A few problems with this approach
* The Dice object is not a type of vector object.
* Both classes are not part of the same logical domain.
* The interface is too complex.
* It violates encapsulation.
