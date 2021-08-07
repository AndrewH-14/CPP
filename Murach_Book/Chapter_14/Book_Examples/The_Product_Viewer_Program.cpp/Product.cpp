#include <string>
#include <cmath>
#include <iostream>
#include "Product.h"

using namespace std;

/**
 * Constructor function for the Product class
 * 
 * @param[in] p_name_p           Initial value for the public name variable.
 * @param[in] price_p            Initial value for the private price variable.
 * @param[in] discount_percent_p Inital value for the private discount_percent variable
 */ 
Product::Product(string p_name_p, double price_p, int discount_percent_p)
{
    name = p_name_p;
    set_price(price);
    set_discount_percent(discount_percent);
}

/**
 * Setter function for the Product classes price variable.
 * 
 * @param[in] p_price A double value representing the new price of the product.
 */
void Product::set_price(double p_price)
{
    if (p_price >= 0.0)
    {
        price = round(p_price * 100) / 100;
    }
    else
    {
        throw invalid_argument("Price can't be negative.");
    }
}

/**
 * Setter function for the Product classes discount percent variable.
 * 
 * @param[in] discount_percent An integer value representing the dicount percent for the product.
 */
void Product::set_discount_percent(int p_discount_percent)
{
    if (p_discount_percent >= 0 && p_discount_percent <= 100)
    {
        discount_percent = p_discount_percent;
    }
    else
    {
        throw invalid_argument("Invalid range for discount percent.");
    }
}

/**
 * Getter function that calculates discount amount based on the products price and discount percent
 * values.
 * 
 * @return The amount of discount that should be applied for the product.
 */
double Product::get_discount_amount()
{
    double discount_amount = price * discount_percent / 100;
    return round(discount_amount * 100) / 100;
}

/**
 *  Getter function that calculates the price of the product after the dicount has been applied.
 * 
 * @return The cost of the product after the discount has been applied.
 */
double Product::get_discount_price()
{
    double discount_price = price - get_discount_amount();
    return round(discount_price * 100) / 100;
}
