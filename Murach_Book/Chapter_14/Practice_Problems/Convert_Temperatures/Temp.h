#ifndef HANKINS_TEMP_H
#define HANKINS_TEMP_H

class Temp
{
    private:
        int fahrenheit;
        int celsius;
    public:
        Temp();
        int get_fahrenheit() const;
        int get_celcius() const;
        void set_fahrenheit(double const fahrenheit_p);
        void set_celcius(double const celcius_p);
};

#endif // HANKINS_TEMP_H