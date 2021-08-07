#ifndef MURACH_MOVIE_H
#define MURACH_MOVIE_H

#include <string>
#include "Product.h"

class Movie : public Product
{
    private:
        int year;

    public:
        Movie(std::string name = "",
              double price     = 0.0,
              int disc_pct     = 0,
              int year_param   = 1888) : Product(name, price, disc_pct)
        {
            year = year_param;
        }

        void set_year(int year_param)
        {
            year = year_param;
        }
        int get_year() const { return year; }

        std::string get_description() const override final
        {
            return name + " (" + std::to_string(year) + ')';
        }
};

#endif // MURACH_MOVIE_H
