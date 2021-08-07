#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/**
 * A struct that contains an accounts first name, last name, password,
 * email, and a funtion that compare an account referernce to the struct.
 */
struct Account
{
    string first_name = "";
    string last_name  = "";
	string password   = "";
	string email      = "";
	bool equals(Account&);
};

/**
 * Definition of the equals function from the Account struct, compares the struct variable's email
 * field to the email from the struct reference.
 * 
 * @param[in] to_compare An account reference to be compared with the struct's email field. 
 */
bool Account::equals(Account& to_compare)
{
	return(email == to_compare.email);
}

/**
 * The name of the file where the accounts vector will be read from and to.
 */
const string accounts_file = "accounts.txt";

/**
 * Function that outputs the contents of the passed Account vector to the terminal.
 * 
 * @param[in] accounts A vector of Account structs to display in the terminal.
 */
void display_accounts(vector<Account> accounts) 
{
	int col_width = 10;
	cout << left
		 << setw(col_width * 3) << "Name"
		 << setw(col_width * 4) << "Email" << endl;

	for (Account acc  : accounts)
	{
		cout << setw(col_width * 3) 
		     << acc.first_name + ' ' + acc.last_name
	 		 << setw(col_width * 4) 
			 << acc.email << endl;
	}
}

/**
 * Function that reads the contents of the `accounts.txt` file in order to create an Account vector.
 * 
 * @return accounts A vector of Account structs that were contained in the `accounts.txt` file.
 */
vector<Account> read_accounts_from_file()
{
	vector<Account> accounts;

	ifstream input_file(accounts_file);

	if (input_file) // If file opened
	{
		Account account;
		string line;

		while(input_file >> account.first_name >> account.last_name 
						 >> account.password   >> account.email)
		{
			accounts.push_back(account);
		}
		input_file.close();
	}
	return accounts;
}

/**
 * Function that writest the contents of an Account vector to the `accounts.txt` file.
 * 
 * @param[in] accounts An Account vector that contains all the inforamtion to be written to the 
 * 					   `account.txt` file.
 */
void write_accounts_to_file(vector<Account> accounts)
{
	ofstream output_file(accounts_file);

	if (output_file) // if file opened successfully
	{
		for (Account account : accounts)
		{
			output_file << account.first_name << '\t'
			            << account.last_name  << '\t'
			            << account.password   << '\t'
			            << account.email      << '\n';
		}
			output_file.close();
		}
}

/**
 * Prompts the user for their first name, last name, password, and email in order to create an 
 * account.
 * 
 * @return account An Account struct created with the information obtained.
 */
Account get_account()
{
	Account account;

	cout << "First Name: ";
	getline(cin, account.first_name);

	cout << "Last Name: ";
	getline(cin, account.last_name);

	cout << "Password: ";
	getline(cin, account.password);

	cout << "Email: ";
	getline(cin, account.email);

	return account;
}

/**
 * Main function of the program that 
 * 1. Lists the accounts that have already been created.
 * 2. Prompts user for information in order to create a new account.
 * 3. Asks whether another account creation is desired.
 * 4. Displays all the current account contained in the list.
 * 5. Exits.
 * 
 * @retval 0 The program run successfully.
 */
int main(void)
{
    cout << "Create Account List\n\n";

	vector<Account> accounts = read_accounts_from_file();

	display_accounts(accounts);

	char another = 'y';
	while (tolower(another) == 'y') 
	{
		bool acc_exists = false;
		Account account = get_account();

		for (Account& a : accounts)
		{
			if (a.equals(account))
			{
				acc_exists = true;
				break;
			}
		}

		if (acc_exists)
		{
			cout << account.email << " already exists - account not added.\n\n";
		}
		else
		{
			accounts.push_back(account);
			write_accounts_to_file(accounts);
			
			cout << endl << account.email << " was added for " 
				 << account.first_name + ' ' + account.last_name + '.' << endl << endl;
		}

		cout << "Enter another account? (y/n): ";
		cin >> another;
		cin.ignore();
		cout << endl;
	}

	display_accounts(accounts);
}