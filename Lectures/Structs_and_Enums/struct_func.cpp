#include <iostream>

using namespace std;

struct Movie
{
    string title;
    int year;
};

// Function that initializes, fills, and returns a movie struct
Movie get_movie()
{
    Movie movie;
    
    cout << "Enter title: ";
    getline(cin, movie.title);

    cout << "Enter year: ";
    cin  >> movie.year;

    return movie;
}

// Function that takes in a Movie object and displays it
void display_movie(const Movie& movie)
{
    cout << "MOVIE: " << movie.title << " ("
         << movie.year << ")\n\n";
}

// Function that takes in a reference to a Movie object and updates the year
void update_movie_year(Movie& movie)
{
    cout << "Update Year: ";
    cin  >> movie.year;
}

Movie update_movie_year2(Movie movie)
{
    cout << "Update Year: ";
    cin  >> movie.year;
    return movie;
}

int main(void)
{
    Movie movie = get_movie();
    display_movie(movie);

    update_movie_year(movie);
    display_movie(movie);

    movie = update_movie_year2(movie);
    display_movie(movie);

    return 0; 
}