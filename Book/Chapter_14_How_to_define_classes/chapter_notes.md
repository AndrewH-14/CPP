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