#ifndef MURACH_USED_BOOK_H
#define MURACH_USED_BOOK_H

#include <string>
#include "Book.h"

using namespace std;

class UsedBook : public Book
{
    private:

    public:
        UsedBook(string name         = "",
             double price        = 0.0,
             int disc_pct        = 0,
             string author_param = "") : Book(name, price, disc_pct, author_param)
        {
            // Do nothing
        }

        string get_description() const
        {
            return name + " by " + author + " (Used)";
        }
};

#endif // MURACH_USED_BOOK_H