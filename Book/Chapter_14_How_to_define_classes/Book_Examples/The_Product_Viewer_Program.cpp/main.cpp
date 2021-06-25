#include <iostream>
#include <string>
#include <vector>
#include "Product.h"

using namespace std;

/**
 * Displays the products contained in the list with a corresponding number.
 * 
 * @param[in] products A vector conating the list of Product objects.
 */
void show_products(vector<Product> products)
{
    cout << "PRODUCTS\n";
    int number = 0;

    for (Product product : products)
    {
        cout << ++number << ". " << product.name << endl;
    }
    cout << endl;
}

/**
 * Displays the products name with it's correlating information.
 * 
 * @param[in] p A Product object in order to have it's information displayed.
 */
void show_product(Product p)
{
    cout << "PRODUCT DATA\n"
         << "Name:             " << p.name << endl
         << "Price:            " << p.get_price() << endl
         << "Discount percent: " << p.get_discount_percent() << endl
         << "Discount amount:  " << p.get_discount_amount() << endl
         << "Discount price:   " << p.get_discount_price() << "\n\n";
}

/**
 * Main loop for The Product Viewer Program.
 */
int main()
{
    cout << "The Product Viewer program\n\n";

    vector<Product> products;
    products.push_back(Product("Stanley 13 Ounce Wood Hammer", 12.99, 62));
    products.push_back(Product("National Hardware 3/4\" Wire Nails", 5.06, 0));
    products.push_back(Product("Economy Duct Tape, 60 yds, Silver", 7.24, 0));

    show_products(products);

    char choice = 'y';
    while (choice == 'y')
    {
        int number;
        cout << "Enter product number: ";
        cin  >> number;
        cout << endl;

        if (number > 0 && number <= products.size())
        {
            Product product = products[number - 1];
            show_product(product);
        }
        else 
        {
            cout << "There is no product with that number.\n\n";
        }

        cout << "View another product? (y/n): ";
        cin  >> choice;
        cout << endl;
    }
    cout << "Bye!\n\n";
}