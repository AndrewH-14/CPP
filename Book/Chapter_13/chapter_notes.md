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