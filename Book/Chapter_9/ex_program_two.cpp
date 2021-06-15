#include <iostream>
#include <fstream>
#include <sstream> 
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

/**
 * Scoped char enum that is used to select different options 
 * in the main function.
 */
enum class Command : char
{ 
    view = 'v', 
    add  = 'a', 
    del  = 'd', 
    exit = 'x'
};

/**
 * A struct that contains information for a movie.
 * 
 * This includes a function to check whether the movie is the same as another.
 */
struct Movie 
{
    string title = "";
    unsigned int year = 0;
    unsigned int stars = 0;
    bool equals(Movie&);              // member function declaration
};

/**
 * The struct member function declaration that compares the structs title and year
 * in order to determine if they are equivalent.
 * 
 * @param[in] to_compare A reference to a movie struct that is to be compared to this
 *                       structs movie.
 * 
 * @retval true  The movies are the same.
 * @retval false The movies are different.
 */
bool Movie::equals(Movie& to_compare) 
{
    return (title == to_compare.title && year == to_compare.year);
}

// The filename of the file where the movies will be writen to and read from.
const string movies_file = "movies.txt";

/**
 * A function that reads the information stored within the `movies.txt` file in 
 * order to store it in a vector.
 * 
 * @return A Movie vector that contains all the movies stored in the `movies.txt` file
 */
vector<Movie> read_movies_from_file() 
{
    vector<Movie> movies;

    ifstream input_file(movies_file);
    if (input_file)    // if file opened successfully...
    {
        Movie movie;
        string line;
        while (getline(input_file, line)) 
        {
            stringstream ss(line);

            getline(ss, movie.title, '\t');     // get title
            ss >> movie.year >> movie.stars;    // get year and stars
            movies.push_back(movie);            // add movie to vector
        }
        input_file.close();
    }
    return movies;
}

/**
 * @param[in] movies A refernce to a Movie vector that will be written to and stored in the
 *                   `movies.txt` file.
 */
void write_movies_to_file(const vector<Movie>& movies) 
{
    ofstream output_file(movies_file);

    if (output_file)     // if file opened successfully...
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
 * @param[in] movies A constant reference to a Movie vector that will be printed to the
 *                   terminal
 */
void view_movies(const vector<Movie>& movies) 
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
             << setw(col_width) << movie.year
             << setw(col_width) << movie.stars << endl;
        
        ++number;
    }
    cout << endl;
}

/**
 * Function that gets the title, year, and rating for a new movie struct.
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
 * @param[in] movies A reference to a Movie vector in order to add a new movie struct to the end.
 */
void add_movie(vector<Movie>& movies) {
    Movie movie = get_movie();

    // check if movie already exists
    bool already_exists = false;
    for (Movie& m : movies) 
    {
        if (m.equals(movie)) 
        {
            already_exists = true;
            m.stars = movie.stars;
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

/**
 * @param[in] movies A constant reference to a Movie vector in order to get
 * 
 * @return 
 */
int get_movie_number(const vector<Movie>& movies) 
{
    int number;

    while (true) 
    {
        cout << "Number: ";
        cin >> number;

        if (number > 0 && number <= movies.size()) 
        {
            return number;
        }
        else {
            cout << "Invalid movie number. Try again.\n";
        }
    }
}

/**
 * @param[in] movies
 */
void delete_movie(vector<Movie>& movies) 
{
    int number = get_movie_number(movies);

    int index = number - 1;
    Movie movie = movies[index];
    movies.erase(movies.begin() + index);
    write_movies_to_file(movies);
    cout << movie.title << " was deleted.\n\n";
}

/**
 * Function that displays the possible commands.
 */
void display_menu() {
    cout << "COMMANDS\n"
         << static_cast<char>(Command::view) << " - View movie list\n"
         << static_cast<char>(Command::add)  << " - Add a movie\n"
         << static_cast<char>(Command::del)  << " - Delete a movie\n"
         << static_cast<char>(Command::exit) << " - Exit\n\n";
}

/**
 * Main function for the movie list progran that:
 * 1.
 */
int main() {
    cout << "The Movie List program\n\n";
    display_menu();

    vector<Movie> movies = read_movies_from_file();

    char choice = 'v';

    while (choice != 'x') 
    {
        cout << "Command: ";
        cin >> choice;

        Command command = static_cast<Command>(choice);

        switch (command) {
            case Command::view:
                view_movies(movies);
                break;
            case Command::add:
                add_movie(movies);
                break;
            case Command::del:
                delete_movie(movies);
                break;
            case Command::exit:
                cout << "Bye!\n\n";
                break;
            default:
                cout << "Not a valid command. Please try again.\n\n";
                break;
        }
    }
}