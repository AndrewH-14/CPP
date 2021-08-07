Chapter 14: How to define classes
=================================

An introduction to object-oriented programming
----------------------------------------------

When you use *object-oriented programming*, you group related variables and functions into
*data structures* called *objects*.

### General Terms

**Encapsulation** - controlling access to data members.

This allows you to hide the data members of an object from other code that uses the object, which is known as ***data hiding***.

**class** - a blueprint from which objects are created.

The process of creating an object from a class or structure is sometimes called ***instantiation***. Once you create an object, the object has an ***identity*** (a unique address), a ***state*** (the data that stores it), and ***behavior*** (the functions that it provides).

### A Movie class that provides encapsulation

#### A Movie class
```C++
class Movie
{
    private: // data members are private
        string title = "";
        int year;
    public: // member functions are public
        void   set_title(string);
        string get_title();
        void   set_year(int);
        int    get_year();
        bool   equals(const Movies&);
};

// member function definitions
void Movie::set_title(string title_param)
{
    title = title_param;
}
string_movie::get_title()
{
    return title;
}
void Movie::set_year(int year_param)
{
    if (year_param < 1888)
    {
        throw invalid_argument("Year must be 1888 or later.");
    }
    year = year_param;
}
int Movie::get_year()
{
    return year;
}
bool Movie::equals(const Movie& to_compare)
{
    return ((title == to_compare.title) && (year == to_compare.year));
}
```

#### Code that creates an object from the Movie class and uses it
```C++
Movie movie;
movie.set_title("Roundhay Garden Scene"); // set title
// movie.year = 1776;                     // illegal - no direct access
// movie.set_year(1776);                  // invalid - throws exception
movie.set_year(1888);                     // set year

cout << "MOVIE DATA\n"
     << "Title: " << movie.get_title() << endl;
     << "Year: "  << movie.get_year()  << endl;
```

### How to define private data members

#### THe syntax for defining private and public members
```C++
class ClassName
{
    [private:] // classes automatically start with a private section
        // private members go here

    public:
        // public members go here

    [private:
        // you can also code private members here]
}
```

#### A class that places all private members before public members
```C++
class Movie
{
    string title;          // private members
    int year;
public:                    // public members
    void   set_title(string);
    string get_title();
    void   set_year(int);
    int    get_year();
    bool   equals(cont Movie&);
}
```

#### A class that places all public members before private members
```C++
class Movie
{
    public: // public members
        void   set_title(string);
        string get_title();
        void   set_year(int);
        int    get_year();
        bool   equals(const Movie&);
    private: // private members
        string title;
        int    year;
}
```

### How to define getter and setter functions

**setters(mutators)** - functions that set the value of the data members.
**getters(accesors)** - functions that return the value of the data members.

#### A setter fuction
```C++
void Movie::set_title(string title_param)
{
    title = title_param;
}
```

#### Another way to code this setter function
```C++
void Movie::set_title(string title)
{
    this->title = title;
}
```

#### A setter function that validates data
```C++
void Movie::set_year(int year_param)
{
    if (year_param < 1888)
    {
        throw invalid_argument("Year must be 1888 or later.");
    }
    year = year_param;
}
```

#### A getter function that returns a string
```C++
string Movie::get_title() const
{
    return title;
}
```

#### A getter function that returns an int value
```C++
int Movie::get_year() const
{
    return year;
}
```

#### Code that calls these functions
```C++
Movie movie;
movie.set_title("Roundhay Garden Scene");
movie.set_year(1888);
string title = movie.get_title();
int year = movie.get_year();
```

### More skills for coding member functions

#### How to work with member functions

##### The declarations for three more functions for the Movie class
```C++
private:
    string to_upper(string); // helper function
public: 
    string get_title_upper() const;
    bool iequals(const Movies&);
```

##### A private function that converts a string to uppercase
```C++
string Movie::to_upper(string str)
{
    string str_upper;

    for (char c : str)
    {
        str_upper.push_back(to_upper(c));
    }
    return str_upper;
}
```

##### A public function that returns the title in uppercase
```C++
string Movie::get_title_upper() const
{
    return to_upper(title);
}
```

##### A public function that performs a case-insensitive equality comparison
```C++
bool Movie::iequals(const Movie& to_compare)
{
    return (to_upper(title) == to_upper(to_compare.title) &&
            year == to_compare.year);
}
```

