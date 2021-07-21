#include "Temp.h"

#include <cmath>

Temp::Temp()
{
    fahrenheit = 32;
    celsius = 0;
}

int Temp::get_fahrenheit() const
{
    return round(fahrenheit * 10) / 10;
}

int Temp::get_celcius() const
{
    return round(celsius * 10) / 10;
}

void Temp::set_fahrenheit(double const fahrenheit_p)
{
    fahrenheit = fahrenheit_p;

    celsius = (fahrenheit_p - 32.0) * 5.0 / 9.0;
}

void Temp::set_celcius(double const celsius_p)
{
    celsius = celsius_p;

    fahrenheit = celsius_p * 9.0 / 5.0 + 32.0;
}