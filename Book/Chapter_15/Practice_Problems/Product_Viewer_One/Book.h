#ifndef MURACH_BOOK_H
#define MURACH_BOOK_H

#include <string>
#include "Media.h"

using namespace std;

class Book : public Media
{
    private:
        string author;

    public:
        Book(string name  = "",
             double price  = 0.0,
             int disc_pct  = 0,
             string author_param = "",
             string format = "") : Media(name, price, disc_pct, format)
        {
            author = author_param;
        }

        void set_author(string author_param)
        {
            author = author_param;
        }

        string get_author() const
        {
            return author;
        }

        string get_description() const
        {
            return name + " by " + author + " - " + format;
        }
};

#endif // MURACH_BOOK_H
