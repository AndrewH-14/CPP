#include <iostream>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};

struct Invoice
{
    int number;
    Date date;
    Date due_date;
    double total;
};

int main(void)
{
    // Create the Invoice structure
    Invoice invoice;

    //assign values to the Invoice and Date structures
    invoice.number =       1;
    invoice.date.month     = 1;
    invoice.date.day       = 2;
    invoice.date.year      = 2018;
    invoice.due_date.month = 4;
    invoice.due_date.day   = 15;
    invoice.due_date.year  = 2018;
    invoice.total          = 1430.72;

    //read values from the Invoice and Date structures
    cout << "INVOICE\n"
         << "Number: "   << invoice.number         << endl
         << "Date:  "    << invoice.date.year      << '-'
                         << invoice.date.month     << '-'
                         << invoice.date.day       << endl
         << "Due Date: " << invoice.due_date.year  << '-'
                         << invoice.due_date.month << '-'
                         << invoice.due_date.day   << endl
         << "Total: "    << invoice.total          << endl << endl; 
}