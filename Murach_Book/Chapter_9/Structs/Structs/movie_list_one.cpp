#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// define a struct for a Movie object
struct Movie
{
    string title = "";
    int year     = 0;
};

int main(void)
{
    cout << "The Movie List Program\n\n"
         << "Enter a movie...\n\n";

    // get vector of Movie objects
    vector<Movie> movie_list;
    char another = 'y';

    while (tolower(another) == 'y')
    {
        Movie movie;

        cout << "Title: ";
        getline(cin, movie.title);

        cout << "Year: ";
        cin  >> movie.year;

        movie_list.push_back(movie);

        cout << "\nEnter another movie? (y/n): ";
        cin  >> another;
        cin.ignore();
        cout << endl;
    }

    // display the Movie objects stored in the vector
    const int w = 10;
    cout << left
         << setw(w * 3) << "TITLE"
         << setw(w)      << "YEAR" << endl;

    for (Movie movie : movie_list)
    {
        cout << setw(w * 3) << movie.title
             << setw(w)     << movie.year << endl << endl;
    }

    return 0;
}