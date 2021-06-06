#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    struct User_Data_Type_Name
    {
        //struct memebers
    };

    struct Movie
    {
        string title;
        int year;
    };

    Movie movie;

    // Example:
    // movie.title = "Wonder Woman";
    // movie.year  =  2017;

    #if 0
    cout << "Please enter a movie title: ";
    getline(cin, movie.title);
    // cin >> movie.title;

    cout << "Please enter the year that movie was released: ";
    cin >> movie.year;

    cout << movie.title << " was released in " << movie.year << ".\n";
    #endif

    #if 0
    vector<Movie> movies;

    movie.title = "xxx";
    movie.year  = 2021;

    movies.push_back (movie);

    movie.title = "Star Wars";
    movie.year  = 2021;

    movies.push_back (movie);

    for (Movie m: movies)
    {
        cout << m.title << " was released in " << m.year << ".\n";
    }
    #endif

    #if 0

    Movie movie_1 = { "Casablanca", 1942 };
    Movie movie_2 = { "Wonder Woman", 2017 };

    Movie movie_3 = { "Casablance" };
    #endif
}