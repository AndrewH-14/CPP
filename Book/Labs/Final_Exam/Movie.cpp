#include "Movie.h"

#include <string>
#include <stdexcept>

using namespace std;


/***************************************************
 * Member functions for the title member attribute.*
 ***************************************************/

/**
 * Sets the Movie object's private title variable.
 *
 * @param[in] title_param The value to set the title variable to.
 */
void Movie::set_title(string title_param)
{
    title = title_param;
}

/**
 * Gets the Movie object's title.
 *
 * @return title The Movie object's title.
 */
string Movie::get_title() const
{
    return title;
}

/**
 * Gets the Movie object;t title in all caps.
 *
 * @return title_upper The Movie's title in all caps.
 */
string Movie::get_title_upper() const
{
    string title_upper;

    // for each charcter in the title string
    for (char c : title)
    {
        // Add capitalized character to the back of the new string.
        title_upper.push_back(toupper(c));
    }

    return title_upper;
}

/**************************************************
 * Member functions for the year member attribute.*
 **************************************************/

/**
 * Sets the Movie object's private year variable.
 *
 * @param[in] year_param The value to set the year variable to.
 */
void Movie::set_year(int year_param)
{
    if (year_param < 1888)
    {
        throw invalid_argument("Year must be 1888 or later.");
    }

    year = year_param;
}

/**
 * Gets the Movie object's year.
 *
 * @return title The Movie object's release year.
 */
int Movie::get_year() const
{
    return year;
}


/***********************************
 * Miscellaneous member functions. *
 ***********************************/

/**
 * Compares two Movie objects to check if they are equal.
 *
 * @param[in] to_compare The Movie object to compare.
 *
 * @retval true  The Movie objects are equal.
 * @retval false The Movie objects are not equal.
 */
bool Movie::equals(const Movie& to_compare)
{
    return ((year == to_compare.get_year()) &&
            (title == to_compare.get_title()));
}

/**
 * Converts the Movie objects data to a string.
 *
 * @return The Movie objects data in string form.
 *         <title> (<year>)
 */
string Movie::to_str()
{
    return title + " (" + to_string(year) + ')';
}
