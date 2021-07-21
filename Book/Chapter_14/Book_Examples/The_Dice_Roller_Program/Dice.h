#ifndef MURACH_DICE_H
#define MURACH_DICE_H

#include <vector>
#include "Die.h"

class Dice
{
private:
    std::vector<Die> dice;
    
public:
    Dice();
    void add_die(Die die);
    void roll_all();
    std::vector<Die> get_dice() const;
};

#endif // MURACH_DICE_H