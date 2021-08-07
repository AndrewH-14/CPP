#include <iostream>
#include <fstream>
#include <sstream> 
#include <iomanip>
#include <string>
#include <vector>
#include <list>

using namespace std;

/// Struct that stores the information regarding a movie
struct Movie 
{
    /// The title of the movie
    string title = "";
    /// The year the movie came out
    unsigned int year = 0;
    /// The rating (1-5) assigned to the movie
    unsigned int stars = 0;
    /// member function declaration
    bool equals(Movie&);
};

/// Member function definition
bool Movie::equals(Movie& to_compare) 
{
    return (title == to_compare.title && year == to_compare.year);
}

/// String containing the name of the text file storing the movie list data
const string movies_file = "movies.txt";

/**
 * Gets the movies that were previosly entered from the `movies.txt` file. Should be ran at the
 * begining of the program in order to reinitialize the stored data.
 * 
 * @return movies A list that contains the movies read from the `movies.txt` file.
 */
list<Movie> read_movies_from_file() 
{
    list<Movie> movies;

    ifstream input_file(movies_file);

    // if file opened successfully...
    if (input_file) 
    {
        Movie movie;
        string line;

        while (getline(input_file, line)) 
        {
            stringstream ss(line);

            // get title
            getline(ss, movie.title, '\t');
            // get year and stars
            ss >> movie.year >> movie.stars;
            // add movie to vector
            movies.push_back(movie);
        }
        input_file.close();
    }
    return movies;
}

/**
 * Writes the new list of movies to the `movies.txt` file.
 * 
 * @param[in] movies A constant list refernce containing the movies entered by the user.
 */
void write_movies_to_file(const list<Movie>& movies) 
{
    ofstream output_file(movies_file);

    // if file opened successfully...
    if (output_file) 
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

/**
 * Iterates through the list in order to display the stored movies.
 * 
 * @param[in] movies A constant list reference that stores the movies to be displayed.
 */
void view_movies(const list<Movie>& movies)
{
    int col_width = 8;
    cout << left
        << setw(col_width / 2) << " "
        << setw(col_width * 4) << "TITLE"
        << setw(col_width) << "YEAR"
        << setw(col_width) << "STARS" << endl;

    int number = 1;
    for (Movie movie : movies) 
    {
        cout << setw(col_width / 2) << number
             << setw(col_width * 4) << movie.title
             << setw(col_width)     << movie.year
             << setw(col_width)     << movie.stars 
             << endl;
        ++number;
    }
    cout << endl;
}

/**
 * Creates a new Movie struct and prompts the user for the information to populate it.
 * 
 * @return movie The newly created Movie struct.
 */
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

/**
 * Adds a Movie struct to the list of movies.
 * 
 * @param[in, out] movies A list of Movie structs that the new movie will be added to.
 */
void add_movie(list<Movie>& movies)
{
    Movie movie = get_movie();

    // check if movie already exists
    bool already_exists = false;

    for (Movie& m : movies) 
    {
        if (m.equals(movie)) 
        {
            already_exists = true;
            break;
        }
    }

    if (already_exists) 
    {
        write_movies_to_file(movies);
        cout << movie.title << " already exists.\n\n";
    }
    else 
    {
        movies.push_back(movie);
        write_movies_to_file(movies);
        cout << movie.title << " was added.\n\n";
    }
}

/**
 * Function that gets a valid number correlating to a moive in the list.
 * 
 * @param[in] movies A constant list refernce in order to validate the entered number.
 *
 * @return number An integer storing the users input.
 */
int get_movie_number(const list<Movie>& movies) 
{
	cin.ignore(1000, '\n');
	int number;
    while (true) 
    {
        number = 0;
        cout << "Number: ";
        cin  >> number;
        if (number > 0 && number <= movies.size()) 
        {
            return number;
        }
        else if (cin.fail())
        {
            cout << "Please enter an integer.\n";
            cin.clear();
            cin.ignore(100, '\n');
        }
        else 
        {
            cout << "Invalid movie number. Try again.\n";
        }
    }
}

/**
 * Removes a movie from the list based on the input number
 * 
 * @param[in, out] movies A reference to the movies list.
 */
void delete_movie(list<Movie>& movies) 
{
    int number = get_movie_number(movies);

    list<Movie>::iterator iter = movies.begin();
    
    for (uint8_t idx = 1; idx < number; idx++)
    {
        iter++;
    }

    Movie movie = *iter;

    movies.erase(iter);

    write_movies_to_file(movies);
    
    cout << movie.title << " was deleted.\n\n";
}

/**
 *  Modifies a movie in the list based on the users input number
 * 
 * @param[in, out] movies A refernce to the movie list.
 */
void modify_movie(list<Movie>& movies)
{
    int const number = get_movie_number(movies);

    list<Movie>::iterator iter = movies.begin();

    for (uint8_t idx = 1; idx < number; idx++)
    {
        iter++;
    }

    cout << "Enter new number of stars (1-5) for " << iter->title << ": ";
    cin  >> iter->stars;
    cout << iter->title << " was updated.";
    cout << endl << endl;

    write_movies_to_file(movies);
}

/**
 * Diplays the possible commands in the terminal
 */
void display_menu() 
{
    cout << "COMMANDS\n"
        << "v - View movie list\n"
        << "a - Add a movie\n"
        << "d - Delete a movie\n"
        << "m - Modify a movie\n"
        << "x - Exit\n\n";
}

/**
 * Main functoin for the movie list program that:
 * 
 * 1. Reloads previous input
 * 2. Prompts user for command
 * 3. Calls the relevent function based on the command
 */
int main() 
{
    cout << "The Movie List program\n\n";

    display_menu();

    list<Movie> movies = read_movies_from_file();

    char command = 'v';
    while (command != 'x') 
    {
        cout << "Command: ";
        cin >> command;

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
            case 'm':
                modify_movie(movies);
                break;
            case 'x':
                cout << "Bye!\n\n";
                break;
            default:
                cout << "Not a valid command. Please try again.\n\n";
                break;
        }
    }
}