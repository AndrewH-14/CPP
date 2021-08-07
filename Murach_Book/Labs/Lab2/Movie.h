#ifndef HANKINS_MOVIE_H
#define HANKINS_MOVIE_H

#include <string>

using namespace std;

/**
 * Defines a Movie class.
 */
class Movie
{
    private:
        // Member attributes
        string title = "";
        int year = 0;

    public:
        // Member functions
        void   set_title(string);
        string get_title() const;
        string get_title_upper() const;

        void set_year(int);
        int  get_year() const;

        bool   equals(const Movie&);
        string to_str();
};

#endif // HANKINS_MOVIE_H
