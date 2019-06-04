#include "classes.hpp"
#include <string>
#include <vector>
#include <limits>


void print_vector(vector<int>& vec)
{
	cout << "{ ";
	for (int i : vec) {
		cout << i << ", ";
	}

	cout << "}";
}


/* Gets string from input, converts to int, validates conversion. 

	Args:
	valid_options - all options, that are acceptable, function asks you until it gets one of the options
	- if empty argument given, function doesn't check for valid options, just gets input and converts

 	message - message to display after every failed try
 */

int get_and_validate_conversion(vector<int> valid_options = {}, const string& message="")
{
	int option = 1;
	int continue_looping = 1;

	while (continue_looping)
	{

		cout << message;
		cin >> option;

		try
		{
			if (cin.fail()) {
				throw "error";
			}

		}
		catch (...)
		{
			cin.clear(); // Clear error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
			cout << "Bad option format, should be whole number\n";
			continue;
		}

		// doesn't care about valid options
		if (valid_options.empty())
			break;

		for (int valid_option : valid_options) {
			if (option == valid_option)
			{
				continue_looping = 0;
				break;
			}
		}

		if (continue_looping == 1)
		{
			cout << "Invalid option, should be "; 
			print_vector(valid_options);
			cout << " please, try again\n";
			continue;
		}
	}

	return option;
}


/* ADDING EMPLOYEES */


vector<int> used_ids;


int get_add_option(int option)
{
    cout << "Which employee to add?\n\n";
    cout << "1: Full time employee" << '\n';
    cout << "2: Part time employee" << '\n';
    cout << "3: Internship employee" << '\n';
    cout << "-1: Step back" << '\n';

	string message = "Please, pick an option: ";
	option = get_and_validate_conversion(vector<int>{1, 2, 3, -1}, message);
	cout << '\n';

    return option;
}


template <class T>
T add_emp(int option)
{

    int id = 0, keep_looping=1;
    string name; 
    float salary;

	if (option == 1)
		cout << "\nYou're adding a new Full time employee" << '\n';
	else if (option == 2)
		cout << "\nYou're adding a new Part time employee" << '\n';
	else if (option == 3)
		cout << "\nYou're adding a new Internship employee" << '\n';

    while(keep_looping)
    {
    	string message = "Enter id: ";
    	id = get_and_validate_conversion(vector<int>{}, message);

		keep_looping = 0;

		for (int used_id : used_ids) {
			if (id == used_id)
			{
				cout << "This id has already been used, please enter new.\n\n";
				keep_looping = 1;
			}
		}
    }

	used_ids.push_back(id);

    cout << "Enter name: ";
	cin.ignore();
	getline(cin, name);

	string message;

    // Full time employee
    if (option == 1)
		message = "Enter monthly salary: ";
	// Part time
	else if(option == 2)
		message = "Enter daily salary: ";
	// Intern
	else if(option == 3)
		message = "Enter hourly salary: ";

	salary = get_and_validate_conversion(vector<int>{}, message);

    return T(id, name, salary);
}


/* ---------------- */


/* SHOWING EMPLOYEES */

template <typename T>
/* int i -> current index of showing
 * T - vector of employee objects (full time, part time, intern)
 * int option -> 1 - show message of printing full time employees
 *               2 - part time
 *               3 - intern
 */
void show_empl(int i, vector<T> &empl, int option)
{
    if(empl.empty())
    {
        if(option == 1)
            cout << "No Full time employees.\n\n";
        else if(option == 2)
            cout << "No Part time employees.\n\n";
        else if(option == 3)
            cout << "No Internship employees.\n\n";
    }
    else
    {
        if(i > empl.size())
        {
            cout << empl[i] << '\n';
        }
    }
}


int get_showing_option()
{
	int option;

	cout << "You're in the showing employee(s) section\n\n";
	cout << "1: Show all employees" << '\n';
	cout << "2: Show first n employees" << '\n';
	cout << "3: Show employee by id (in development)" << '\n';
	cout << "4: Show employee by name (in development)" << '\n';
	cout << "-1: Step back" << '\n';

	string message = "Please, pick an option: ";
	option = get_and_validate_conversion(vector<int>{1, 2, 3, 4, -1}, message);

	cout << "\n\n";

	return option;
}


