#ifndef MURACH_PRODUCT_H
#define MURACH_PRODUCT_H

#include <string>

class Product {
protected:
    std::string name;     // protected data member
private:
    double price;
    int discount_percent;
public:
    Product(std::string name = "", double price = 0.0, 
            int discount_pct = 0);

    void set_price(double);
    double get_price() const { return price; }

    void set_discount_percent(int);
    int get_discount_percent() const { return discount_percent; }

    double get_discount_amount() const;
    double get_discount_price() const;

    // virtual function - necessary for polymorphism
    virtual std::string get_description() const;
};
#endif // MURACH_PRODUCT_H