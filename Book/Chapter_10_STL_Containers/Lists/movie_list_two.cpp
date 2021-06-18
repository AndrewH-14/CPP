#include <iostream>
#include <iomanip>
#include <string>
#include <list>

using namespace std;

void display_rankings(const list<string>& movies);
char get_choice();
void change_ranking(list<string>& movies, int current_ranking, int new_ranking);

int main() 
{
    list<string> movies
    { 
        "Casablanca", 
        "Wonder Woman", 
        "The Godfather",
        "E.T.", 
        "The Bridge on the River Kwai" 
    };

    cout << "The Movie Rankings program\n";
    display_rankings(movies);
    char choice = get_choice();

    while (tolower(choice) == 'y') 
    {
        int current_ranking = 0, new_ranking = 0;
        cout << "Enter current ranking of a movie: ";
        cin >> current_ranking;
        cout << "Enter new ranking of the movie: ";
        cin >> new_ranking;

        change_ranking(movies, current_ranking, new_ranking);
        display_rankings(movies);    // show new rankings
        choice = get_choice();       // ask user if they want to continue
    }
}

void display_rankings(const list<string>& movies) 
{
    cout << "\nMovie Rankings\n--------------\n";
    int i = 1;
    for (string m : movies) 
    {
        cout << i << " - " << m << endl;
        ++i;
    }
    cout << endl;
}

char get_choice() 
{
    char choice;
    cout << "Do you want to change any rankings? (y/n): ";
    cin >> choice;
    cin.ignore(10000, '\n');
    return choice;
}

void change_ranking(list<string>& movies, int current_ranking, int new_ranking) 
{

    // make sure rankings are in bounds
    if (current_ranking > 0 && new_ranking > 0 &&
        current_ranking <= movies.size() &&
        new_ranking <= movies.size()) 
    {

        // get iterator that points to first element
        auto iter = movies.begin();

        // increment iterator until it points to current ranking
        for (int i = 1; i < current_ranking; ++i) 
        {
            ++iter;
        }

        // store value of element to be moved
        string movie = *iter;

        // remove element
        movies.erase(iter);

        // get first iterator again and then increment to new ranking
        iter = movies.begin();
        for (int i = 1; i < new_ranking; ++i) 
        {
            ++iter;
        }

        // insert element at new location
        movies.insert(iter, movie);
    }
}