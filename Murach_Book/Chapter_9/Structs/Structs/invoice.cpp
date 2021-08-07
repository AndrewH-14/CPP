#include <iostream>
#include <vector>

using namespace std;

struct Date
{
    int year  = 1900;
    int month = 1;
    int day   = 1;
};

struct Invoice
{
    int number = -1;
    Date date;
    Date due_date;
    double total = 0;
};

int main(void)
{
    // Create the Invoice stucture
    Invoice invoice;

    // assign values to the Invoice and Date structures
    invoice.number         = 1;
    invoice.date.month     = 1;
    invoice.date.day       = 2;
    invoice.date.year      = 2018;
    invoice.due_date.month = 4;
    invoice.due_date.day   = 15;
    invoice.due_date.year  = 2018;
    invoice.total          = 1430.72;

    // read values from the Invoice and Date structures
    cout << "INVOICE\n"
         << "Number:    " << invoice.number         << endl
         << "Date:      " << invoice.date.year      << '-'
                          << invoice.date.month     << '-'
                          << invoice.date.day       << endl
         << "Due Date:  " << invoice.due_date.year  << '-'
                          << invoice.due_date.month << '-'
                          << invoice.due_date.day   << endl
         << "Total:     " << invoice.total          << endl << endl;

    return 0;
}