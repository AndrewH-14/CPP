#include<iostream>
#include<vector>

class Counter
{
    private:
        std::vector<int> steps;

    public:
        std::vector<char> days = { 'M','T','W','T','F','S','S' };
        Counter& get_weekly_steps();
        double get_total();
};

int main()
{
    std::cout << "Welcome to the Weekly Step Counter program!\n\n"
              << "Please enter your steps for the week:\n";

    Counter steps;
    double total = steps.get_weekly_steps().get_total();  // chaining
    double avg = total / steps.days.size();

    std::cout << "Total steps for the week:  " << total << '\n'
              << "Average daily steps:       " << avg   << "\n\n";
}

Counter& Counter::get_weekly_steps()
{
    int daily_steps;

    for (char day : this->days)
    {
        std::cout << day << ": ";
        std::cin >> daily_steps;
        this->steps.push_back(daily_steps);
    }
    std::cout << '\n';

    return *this;  // return a self-reference
}

double Counter::get_total()
{
    double total = 0;

    for (int s : this->steps)
    {
        total += s;
    }

    return total;
}