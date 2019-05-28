/*
Add employees, full time (monthly salary), part time (daily salary)
*/

#include "functions.hpp"

using namespace std;

int main()
{

	int option;

	vector<Full_time_employee> full_time_employees;
	vector<Part_time_employee> part_time_employees;
	vector<Intern_employee> intern_employees;

	cout << "Welcome to employee database system program\n\n";

	while (true)
	{

		cout << "General navigation:\n\n";
		cout << "1: Add employee" << '\n';
		cout << "2: Show employees" << '\n';
		cout << "3: Change value(s)" << '\n';
		cout << "4: Delete employees" << '\n';
		cout << "5: Show statistics" << '\n';
		cout << "-1: End program" << '\n';

		option = get_and_validate_conversion(vector<int>{ 1, 2, 3, 4, 5, -1 }, "Please, pick option: ");

		if(option == -1)
		    break;

		cout << "\n\n";

        switch(option) {

            /* ADDING EMPLOYEES */

            case 1:
            {

                // 1 - Full time employee, 2 - Part time, 3 - Intern, -1 - step back
                option = get_add_option(option);

                if(option == -1)
                    break;

                string message = "How many employees to add? (-1 to step back): ";
                int q = get_and_validate_conversion(vector<int>{}, message);

                for (int i = 0; i < q; i++) {
                    switch (option)
                    {
                        case 1:
                            full_time_employees.push_back(add_emp<Full_time_employee>(1));
                            cout << "Full time employee added successfully" << '\n';
                            break;
                        case 2:
                            part_time_employees.push_back(add_emp<Part_time_employee>(2));
                            cout << "Part time employee added successfully" << '\n';
                            break;
                        case 3:
                            intern_employees.push_back(add_emp<Intern_employee>(3));
                            cout << "Internship employee added successfully" << '\n';
                            break;

                        default:
                            continue;
                    }

                    cout << '\n';
                }

                cout << '\n';

                break;

            }
                /* ----------------- */


                /* SHOWING EMPLOYEES */

            case 2:
            {

                option = get_showing_option();
                if(option == -1)
                    break;

                switch (option) {
                    case 1:
                        show_all_emp(full_time_employees, part_time_employees, intern_employees);
                        break;
                    case 2:
                        show_n_emp();
                        break;
                    case 3:
                        show_by_id();
                        break;
                    case 4:
                        show_by_name();
                        break;
                    default:
                        continue;
                }

                break;
            }

                /* ------------------- */


                /* CHANGING VALUES OF EMPLOYEES */

            case 3:
            {
                option = get_changing_option();

                if(option == -1)
                    break;

                switch (option)
                {
                    case 1:
                        change_id_emp();
                        break;
                    case 2:
                        change_name_emp();
                    case 3:
                        change_salary_emp();
                    default:
                        continue;
                }

                break;
            }

                /* --------------------------- */


                /* DELETING EMPLOYEES */

            case 4:
            {
                option = get_deleting_option();

                if(option == -1)
                    break;

                switch (option) {
                    case 1:
                        delete_one_emp();

                    case 2:
                        delete_multiple_emp();

                    case 3:
                        while (true) {
                            cout << "Warning, this action will wipe out entire database" << '\n';
                            cout << "Do you want to proceed? (y/n)";

                            string warning;
                            cin >> warning;

                            if ((warning == "y") || (warning == "Y") || (warning == "1")) {
                                wipe_all_emp();
                            }

                            if ((warning == "n") || (warning == "N") || (warning == "0")) {
                                break;
                            }
                        }

                    default:
                        continue;

                }

                break;
            }

                /* ----------------- */


                /* SHOWING STATS */

            case 5: {
                show_stats();
                break;
            }

            default:
                continue;

            /* ------------- */
        }

    }

    cout << "Thank you for using me ;)" << '\n';

    return 0;
}