##### Code that calls the public functions
```C++
Movie m1;
Movie m2;

m1.set_title("Test");
m1.set_year(2018);

m2.set_title("test");
m2.set_year(2018);

if (m1.iequals(m2)) 
{
    cout << "The test movies are equal (case-insensitive).";
}

// m1.to_upper() // illegal - can't call private member functions
cout << "The title is " << m1.get_title() << endl;
cout << "The uppercase title is " << m1.get_title_upper() << endl;
```

### How to convert between numbers ans strings

#### Three functions for converting between numbers and strings

`to_string(num)` - Converts the specified number to a string and returns the string.
`stoi(str)`      - Converts the specified string to a double value and returns that value.
                   If this function can't perform the conversion, it throws an exception.
`stod(str)`      - Converts the speceified string to a double value and returns that value. If 
                   this fucntion can't perform the conversion, it throws an exception.

#### The declarations for more functions for the Movie class
```C++
public:
    void   set_year(int year_param);
    void   set_year(string year_param);
    string to_str() const;
```

#### A set_year() function that accepts an int value
```C++
void Movie::set_year(int year_param)
{
    if (year_param < 1888)
    {
        throw invalid_argument("Year must be 1888 or later.");
    }
    year = year_param;
}
```

#### An overload of the set_year() function that accepts a string
```C++
void Movie::set_year(string year_param)
{
    int yr = stoi(year_param); // string to int
    set_year(yr);
}
```

#### A function that returns a string representation of an object
```C++
string Movie::to_str() const
{
    return title + " (" + to_string(year) + ')'; // int to string

}
```

#### Code that calls all three public functions
```C++
Movie movie;
movie.set_title("Arrival of the Train");
movie.set_year("1895");

cout << movie.to_str() << endl;
```

### How to define constructors

**constructor** - special type of member function that's automatically called when you create(construct) an object.

**default constuctor** - constuctor that has zero parameters.

#### A default constructor (zero parameters)

**The declaration**
```C++
Movie();
```
**The definiton**
```C++
Movie::Movie()
{
    title = "";
    year  = 1888;
}
```

#### Another way to code a default constructor (zero required parameters)
**The declaration**
```C++
Movie(string title = "", int year = 1888);
```
**The definition**
```C++
Movie::Movie(string title_p, int year_p)
{
    set_title(title);
    set_year(year);
}
```

#### Three ways to call the default constructor (no arguments)
```C++
Movie m1 = Movie(); // full syntax
Movie m2();         // partially abbreviated syntax
Movie m3;           // abbreviated syntax
```
#### Examples that pass arguments to a constructor
```C++
Movie m4 = Movie("Wizard of Oz");
Movie m5("Wizard of Oz");
Movie m6 = Movie("Wizard of Oz" 1939);
Movie m7("Wizard of Oz", 1939);
```

#### An example that creates an object and stores it in a vector
```C++
movies.push_back(Movie("Wizard of Oz", 1939));
```

### How to define destructors

**destructors** - a special type of member function that's automatically called when an object
                  is destroyed.

#### A destructor
**The definition**
```C++
~Movie();
```
**The definintion**
```C++
Movie::~Movie()
{
    // code that frees system resources goes here
}
```

#### An example of a class with a destructor
**The declaration**
```C++
class MovieList
{
    private:
        string filename = "movies.txt";
        fstream file;
        vector<Movie> movies;
    public:
        MovieList();
        ~MovieList();
        void add_movie(Movie);
        void delete_movie(Movie);
}
```
**The definition for the constructor**
```C++
MovieList::MovieList()
{
    file.open(filename, ios::in); // opens a systen resource
}
```
**The definition for the destructor**
```C++
MovieList::~MovieList()
{
    if (file.is_open())
    {
        file.close();
    }
}
```

### How to store a class in header and source files

#### The Header and source files for a Movie class

