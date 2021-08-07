#include "Product.h"

#include <string>
#include <cmath>
#include <iostream>

using std::string;
using std::invalid_argument;

Product::Product(string name_param, double price, int discount_percent)
{
    name = name_param;
    set_price(price);
    set_discount_percent(discount_percent);
}

void Product::set_price(double price_param)
{
    if (price_param >= 0.0)
    {
        price = round(price_param * 100) / 100;
    }
    else
    {
        throw invalid_argument("Price can't be negative.");
    }
}

void Product::set_discount_percent(int disc_pct)
{
    if (disc_pct >= 0 && disc_pct <= 100)
    {
        discount_percent = disc_pct;
    }
    else
    {
        throw invalid_argument("Invalid range for discount percent.");
    }
}

double Product::get_discount_amount() const
{
    double discount_amount = price * discount_percent / 100;
    return round(discount_amount * 100) / 100;
}

double Product::get_discount_price() const
{
    double discount_price = price - get_discount_amount();
    return round(discount_price * 100) / 100;
}

string Product::get_description() const
{
    return name;
}