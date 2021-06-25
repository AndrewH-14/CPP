#ifndef MURACH_MOVIE_H
#define MURACH_MOVIE_H

#include <string>

class Movie {
private:
    std::string title;
    int year;
    int stars;

    std::string to_upper(std::string);
public:
    Movie(std::string title = "", int year = 1888, int stars = 1);

    void set_title(std::string);
    std::string get_title() const;

    void set_year(int);
    int get_year() const;

    void set_stars(int);
    int get_stars() const;

    bool iequals(const Movie&);
};

#endif // MURACH_MOVIE_H