#### The Movie.h file
```C++
#ifndef MURACH_MOVIE_H // include guard, prevents the compiler from including the same header
#define MURACH_MOVIE_H // file twice.

#include <string>

class Movie
{
    private:
        std::string title;
        int year;
        int stars;

        std::string to_upper(std::string);
    public:
        Movie(std::string title_p = "", int year_p = 1888, int stars_p = 1);

        Movie set_title(std::string);
        std::string get_title() const;

        Movie set_year(int);
        int get_year() const;

        Movie set_stars(int);
        int get_stars() const;

        bool iequals(const Movie&)
}

#endif // MURACH_MOVIE_H
```
#### The Movie.cpp file
```C++
#include "Movie.h"
#include <string>

using std::string;
using std::invalid_argument;

// private function
string Movie::to_upper(string str)
{
    string str_upper;

    for (char c : str)
    {
        str_upper.push_back(to_upper(c));
    }
    return str_upper;
}

// public functions
Movie::Movie(string title_p, int year_p, int stars_p)
{
    set_title(title_p);
    set_year(year_p);
    set_stars(stars_p);
}

void Movie::set_title(string title_param)
{
    if (title_param.size() > 120)
    {
        throw_invalid_argument("Title must not have more than 120 chars.");
    }
    title = title_param;
}

string Movie::get_title() const
{
    return title;
}

void set_year(int year_param)
{
    if (year_param < 1888)
    {
        throw_invalid_argument("Year must be 1888 or later.");
    }
    year = year_param;
}

int Movie::get_year() const
{
    return year;
}

void Movie::set_stars(int stars_param)
{
    if (stars_param < 1 || stars_param > 5)
    {
        throw_invalid_argument("Stars must be from 1 to 5.");
    }
    stars = stars_param;
}

int Movie::get_stars() const
{
    return stars;
}

bool Movie::iequals(const Movie& to_compare)
{
    return (to_upper(title) == to_upper(to_compare.title) &&
           year == to_compare);
}
```

### When and how to use inline functions

When you code the definition of a member function into the header file, it is called an *inline function*.

#### A Movie.h file that uses inline function definitions
```C++
#ifndef MURACH_MOVIE_H
#define MURACH_MOVIE_H

#include <string>

class Movie
{
    private:
        std::string title;
        int year;
        int stars;
        std::string to_upper(std::string);
    public:
        Movie(std::string title = "", int year = 1888, int stars = 1);

        void set_title(std::string);
        std::string get_title() const { return title; } // inline function

        void set_year(int);
        int Movie::get_year() const { return year; } // inline functions

        // other function definitions
};

#endif // MURACH_MOVIE_H
```
#### Pros of inline functions
1. More concise
2. Possible improved performance due to avoiding function call overhead.

#### Cons of inline functions
1. Larger executable
2. Possible degraded performance due to larger executable size
3. Header file must be recompiled if you change any of the implementation code of the 
   inline function.

How to work with UML diagrams
-----------------------------

### An introduction to UML diagrams

It's common to use a diagram known as a *class diagram* to plan and document the data members and
functions of a class. To do that it's commone to use ***Unified Modeling Language (UML)***, a
modeling language that's the industry standard for working with all object-oriented programming
languages.

**minus sign (-)** - marks the private member's that can't be accessed by other classes.
**plus sign (+)** - marks the public members that can be accessed by other classes.

How to work with object composition
-----------------------------------

**object compostion** - to combine simple objects into more complex data structures.

### A Die class

#### The Die.h file
```C++
#ifndef HANKINS_DIE_H
#define HANKINS_DIE_H

class Die
{
    private:
        int value;

    public:
        Die();
        void roll();
        int get_value() const;
};

#endif // HANKINS_DIE_H
```

#### The Die.cpp file

```C++
#include <cstdlib>
#include <ctime>
#include "Die.h"

Die::Die()
{
    srand(time(nullptr)); // seed the rand() function
    value = 1;
}

void Die::roll()
{
    value = rand() % 6; // value is >= 0 and <= 5
    ++value;            // value is >= 1 and <= 6
}

int Die::get_value() const
{
    return value;
}
```

### A Dice class

A class composed of other class objects.

#### The Dice.h file
```C++
#ifndef HANKINS_DICE_H
#define HANKINS_DIcE_H

#include <vector>
#include "Die.h"

class Dice
{
    private:
        std::vector<Die> dice;

    public:
        Dice();
        void add_die(Die die);
        void roll_all();
        std::vector<Die> get_dice() const;
};

#endif // HANKINS_DICE_H
```

#### The Dice.cpp file
```C++
#include "Dice.h"

Dice::Dice() {}

void Dice::add_die(Die die)
{
    dice.push_back(die);
}

void Die::roll_all()
{
    for (Die die : dice)
    {
        die.roll();
    }
}

std::vector<Die> Dice::get_dice() const
{
    return dice;
}
```