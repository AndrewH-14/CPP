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

### A pure virtual function in the Product.h file
```C++

```