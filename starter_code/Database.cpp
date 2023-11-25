#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;

namespace Records {

	Employee& Database::addEmployee(const string& firstName,
		const string& lastName)
	{
		Employee theEmployee(firstName, lastName);
		theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
		theEmployee.hire();
		mEmployees.push_back(theEmployee);

		return mEmployees[mEmployees.size() - 1];
	}

	Employee& Database::getEmployee(int employeeNumber)
	{
		for (auto& employee : mEmployees) {
			if (employee.getEmployeeNumber() == employeeNumber) {
				return employee;
			}
		}
		throw logic_error("No employee found.");
	}

	Employee& Database::getEmployee(const string& firstName, const string& lastName)
	{
		for (auto& employee : mEmployees) {
			if (employee.getFirstName() == firstName &&
				employee.getLastName() == lastName) {
					return employee;
			}
		}
		throw logic_error("No employee found.");
	}

	void Database::displayAll() const
	{
		for (const auto& employee : mEmployees) {
			employee.display();
		}
	}

	void Database::displayCurrent() const
	{
		for (const auto& employee : mEmployees) {
			if (employee.isHired())
				employee.display();
		}
	}

	void Database::displayFormer() const
	{
		for (const auto& employee : mEmployees) {
			if (!employee.isHired())
				employee.display();
		}
	}
 // Function to generate a unique address
    std::string Database::generateUniqueAddress()
    {
        static int uniqueAddressCounter = 0;
        return "Address" + std::to_string(uniqueAddressCounter++);
    }

    // Function to generate a new database with sample data
    void Database::generateNewDatabase()
    {
        const std::vector<std::string> firstNames = {
            "John", "Jane", "Michael", "Emily", "David", "Mary", "James", "Sarah", "Robert", "Jennifer"};
        const std::vector<std::string> middleNames = {
            "Lee", "Ann", "William", "Grace", "Joseph", "Elizabeth", "Charles", "Linda", "Thomas", "Susan"};
        const std::vector<std::string> lastNames = {
            "Smith", "Johnson", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor", "Anderson", "Thomas"};
        int employeeNumber = kFirstEmployeeNumber;
        for (const std::string& firstName : firstNames) {
            for (const std::string& middleName : middleNames) {
                for (const std::string& lastName : lastNames) {
                    std::string address = generateUniqueAddress(); 
                    addEmployee(firstName, lastName,middleName,address);
                }
            }
        }
    }


}
