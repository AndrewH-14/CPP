#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// A structure to store a movie's title and year
struct Movie
{
    string title = "";
    int year     = 0;
};

/**
 * Function that prompts the user for the movies title, and stores it in
 * the Movie struct.
 *
 * @param[in] movies A reference to the Movie struct vector.
 */
void get_title(Movie& movie)
{
    cout << "Title: ";
    getline(cin, movie.title);
}

/**
 * Function that prompts the user for the movie's release year, and stores
 * it in the Movie struct. If the release year is invalid, the function
 * will prompt the user to enter a new year until a valid one is entered.
 *
 * @param[in] movie A reference to a Movie struct.
 */
void get_year(Movie& movie)
{
    int release_year = 0;

    // Loop until a valid release year is entered.
    while(true)
    {
        cout << "Year: ";

        if (!(cin >> release_year))  // User entered wrong data type.
        {
            cin.clear();
            cin.ignore(100, '\n');

            cout << "Please enter an integer!\n";
        }
        else if (1888 > release_year) // First movie came out in 1888
        {
            cout << "Please enter a valid year!\n";
        }
        else // User entered a valid release year.
        {
            movie.year = release_year;
            return;
        }
    }
}

/**
 * Function that iterates through the movies vector and displays each movies
 * title and release year.
 *
 * @param[in] movies A constant reference to the Movie struct vector.
 */
void display_movies(const vector<Movie>& movies)
{
    int const w = 10;

    cout << left
         << setw(w * 3) << "TITLE"
         << setw(w)     << "YEAR" << endl;

    for (Movie movie : movies) // For each movie in the movies vector
    {
        cout << setw(w * 3) << movie.title
             << setw(w)     << movie.year << endl;
    }
    cout << endl;
}

/**
 * Main function for The Movie List Program.
 *
 * This program will:
 * 1. Prompt user for details about a movie.
 * 2. Add the movie to a Movie struct vector.
 * 3. Ask if adding another movie is desired.
 * 4. Display the contents of the vector and exit.
 */
int main(void)
{
    cout << "The Movie List Program" << endl << endl;
    cout << "Enter a movie..."          << endl << endl;

    vector<Movie> movies;

    char user_choice = 'y';

    // Run loop until the user enters a non 'y' character
    while (tolower(user_choice) == 'y')
    {
        Movie movie;

        // Prompts user for the movie's title
        get_title(movie);

        // Prompts user for the movie's release year
        get_year(movie);

        // Add a movie to the back of the vector
        movies.push_back(movie);

        cout << "\nEnter another movie? (y/n): ";

        cin >> user_choice;
        cin.ignore();

        cout << endl;
    }

    // Displays all the movies added to the vector
    display_movies(movies);

    return 0;
}
