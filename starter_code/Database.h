#pragma once

#include <iostream>
#include <vector>
#include "Employee.h"

namespace Records {
	const int kFirstEmployeeNumber = 1000;

	class Database
	{
	public:
		Employee& addEmployee(const std::string& firstName,
							  const std::string& lastName);
		Employee& getEmployee(int employeeNumber);
		Employee& getEmployee(const std::string& firstName,
							  const std::string& lastName);

		void displayAll() const;
		void displayCurrent() const;
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
		std::vector<Employee> mEmployees;
		int mNextEmployeeNumber = kFirstEmployeeNumber;
	};
}
