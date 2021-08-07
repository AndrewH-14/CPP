#ifndef MURACH_PRODUCT_H
#define MURACH_PRODUCT_H

#include <string>

using std::string;

class Product 
{
    private:
        double price;
        int discount_percent;

    public:
        string name;

        Product(string name_p = "", double price_p = 0.0, int discount_pct_p = 0);

        void set_price(double);
        double get_price() const 
        { 
            return price;
        }


        void set_discount_percent(int);
        int get_discount_percent() const 
        {
            return discount_percent;
        }

        double get_discount_amount();
        double get_discount_price();
};

#endif // MURACH_PRODUCT_H