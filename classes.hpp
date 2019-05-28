#include <iostream>
#include <string>
#include <ctime>

using namespace std;


class Employee
{
private:
    int id;
    string name;
    float salary;

public:

    Employee(int id, string& name, float salary)
    {
        this->id = id;
        this->name = name;

        if(salary >=0)
            this->salary = salary;
        else
            this->salary = -1;
    }

    void setId(int i){ id = i; }
    void setName(string s){ name = s; }
    void setSalary(float s){ salary = s; }

    int getId(){ return id; }
    string getName(){ return name; }
    float getSalary(){ return salary; }

    int get_current_month();

};


// Full time means monthly salary
class Full_time_employee : public Employee
{

public:

    explicit Full_time_employee(int id, string name="Unspecified Full time", float salary=-1) : Employee(id, name, salary){}

    float convert_salary_to_daily()
    {
        return getSalary() / get_current_month();
    }

    float convert_salary_to_hourly()  // 8 hours a day
    {
        return convert_salary_to_daily() / 8.0f;
    }

    // printing Full time employee
    friend ostream &operator<<(ostream &out, Full_time_employee &f);
};


// Part time means daily salary
class Part_time_employee : public Employee
{

public:

    explicit Part_time_employee(int id, string name="Unspecified Part time", float salary=-1) : Employee(id, name, salary){}

    float convert_salary_to_monthly()
    {
        return getSalary() * get_current_month();
    }

    float convert_salary_hourly()  // 8 hours a day
    {
        return getSalary() / 8.0f;
    }

    // printing part time employee
    friend ostream &operator<<(ostream &out, Part_time_employee &p);
};


// Intern means hourly salary
class Intern_employee : public Employee
{

public:
    Intern_employee(int id, string name="Unspecified Intern", float salary=-1) : Employee(id, name, salary){}

    float convert_salary_to_daily()
    {
        return getSalary() * 8.0f;
    }

    float conver_salary_to_monthly()
    {
        return convert_salary_to_daily() * get_current_month();
    }

    // printing part time employee
    friend ostream &operator<<(ostream &out, Intern_employee &p);
};


int Employee::get_current_month()
{
    tm* my_time;

    //get current time in format of time_t
    time_t t = time(NULL);

    //convert time_t to tm
    my_time = localtime(&t);

    int month = my_time->tm_mon;

    return month;
}


// FULL TIME EMPLOYEE


// printing employee full time
ostream &operator<<(ostream &out, Full_time_employee &f)
    {
        out << "Id: " << f.getId() << '\n'
            << "Name: " << f.getName() << '\n'
            << "Monthly salary: " << f.getSalary() << '\n';
        return out;
    }


// -------------------


// PART TIME EMPLOYEE


// printing part time employee
ostream &operator<<(ostream &out, Part_time_employee &p)
    {
        out << "Id: " << p.getId() << '\n'
            << "Name: " << p.getName() << '\n'
            << "Daily wage: " << p.getSalary() << '\n';
        return out;
    }


// ------------------


// INTERNSHIP EMPLOYEE


// printing intern employee
ostream &operator<<(ostream &out, Intern_employee &p)
    {
        out << "Id: " << p.getId() << '\n'
            << "Name: " << p.getName() << '\n'
            << "Hourly wage: " << p.getSalary() << '\n';
        return out;
    }


// ------------------
