How to work with exceptions
===========================

How to get started with exceptions
----------------------------------

### A function that doesn't use exceptions

**A function that returns -1.0 to signal that an error has occured**
```C++
double calculate_mpg(double miles, double gallons)
{
    if (miles <= 0.0)
    {
        return -1.0;
    }
    if (gallons <= 0.0)
    {
        return -1.0;
    }

    double mpg = miles / gallons;

    mpg = round(mpg * 10) / 10; // round to 1 decimal place

    return mpg;
}
```

**Calling code that displays an invalid result**
```C++
double mpg = calculate_mpg(100, 0);
cout << "Miles per gallon: " << mpg << "\n\n";
```


**Calling code that uses the return value to check for an error**
```C++
double mpg = calculate_mpg(100, 0);
if (mpg == -1.0)
{
    cout << "Error! Unable to calculate miles per gallon\n\n";
}
else
{
    cout << "Miles per gallon: " << mpg << "\n\n";
}
```

### How to throw an exception

**exception** - an object that represents an error that has occured and contains information about
                the error.

**The hierarchy of predefined exception classes**

exception
    logic_error
        invalid_argument
        out_of_range
    runtime_error
        range_error
        overflow_error
        underflow_error

**The syntax for creating an exception object**
```C++
class_name([error_message])
```

**The syntax of the throw statement**
```C++
throw exception_object;
```

**A function that throws a predefined exception**
```C++
double calculate_mpg(double miles, double gallons)
{
    if (miles <= 0.0)
    {
        throw invalid_argument("Error! Miles must be > 0.");
    }
    if (gallons <= 0.0)
    {
        throw invalid_argument("Error! Gallons must be > 0.");
    }

    double mpg = miles / gallons;

    mpg = round(mpg * 10) / 10; // round to 1 decimal place

    return mpg;
}
```

**Calling code that passes an invalid argument**
```C++
double mpg = calculate_mpg(100, 0); // causes the program to crash!
cout << "Miles per gallon: " << mpg << "\n\n";
```

### A program that catches exceptions

**The code**
```C++
#include <iostream>
#include <cmath>

using namespace std;

void display_title()
{
    cout << "Miles Per Gallon Calculator\n\n";
}

double calculate_mpg(double miles, double gallons)
{
    if (miles <= 0.0)
    {
        throw invalid_argument("Error! Miles must be > 0.");
    }
    if (gallons <= 0.0)
    {
        throw invalid_argument("Error! Gallons must be > 0.");
    }

    double mpg = miles / gallons;

    mpg = round(mpg * 10) / 10;

    return mpg;
}

int main()
{
    display_title()

    double miles;
    cout << "Enter miles driven:        "
    cin  >> miles;

    double gallons;
    cout << "Enter gallons of gas used: "
    cin  >> gallons;

    double mpg;

    try
    {
        mpg = calculate_mpg(miles, gallons);

        cout << "Miles per gallon:          "
    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << "\n\n";
    }

    cout << "Bye!\n\n";

    return 0;
}
```

### A program that prevents exceptions from being thrown

**The code**
```C++
#include <iostream>
#include <cmath>

#include "console.h"

void display_title()
{
    cout << "Miles Per Gallon Calculator\n\n";
}

double calculate_mpg(double miles, double gallons)
{
    if (0.0 >= miles)
    {
        throw invalid_argument("Error! Miles must be > 0.");
    }
    if (0.0 >= gallons)
    {
        throw invalid_argument("Error! Gallons must be > 0.");
    }

    double mpg = miles / gallons;

    mpg = round(mpg * 10) / 10; // round to one decimal place

    return mpg;
}

int main()
{
    display_title();

    // use console namespace to get valid values
    double miles   = console::get_double("Enter miles driven:        ", 0.0);

    double gallons = console::get_double("Enter gallons of gas used: ", 0.0);

    // calculate and display mpg
    double mpg = calculate_mpg(miles, gallons);
    cout << "Miles per gallon:          " << mpg << "\n\n";

    // exit program
    cout << "Bye!\n\n";

    return 0;
}
```

More skills for working with exceptions
---------------------------------------

### How to catch multiple exceptions

**The syntax for a try statement with multiple catch clauses**
```C++
try
{
    // Statements that might throw an exception
}
catch (most_specific_exception_object_name)
{
    // Statements that handle the most specific exception type
}
[catch (less_specific_exception_object_name)
{
    // Statements that handle a less specific exception type
}]...
```

**Code that throws different types of predefined exception objects**
```C++
throw invalid_argument("Miles must be > 0.");
throw runtime_error();
throw exception();
```

**Code that handles multiple predefined exceptions**
```C++
try
{
    // Statements that might throw predefined exceptions
}
catch (const invalid_argument& e)
{
    cout << "Invalid argument!\n\n";
}
catch (const runtume_error& e)
{
    cout << "An unexpected runtime error occured!\n\n";
}
catch (const exception& e)
{
    cout << "An unexpected exception occured.\n\n";
}
```

### How to rethrow an exception

**The syntax for rethrowing an exception**
```C++
catch (exception_type_object_name)
{
    // code that performs some processing on the exception
    throw; // rethrow the exception
}
```

**A function that throws an exception**
```C++
void load_temps(vector<double>& low_temps, vector<double>& high_temps)
{
    double low, high;

    ifstream input_file(filename);

    if (input_file)
    {
        while (input_file >> low >> high)
        {
            low_temps.push_back(low);
            high_temps.push_back(high);
        }
        input_file.close();
    }
    else
    {
        throw runtime_error("Error! Unable to open file: " + filename);
    }
}
```

**A function that rethrows an exception**
```C++
void load_temps_with_check(vector<double>& low_temps, vector<double>& high_temps)
{
    try
    {
        load_temps(low_temps, high_temps);

        cout << "Temperatures have been loaded.\n\n";
    }
    catch (const runtime_error& e)
    {
        cout << e.what() << endl;
        cout << "Unable to load temperatures from file.\n";

        char choice;
        cout << "Would you like to create a new file? (y/n): ";
        cin  >> choice;
        cout << endl;

        if (choice == 'y')
        {
            cout << "OK. You can add temperatures now.\n";
        }
        else
        {
            cout << "Please make sure the file exists and try again.\n"
                 << "You may need to specify a full path to file.\n";

            throw;
        }
    }
}
```

How to work with custom exceptions
----------------------------------

**Code that throws a string object**
```C++
throw string("Error! Gallons must be > 0.");
```

**Code that defines a custom exception object**
```C++
struct NegativeGallons
{
    string message;
    double gallons;
};
```

**Code that creates a custom exception object and throws it**
```C++
if (gallons < 0)
{
    NegativeGallons error;
    error.message = "Error! Gallons must be > 0.";
    error.gallons = gallons;
    throw error;
}
```

**The syntax for a catch clause that catches all exceptions**
```C++
catch(...)
{
    // statements that handle all exceptions (predefined and custom)
}
```

**Code that handles multiple custom exception**
```C++
try
{
    // statements that might throw custom exceptions
}
catch (const strings& message)
{
    cout << message << "\n\n";
}
catch (const NegativeGallons& e)
{
    cout << e.message << "\n\n"
         << "You entered: " << e.gallons << "\n\n";
}
catch (...)
{
    cout << "An unexpected exception occurred!\n\n";
    throw;
}
```