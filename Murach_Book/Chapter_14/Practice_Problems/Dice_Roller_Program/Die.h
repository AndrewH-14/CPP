#ifndef MURACH_DIE_H
#define MURACH_DIE_H

#include <string>

using std::string;

class Die 
{
    private:
        int value;
        string image;
    
    public:
        Die();
        void roll();
        int get_value() const;
        void set_value(int const value_p);
        string get_image();
};

#endif // MURACH_DIE_H