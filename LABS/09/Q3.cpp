#include<iostream>
using namespace std;

class Employee{
protected:
    int employeeID;
    string employeeName;
public:
    Employee(int id, const string& name) : employeeID(id), employeeName(name) {}
    virtual ~Employee() {} 
    virtual double calculatePay() const = 0;
    virtual void displayDetails() const = 0;

};

class FullTimeEmployee : public Employee{
private:
    double monthlySalary;
public:
    FullTimeEmployee(int id, const string& name, double salary)
        : Employee(id, name), monthlySalary(salary) {}

    double calculatePay() const override{
        return monthlySalary;
    }
    void displayDetails() const override{
        cout << "Full Time Employee Details:" << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Employee Name: " << employeeName << endl;
        cout << "Employee Type: Full Time" << endl;
        cout << "Monthly Salary: " << monthlySalary << endl << endl;
    }
};

class PartTimeEmployee : public Employee{
private:
    double hourlyWage;
    int hoursWorked;
public:
    PartTimeEmployee(int id, const string& name, double wage, int hours)
        : Employee(id, name), hourlyWage(wage), hoursWorked(hours) {}

    double calculatePay() const override{
        return hourlyWage * hoursWorked;
    }
    void displayDetails() const override{
        cout << "Part Time Employee Details:" << endl;
        cout << "Employee ID: " << endl << employeeID << endl;
        cout << "Employee Name: " << employeeName << endl;
        cout << "Employee Type: Part Time" << endl;
        cout << "Hourly Wage: " << hourlyWage << endl;
        cout << "Hours Worked: " << hoursWorked << endl << endl;
    }
};

int main(){
    Employee *pE;
    Employee *fE;
    FullTimeEmployee f(1, "Rayyan", 5000);
    fE = &f;
    PartTimeEmployee p(2, "Rayyy", 100, 10);
    pE = &p;
    cout << "Displaying Details: " << endl;
    fE->displayDetails();
    pE->displayDetails();
    cout << "Calculating Pay: " << endl;
    cout << "Full Time Employee Pay: " << fE->calculatePay() << endl;
    cout << "Part Time Employee Pay: " << pE->calculatePay() << endl;
}

  
