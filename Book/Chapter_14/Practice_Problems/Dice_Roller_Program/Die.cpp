#include "Die.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Die::Die() 
{
    srand(time(nullptr));  // seed the rand() function
    value = 1;
}

void Die::roll() 
{
    value = rand() % 6;    // value is >= 0 and < 6
    ++value;               // value is >= 1 and <= 6
}

int Die::get_value() const 
{
    return value;
}

void Die::set_value(int const value_p)
{
    if ((value_p < 1) or (value_p > 6))
    {
        throw invalid_argument("Must be a number 1 and 6\n");
    }
    value = value_p;
}

string Die::get_image()
{   
    if (1 == value)
    {
        string image =  " _____ \n"
                        "|     |\n"
                        "|  o  |\n" 
                        "|_____|\n";
        return image;
    }
    else if (2 == value)
    {
        string image =  " _____ \n"
                        "|o    |\n"
                        "|     |\n" 
                        "|____o|\n";
        return image;
    }
    else if (3 == value)
    {
        string image =  " _____ \n"
                        "|o    |\n"
                        "|  o  |\n" 
                        "|____o|\n";
        return image;
    }
    else if (4 == value)
    {
        string image =  " _____ \n"
                        "|o   o|\n"
                        "|     |\n" 
                        "|o___o|\n";
        return image;
    }
    else if (5 == value)
    {
        string image =  " _____ \n"
                        "|o   o|\n"
                        "|  o  |\n" 
                        "|o___o|\n";
        return image;
    }
    else if (6 == value)
    {
        string image =  " _____ \n"
                        "|o   o|\n"
                        "|o   o|\n" 
                        "|o___o|\n";
        return image;
    }
    else
    {
        cout << "Set value of the die first.\n";
    }

    return image;
}