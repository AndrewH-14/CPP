#include <iostream>
#include <cmath>

#include "Temp.h"

using namespace std;

// declare functions
void display_menu();
void convert_temp();

int main() 
{

	cout << "Convert Temperatures\n\n";

    display_menu();
    char again = 'y';
    while (again == 'y') 
    {
        convert_temp();

        cout << "Convert another temperature? (y/n): ";
        cin >> again;
        cout << endl;
    }
    cout << "Bye!\n";
}

/****************************************************
* Define functions
*****************************************************/

void display_menu() 
{
    cout << "MENU\n"
        << "1. Fahrenheit to Celsius\n"
        << "2. Celsius to Fahrenheit\n\n";
}

void convert_temp() 
{
    int option;
    cout << "Enter a menu option: ";
    cin >> option;

    Temp temp;

    double f = 0.0;
    double c = 0.0;
    switch (option) 
    {
        case 1:
            cout << "Enter degrees Fahrenheit: ";
            cin >> f;

            temp.set_fahrenheit(f);

            cout << "Degrees Celsius: " << temp.get_celcius() << endl;
            break;
        case 2:
            cout << "Enter degrees Celsius: ";
            cin >> c;

            temp.set_celcius(c);

            cout << "Degrees Fahrenheit: " << temp.get_fahrenheit() << endl;
            break;
        default:
            cout << "You must enter a valid menu number.\n";
         break;
    }
}
