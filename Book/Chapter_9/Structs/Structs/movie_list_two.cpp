#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Movie
{
    string title       = "";
    unsigned int year  = 0;
    unsigned int stars = 0;
    bool equals(Movie&);  // Memeber function declaration
};

// member function definition
bool Movie::equals(Movie& to_compare)
{
    return ((title == to_compare.title) && (year == to_compare.year));
}

const string movies_file = "movies.txt";

vector<Movie> read_movies_from_file() 
{
    vector<Movie> movies;

    ifstream input_file(movies_file);
    if (input_file) // If file opened successfully
    {
        Movie movie;
        string line;

        while(getline(input_file, line))
        {
            stringstream ss(line);

            getline(ss, movie.title, '\t');  // get title
            ss >> movie.year >> movie.stars; // get year and stars
            movies.push_back(movie);         // add movie to vector
        }
        input_file.close();
    }
    return movies;
}

void write_movies_to_file(const vector<Movie>& movies)
{
    ofstream output_file(movies_file);

    if (output_file) // if file opened successfully
    {
        for (Movie movie : movies)
        {
            output_file << movie.title << '\t'
                        << movie.year  << '\t'
                        << movie.stars << '\n';
        }
        output_file.close();
    }
}

void view_movies(const vector<Movie>& movies)
{
    int col_width = 8;

    cout << left
         << setw(col_width / 2) << " "
         << setw(col_width * 4) << "TITLE"
         << setw(col_width)     << "YEAR"
         << setw(col_width)     << "STARS" << endl;

    int number = 1;

    for (Movie movie : movies)
    {
        cout << setw(col_width / 2) << number
             << setw(col_width * 4) << movie.title
             << setw(col_width)     << movie.year
             << setw(col_width)     << movie.stars << endl;

        ++number;
    }

    cout << endl;
}

Movie get_movie()
{
    Movie movie;

    cout << "Title: ";
    cin.ignore(1000, '\n');
    getline(cin, movie.title);

    cout << "Year: ";
    cin >> movie.year;

    cout << "Stars (1-5): ";
    cin >> movie.stars;

    return movie;
}

void add_movie(vector<Movie>& movies)
{
    Movie movie = get_movie();

    // check if movie already exists
    bool already_exists = false;

    for (Movie& m : movies)
    {
        if (m.equals(movie))
        {
            already_exists = true;
            m.stars        = movie.stars;
            break;
        }
    }

    if (already_exists)
    {
        write_movies_to_file(movies);
        cout << movie.title << " already exists and was updated.\n\n";
    }
    else 
    {
        movies.push_back(movie);
        write_movies_to_file(movies);
        cout << movie.title << " was added.\n\n";
    }
}

int get_movie_number(const vector<Movie>& movies)
{
    cin.ignore(1000, '\n');

    int number;

    while (true)
    {
        cout << "Number: ";
        cin  >> number;

        if ((number > 0) && (number <= movies.size()))
        {
            return number;
        }
        else
        {
            cout << "Invalid movie number. Try again.\n";
        }
    }
}

void delete_movie(vector<Movie>& movies)
{
    int number = get_movie_number(movies);

    int index = number - 1;

    Movie movie = movies[index];
    movies.erase(movies.begin() + index);
    write_movies_to_file(movies);
    cout << movie.title << " was deleted.\n\n";
}

void display_menu() 
{
    cout << "COMMANDS\n" 
         << "v - View movie list\n"
         << "a - Add a movie\n"
         << "d - Delete a movie\n"
         << "x - Exit\n\n";
}

int main(void)
{
    cout << "The Movie List Program\n\n";
    display_menu();
    vector<Movie> movies = read_movies_from_file();
    char command = 'v';

    while (command != 'x')
    {
        cout << "Command: ";
        cin  >> command;

        switch (command)
        {
            case 'v':
                view_movies(movies);
                break;
            case 'a':
                add_movie(movies);
                break;
            case 'd':
                delete_movie(movies);
                break;
            case 'x':
                cout << "Bye!\n\n";
                break;
            default:
                cout << "Not a valid command. Please try again.\n\n";
                break;
        }
    }

    return 0;
}