void show_all_emp(vector<Full_time_employee>& full, vector<Part_time_employee>& part, vector<Intern_employee>& intern)
{
	cout << "\n\n";
	cout << "#################################";
    cout << "\n\nDisplaying Full time employees:\n\n";

    if(full.empty())
	{
    	cout << "No Full time employees\n\n";
	}
    else
    {
		for (auto f: full) {
			cout << f;
			cout << '\n';
		}
	}

    cout << "#################################";

    cout << "\n\nDisplaying Part time employees:\n\n";

    if(part.empty())
	{
		cout << "No Part time employees\n\n";
	}
    else
    {
		for (auto p: part) {
			cout << p;
			cout << '\n';
		}
	}

    cout << "##################################";

    cout << "\n\nDisplaying Internship employees:\n\n";

	if(intern.empty())
	{
		cout << "No Internship employees\n\n";
	}
	else
	{
		for (auto i: intern) {
			cout << i;
			cout << '\n';
		}
	}

	cout << "##################################\n\n";
}


void show_n_emp(vector<Full_time_employee>& full, vector<Part_time_employee>& part, vector<Intern_employee>& intern)
{
    cout << "Which employee to show?\n\n";
    cout << "1: Full time employee" << '\n';
    cout << "2: Part time employee" << '\n';
    cout << "3: Internship employee" << '\n';
    cout << "4: All employees " << '\n';
    cout << "-1: Step back" << '\n';

    string message = "Please, pick an option: ";
    int option = get_and_validate_conversion(vector<int>{1, 2, 3, 4, -1}, message);
    cout << '\n';

    string message2 = "How many to show? ";
    int how_many_show = get_and_validate_conversion(vector<int>{}, message2);

    cout << "##################################\n\n";

    int kill = 0;

    if(full.size() + part.size() + intern.size() == 0)
    {
        cout << "No employees! \n\n";
    }
    else
    {
        for(int i=0; i<how_many_show; i++)
        {
            if(kill == 1)
                break;

            switch(option) {
                case 1: {
                    show_empl(i, full, 1);

                    if (i >= full.size()) {
                        cout << "##################################\n\n";
                        kill = 1;
                        break;
                    }
                    break;
                }
                case 2: {
                    show_empl(i, part, 2);

                    if (i >= part.size()) {
                        cout << "##################################\n\n";
                        kill = 1;
                        break;
                    }
                    break;
                }
                case 3: {
                    show_empl(i, intern, 3);

                    if (i >= intern.size()) {
                        cout << "##################################\n\n";
                        kill = 1;
                        break;
                    }
                    break;
                }
                case 4: {
                    if (i <= full.size()) // <= because when there are none employees, we want to print that.
                        show_empl(i, full, 1);
                    else if (i <= full.size() + part.size())
                        show_empl(i, part, 2);
                    else if (i <= full.size() + part.size() + intern.size())
                        show_empl(i, intern, 3);

                    // when to divide the sections
                    if ((i == full.size()) || (i == full.size() + part.size()) ||
                        (i == full.size() + part.size()) + intern.size())
                        cout << "##################################\n\n";

                    if (i == i <= full.size() + part.size() + intern.size()) {
                        kill = 1;
                        break;
                    }
                    break;
                }
            }
        }
    }
}


void show_by_id()
{

}


void show_by_name()
{

}


/* ---------------- */


/* CHANGE VALUE OF EMPLOYEES */


int get_changing_option()
{
	int option;

	cout << "You're in the change value of employee section (no yet)\n\n";
	cout << "1: Change id (not yet)" << '\n';
	cout << "2: Change name (not yet)" << '\n';
	cout << "3: Change salary (not yet)" << '\n';
	cout << "-1: Step back (not yet)" << '\n';

	option = get_and_validate_conversion(vector<int>{1, 2, 3, -1});

	cout << "\n\n";

	return option;
}


void change_id_emp()
{

}


void change_name_emp()
{

}


void change_salary_emp()
{

}


/* -------------------------- */

/* DELETE EMPLOYEE */

int get_deleting_option()
{
	int option;

	cout << "You're in the delete employee section\n\n";
	cout << "1: Delete 1 employee" << '\n';
	cout << "2: Delete multiple employees" << '\n';
	cout << "3: Delete all employees (warning)" << '\n';
	cout << "-1: Step back" << '\n';
	cout << "Please, choose option:" << '\n';

	option = get_and_validate_conversion(vector<int>{1, 2, 3, -1});

	cout << '\n';
	
	return option;
}


void delete_one_emp()
{

}


void delete_multiple_emp()
{

}


void wipe_all_emp()
{

}


/* SHOW STATISTICS */

void show_stats()
{

}

/* --------------- */
