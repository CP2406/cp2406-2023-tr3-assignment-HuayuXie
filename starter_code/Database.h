#pragma once

#include <iostream>
#include <vector>
#include "Employee.h"

namespace Records {
    const int kFirstEmployeeNumber = 1000;

    class Database
    {
    public:
        // Add an employee to the database
        Employee& addEmployee(const std::string& firstName,
                              const std::string& lastName, const std::string& middleName, const std::string& Address);
        
        // Get an employee by employee number
        Employee& getEmployee(int employeeNumber);
        
        // Get an employee by first name and last name
        Employee& getEmployee(const std::string& firstName,
                              const std::string& lastName);

        // Display all employees
        void displayAll() const;
        
        // Display currently employed employees
        void displayCurrent() const;
        
        // Display former employees (not currently employed)
        void displayFormer() const;
        
        // Generate a new database with example data
        void generateNewDatabase();
        
        // Generate a unique address
        std::string generateUniqueAddress();

        // Save the database to a file
        void saveToFile(const std::string& fileName);
        
        // Load the database from a file
        void loadFromFile(const std::string& fileName);
        
        // Edit employee information by first name and last name
        void editEmployee(const std::string& firstName, const std::string& lastName);
        
        // Search employees by first name
        void searchEmployeesByName();
        
        // Search employees by middle name
        void searchEmployeesByMiddleName();
        
        // Search employees by last name
        void searchEmployeesByLastName();
        
        // Search employees by address
        void searchEmployeesByAddress();
        
        // Search employees by various criteria
        void searchEmployees();

		Employee* authenticate(const std::string& loginId, const std::string& password);

        void logDebug(const std::string& message);
        
    private:

        bool gDebugEnabled = false;  // Global debug flag

        std::vector<Employee> mEmployees;
        
        int mNextEmployeeNumber = kFirstEmployeeNumber;
    };
}
