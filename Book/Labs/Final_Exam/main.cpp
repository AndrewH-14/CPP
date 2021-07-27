#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdexcept>

#include "Movie.h"

using namespace std;

/**
 * Function that prompts the user for the movies title, and stores it in
 * the Movie object.
 *
 * @param[in] movies A reference to the Movie object vector.
 */
void get_title(Movie& movie)
{
    string title = "";

    cout << "Title: ";
    getline(cin, title);

    movie.set_title(title);
}

/**
 * Function that prompts the user for the movie's release year, and stores
 * it in the Movie object. If the release year is an invalid type, the function
 * will prompt the user to enter a new year until a valid one is entered. If the
 * entered integer is invalid, an exception will be thrown signalling to exit the
 * program.
 *
 * @param[in] movie A reference to a Movie object.
 *
 * @retval True  A valid value was entered.
 * @retval False An invalid value was entered.
 */
bool get_year(Movie& movie)
{
    int release_year = 0;

    // Loop until a valid release year data type is entered.
    while(true)
    {
        cout << "Year: ";

        if (!(cin >> release_year))  // User entered wrong data type.
        {
            cin.clear();
            cin.ignore(100, '\n');

            cout << "Please enter an integer!\n";
        }
        else // User entered a valid data type.
        {
            try
            {
                movie.set_year(release_year);
            }
            catch (const invalid_argument& e)
            {
                cout << e.what() << endl;
                cout << "Exiting program...\n\n";

                // An invalid integer was entered, exit program
                return false;
            }
            // A valid integer was entered
            return true;
        }
    }
}

/**
 * Adds the Movie object to the vector if it is not already there.
 *
 * @param[in, out] movies A reference to the vector of Movie objects.
 *
 * @param[in] movie A reference to a Movie object to be added to the vector.
 */
void add_movie(vector<Movie>& movies, const Movie& movie)
{
    bool b_add_movie = true;

    // Iterate through the movie vector to see if the move already
    // exists.
    for (Movie m : movies)
    {
        if(m.equals(movie)) // Movie already exists in the vector
        {
            cout << "Movie already in list!" << endl;
            b_add_movie = false;
            break;
        }
    }

    // If the movie does not already exist in the vector then add it
    if (b_add_movie)
    {
        movies.push_back(movie);
    }
}

/**
 * Function that iterates through the movies vector and displays each movies
 * title and release year.
 *
 * @param[in] movies A constant reference to the Movie object vector.
 */
void display_movies(const vector<Movie>& movies)
{
    int const w = 10;

    cout << left
         << setw(w * 3) << "TITLE"
         << setw(w)     << "YEAR" << endl;

    for (Movie movie : movies) // For each movie in the movies vector
    {
        cout << setw(w * 3) << movie.get_title()
             << setw(w)     << movie.get_year()  << endl;
    }
    cout << endl;
}

/**
 * Main function for The Movie List Program.
 *
 * This program will:
 * 1. Prompt user for details about a movie.
 * 2. Add the movie to a Movie object vector.
 * 3. Ask if adding another movie is desired.
 * 4. Display the contents of the vector and exit.
 */
int main(void)
{
    cout << "The Movie List Program" << endl << endl;
    cout << "Enter a movie..."       << endl << endl;

    // Initialze a vector of Movie objects
    vector<Movie> movies;

    char user_choice = 'y';

    // Run loop until the user enters a non 'y' character
    while (tolower(user_choice) == 'y')
    {
        Movie movie;

        // Prompts user for the movie's title
        get_title(movie);

        // Prompts user for the movie's release year
        if (!get_year(movie))
        {
            // An invalid value was detected, exit program
            return 0;
        }

        // If the movie does not already exist in the vector then add it
        add_movie(movies, movie);

        // Ask user if they would like to continue
        cout << "\nEnter another movie? (y/n): ";

        cin >> user_choice;
        cin.ignore();

        cout << endl;
    }

    // Displays all the movies added to the vector
    display_movies(movies);

    // The program ran successfully
    return 0;
}