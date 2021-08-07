#ifndef MURACH_BOOK_H
#define MURACH_BOOK_H

#include <string>
#include "Product.h"

class Book : public Product
{
    private:
        std::string author;
    public:
        Book(std::string name = "", double price = 0.0, int disc_pct = 0,
             std::string author_param = "") : Product(name, price, disc_pct)
        {
            author = author_param;
        }

        void set_author(std::string author_param)
        {
            author = author_param;
        }
        std::string get_author() const
        {
            return author;
        }

        std::string get_description() const
        {
            return name + " by " + author;
        }
};
#endif // MURACH_BOOK_H