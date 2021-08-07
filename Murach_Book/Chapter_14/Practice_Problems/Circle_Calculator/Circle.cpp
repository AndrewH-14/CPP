#include "Circle.h"

#include <cmath>

Circle::Circle(double radius_p)
{
    set_radius(radius_p);
}

double Circle::get_diameter() const
{
    return (2 * radius);
}

double Circle::get_circumference() const
{
    return round((((2 * radius) * pi) * 10)) / 10;
}

double Circle::get_area() const
{
    return round((pi * pow(radius, 2.0) * 10)) / 10;
}