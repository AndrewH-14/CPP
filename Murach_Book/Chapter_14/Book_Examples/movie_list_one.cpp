#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Movie 
{
    private:
        string title = "";
        int year = 0;
    public:
        void   set_title(string);
        string get_title() const;
        string get_title_upper() const;
        void   set_year(int);
        int    get_year() const;
        bool   equals(const Movie&);
        string to_str() const;
};

void Movie::set_title(string title_param)
{
    title = title_param;
}

string Movie::get_title() const
{
    return title;
}

string Movie::get_title_upper() const
{
    string title_upper;
    for (char c : title) 
    {
        title_upper.push_back(toupper(c));
    }
    return title_upper;
}

void Movie::set_year(int year_param) 
{
    if (year_param < 1888) 
    {
        throw invalid_argument("Year must be 1888 or later.");
    }
    year = year_param;
}

int Movie::get_year() const
{
    return year;
}

bool Movie::equals(const Movie& to_compare) 
{
    return (title == to_compare.title && year == to_compare.year);
}

string Movie::to_str() const 
{
    return title + " (" + to_string(year) + ')';
}

int main() 
{
    cout << "The Movie List program\n\n"
         << "Enter a movie...\n\n";

    // get vector of Movie objects
    vector<Movie> movies;
    char another = 'y';
    while (tolower(another) == 'y') 
    {
        Movie movie;

        string title;
        cout << "Title: ";
        getline(cin, title);
        movie.set_title(title);

        int year;
        cout << "Year: ";
        cin  >> year;
        try 
        {
            movie.set_year(year);
        }
        catch (const invalid_argument& e) 
        {
            cout << e.what() << "\n";
            cout << "Exiting program...\n\n";
            return 0;
        }

        movies.push_back(movie);

        cout << "\nEnter another movie? (y/n): ";
        cin >> another;
        cin.ignore();
        cout << endl;
    }

    // display the movies
    const int w = 10;
    cout << left
        << setw(w * 3) << "TITLE"
        << setw(w)     << "YEAR" << endl;
    for (Movie movie : movies) 
    {
        cout << setw(w * 3) << movie.get_title()
             << setw(w)     << movie.get_year() << endl;
    }
    cout << endl;
}

