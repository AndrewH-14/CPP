#include "Dice.h"

Dice::Dice() {}

void Dice::add_die(Die die)
{
    dice.push_back(die);
}

void Dice::roll_all() 
{
    for (Die& die : dice) 
    {
        die.roll();
    }
}

std::vector<Die> Dice::get_dice() const 
{
    return dice;
}