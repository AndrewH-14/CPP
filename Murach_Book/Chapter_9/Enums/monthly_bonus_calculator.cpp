#include <iostream>

using namespace std;

/**
 * A scoped enumeration that assigns a department a corresponding value
 * stating at 1.
 */
enum class Department { marketing = 1, it, sales, other };

// function prototypes
void show_menu();
Department get_department();
bool check_criteria(Department);

/**
 * Main function for the Monthly Bonus Calculator that
 * 1. Gets the users department
 * 2. Checks if the user qualifies for the monthly bonus
 * 3. Displays a message depending on whether the use 
 *    qualified for the bonus. 
 */
int main(void)
{
    cout << "The Monthly Bonus Calculator\n\n";
    show_menu();

    Department dept = get_department();
    bool bonus = check_criteria(dept);
    const double bonus_amt = 1000;

    if (bonus)
    {
        cout << "Congrats! You earned the $" << bonus_amt
             << " monthly bonus.\n\n";
    }
    else
    {
        cout << "Sorry! No bonus for you this month :( Keep trying!\n\n";
    }

    return 0;
}

/**
 * Diplays the departments and their corresponding number.
 */
void show_menu()
{
    cout << "DEPTARTMENTS\n"
         << static_cast<int>(Department::marketing) << " - Marketing\n"
         << static_cast<int>(Department::it)        << " - IT\n"
         << static_cast<int>(Department::sales)     << " - Sales\n"
         << static_cast<int>(Department::other)     << " - Other\n\n";
}

/**
 * Gets the department that the user works in and returns the value
 * 
 * @return The enumerator that corresponds to the user's department number
 */
Department get_department()
{
    cout << "Enter department number: ";

    int choice = 0;
    cin >> choice;

    Department dept = static_cast<Department>(choice);

    if (dept < Department::marketing || dept > Department::sales)
    {
        return Department::other;
    }
    else
    {
        return dept;
    }
}

/**
 * Asks the user a depathement specific question to determine whether they 
 * earned a bonus.
 * 
 * @retval true User earned a bonus.
 * @retval false User did not earn a bonus.
 */
bool check_criteria(Department dept)
{
    switch (dept) 
    {
        case Department::marketing:
            int viral_campaigns;

            cout << "How many of your campains went viral "
                 << "this month?: ";
            cin  >> viral_campaigns;

            return viral_campaigns >= 4;
        case Department::it:
            int trouble_tickets;

            cout << "How many trouble tickets did you close "
                 << "this month?: ";
            cin  >> trouble_tickets;

            return trouble_tickets >= 10;
        case Department::sales:
            double sales;

            cout << "What were your total sales this month?: ";
            cin  >> sales;

            return sales >= 1000;
        case Department::other:
            char supervisor_grade;

            cout << "What was your grade from your supervisor "
                 << "this month?: ";
            cin  >> supervisor_grade;

            return tolower(supervisor_grade) == 'a';
    }
    return false;
}
