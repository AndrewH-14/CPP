#include "Movie.h"
#include <string>

using std::string;
using std::invalid_argument;

// private function
string Movie::to_upper(string str) {
    string str_upper;
    for (char c : str) {
        str_upper.push_back(toupper(c));
    }
    return str_upper;
}

// public functions
Movie::Movie(string title, int year, int stars) {
    set_title(title);
    set_year(year);
    set_stars(stars);
}

void Movie::set_title(string title_param) {
	if (title_param.size() > 120) {
		throw invalid_argument("Title must not have more than 120 chars.");
	}
    title = title_param;
}

string Movie::get_title() const {
    return title;
}

void Movie::set_year(int year_param) {
    if (year_param < 1888) {
        throw invalid_argument("Year must be 1888 or later.");
    }
    year = year_param;
}

int Movie::get_year() const {
    return year;
}

void Movie::set_stars(int stars_param) {
    if (stars_param < 1 || stars_param > 5) {
        throw invalid_argument("Stars must be from 1 to 5.");
    }
    stars = stars_param;
}

int Movie::get_stars() const {
    return stars;
}

bool Movie::iequals(const Movie& to_compare) {
    return (to_upper(title) == to_upper(to_compare.title) &&
        year == to_compare.year);
}