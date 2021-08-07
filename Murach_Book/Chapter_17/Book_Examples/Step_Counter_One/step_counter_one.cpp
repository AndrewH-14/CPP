#include<iostream>

// declare two functions that define pointer paramters
void get_weekly_steps(int* steps, char* days, int num_days);
double get_total(int* steps, int num_days);

int main()
{
    const int num_days = 7;
    char days[] = "MTWTFSS";      // a built-in array for the days argument
    int steps[num_days] = { 0 };  // a built-in array for the steps argument

    std::cout << "Welcome to the Weekly Step Counter program!\n\n"
              << "Please enter your steps for the week:\n";

    get_weekly_steps(steps, days, num_days);
    double total = get_total(steps, num_days);
    double avg = total / num_days;

    std::cout << "Total steps for the week:  " << total << '\n'
              << "Average daily steps:       " << avg << "\n\n";
}

void get_weekly_steps(int* steps, char* days, int num_days)
{
    if (steps == nullptr || days == nullptr) return;

    for (int i = 0; i < num_days; ++i)
    {
        std::cout << days[i] << ": ";
        std::cin >> steps[i];
    }
    std::cout << '\n';
}

double get_total(int* steps, int num_days)
{
    double total = 0;
    if (steps)
    { // that is, steps is not nullptr
        for (int i = 0; i < num_days; ++i)
        {
            total += steps[i];
        }
    }
    return total;
}