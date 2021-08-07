#include <iostream>
#include "Die.h"
#include "Dice.h"

using namespace std;

int main() {
    cout << "The Dice Roller program\n\n";

    for (int num = 1; num <= 6; num++)
    {
        Die die;

        die.set_value(num);
        cout << die.get_image();
    }

    cout << endl;

     // get number of dice from user
    int count;
    cout << "Enter the number of dice to roll: ";
    cin >> count;

    // create Dice object and add Die objects to it
    Dice dice;
    for (int i = 0; i < count; ++i) {
        Die die;
        dice.add_die(die);
    }

    char choice = 'y';
    while (choice == 'y') 
    {
        // roll the dice
        dice.roll_all();
        cout << "YOUR ROLL: \n";
        for (Die die : dice.get_dice()) 
        {
            cout << die.get_image() << endl;
        }
        cout << endl;

        cout << "TOTAL: " << dice.get_total() << endl;

        cout << "Roll again? (y/n): ";
        cin >> choice;
    }
    cout << "Bye!\n\n";
}