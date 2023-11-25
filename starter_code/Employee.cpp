// Employee.cpp
#include "Employee.h"
#include <iostream>

using namespace std;

namespace Records {
    // Constructor to initialize employee information
    Employee::Employee(const std::string& firstName, const std::string& lastName,
        const std::string& middleName, const std::string& Address)
        : mFirstName(firstName)
        , mLastName(lastName)
        , mMiddleName(middleName)
        , mAddress(Address)
    {
    }

    // Promote an employee by raising their salary
    void Employee::promote(int raiseAmount)
    {
        setSalary(getSalary() + raiseAmount);
    }

    // Demote an employee by reducing their salary
    void Employee::demote(int demeritAmount)
    {
        setSalary(getSalary() - demeritAmount);
    }

    // Hire an employee
    void Employee::hire()
    {
        mHired = true;
    }

    // Fire an employee
    void Employee::fire()
    {
        mHired = false;
    }

    // Display employee information
    void Employee::display() const
    {
        cout << "Employee Information: " << getLastName() << ", " << getFirstName() << ", " << getMiddleName() << ", Address: " << getAddress() << endl;
        cout << "-------------------------" << endl;
        cout << (isHired() ? "Current Employee" : "Former Employee") << endl;
        cout << "Employee Number: " << getEmployeeNumber() << endl;
        cout << "Salary: $" << getSalary() << endl;
        cout << endl;
    }

    // Set and get first name methods
    void Employee::setFirstName(const string& firstName)
    {
        mFirstName = firstName;
    }

    const string& Employee::getFirstName() const
    {
        return mFirstName;
    }

    // Set and get last name methods
    void Employee::setLastName(const string& lastName)
    {
        mLastName = lastName;
    }

    const string& Employee::getLastName() const
    {
        return mLastName;
    }

    // Set and get employee number methods
    void Employee::setEmployeeNumber(int employeeNumber)
    {
        mEmployeeNumber = employeeNumber;
    }

    int Employee::getEmployeeNumber() const
    {
        return mEmployeeNumber;
    }

    // Set and get salary methods
    void Employee::setSalary(int salary)
    {
        mSalary = salary;
    }

    int Employee::getSalary() const
    {
        return mSalary;
    }

    // Check if the employee is hired
    bool Employee::isHired() const
    {
        return mHired;
    }

    // Set and get middle name methods
    void Employee::setMiddleName(const std::string& middleName)
    {
        mMiddleName = middleName;
    }

    std::string Employee::getMiddleName() const
    {
        return mMiddleName;
    }

    // Set and get address methods
    void Employee::setAddress(const std::string& address)
    {
        mAddress = address;
    }

    std::string Employee::getAddress() const
    {
        return mAddress;
    }

    // Edit employee information based on user input
    void Employee::editEmployee()
    {
        int choice;
        std::cout << "Select what you want to edit for this employee:" << std::endl;
        std::cout << "1) Address" << std::endl;
        std::cout << "2) Salary" << std::endl;
        std::cout << "3) Employment Status" << std::endl;
        std::cout << "Enter your choice (1/2/3): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter new address: ";
            std::cin.ignore(); // Clear the newline character
            std::getline(std::cin, mAddress); // Update the address
            break;
        case 2:
            std::cout << "Enter new salary: ";
            std::cin >> mSalary; // Update the salary
            break;
        case 3:
            std::cout << "Change employment status (0 for not hired, 1 for hired): ";
            std::cin >> mHired; // Update the employment status
            break;
        default:
            std::cout << "Invalid choice. No changes were made." << std::endl;
        }
    }

}
