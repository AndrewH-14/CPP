#ifndef HANKINS_CIRCLE_H
#define HANKINS_CIRCLE_H

class Circle
{
    private:
        double radius;
        double const pi = 3.14149;

    public:
        Circle(double radius = 0);
        void   set_radius(double const radius_p) { radius = radius_p; };
        double get_radius() const { return radius; };

        double get_diameter() const;
        double get_circumference() const;
        double get_area() const;

};

#endif // HANKINS_CIRCLE_H