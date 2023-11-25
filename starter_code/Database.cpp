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
// Function to save the database to a file
    void Database::saveToFile(const std::string& fileName)
    {
        std::ifstream fileExists(fileName);
        if (fileExists) {
            std::string overwrite;
            std::cout << "The file already exists. Do you want to overwrite it? (yes/no): ";
            std::cin >> overwrite;

            if (overwrite != "yes") {
                std::cout << "File not saved." << std::endl;
                return;
            }
        }

        std::ofstream outFile(fileName);

        if (!outFile) {
            std::cerr << "Unable to open the file: " << fileName << std::endl;
            return;
        }

        for (const Employee& emp : mEmployees) {
            outFile << "First Name: " << emp.getFirstName() << std::endl;
            outFile << "Last Name: " << emp.getLastName() << std::endl;
            outFile << "Middle Name: " << emp.getMiddleName() << std::endl; // Save middle name
            outFile << "Address: " << emp.getAddress() << std::endl; // Save address
            outFile << "Employee Number: " << emp.getEmployeeNumber() << std::endl;
            outFile << "Salary: " << emp.getSalary() << std::endl;
            outFile << "Hired: " << (emp.isHired() ? "Yes" : "No") << std::endl;
            outFile << "----------------------" << std::endl;
        }

        std::cout << "The database has been saved to the file: " << fileName << std::endl;
        outFile.close();
    }

    // Function to load the database from a file
    void Database::loadFromFile(const std::string& fileName)
    {
        std::ifstream inFile(fileName);

        if (!inFile) {
            std::cerr << "Unable to open the file: " << fileName << std::endl;
            return;
        }

        // Clear existing data in the database
        mEmployees.clear();

        std::string line;
        Employee currentEmployee;

        while (std::getline(inFile, line)) {
            // Parse employee data from the file
            std::string fieldName;
            std::string fieldValue;

            std::istringstream lineStream(line);
            std::getline(lineStream, fieldName, ':');
            std::getline(lineStream, fieldValue);

            // Remove leading and trailing whitespace from the field value
            fieldValue.erase(fieldValue.find_last_not_of(" \t") + 1);
            fieldValue.erase(0, fieldValue.find_first_not_of(" \t"));

            if (fieldName == "First Name") {
                currentEmployee.setFirstName(fieldValue);
            } else if (fieldName == "Last Name") {
                currentEmployee.setLastName(fieldValue);
            } else if (fieldName == "Middle Name") {
                currentEmployee.setMiddleName(fieldValue); // Load middle name
            } else if (fieldName == "Address") {
                currentEmployee.setAddress(fieldValue); // Load address
            } else if (fieldName == "Employee Number") {
                currentEmployee.setEmployeeNumber(std::stoi(fieldValue));
            } else if (fieldName == "Salary") {
                currentEmployee.setSalary(std::stoi(fieldValue));
            } else if (fieldName == "Hired") {
                currentEmployee.hire(); // Assume "Hired" means the employee is hired
            } else if (fieldName == "----------------------") {
                // End of an employee record, add it to the database
                mEmployees.push_back(currentEmployee);
                currentEmployee = Employee(); // Clear employee data for the next record
            }
        }

        std::cout << "The database has been loaded from the file: " << fileName << std::endl;
        inFile.close();
    }

// Function to edit an employee's information
    void Database::editEmployee(const std::string& firstName, const std::string& lastName)
    {
        for (Employee& emp : mEmployees) {
            if (emp.getFirstName() == firstName && emp.getLastName() == lastName) {
                emp.editEmployee(); // Call the editEmployee function for the selected employee
                std::cout << "Employee information updated." << std::endl;
                return;
            }
        }

        std::cerr << "Employee not found." << std::endl;
    }

    // Function to search employees by partial first name
    void Database::searchEmployeesByName()
    {
        std::string searchText;
        std::cout << "Enter a partial first name to search for: ";
        std::cin.ignore(); // Clear the newline character
        std::getline(std::cin, searchText);

        bool found = false;

        for (const Employee& emp : mEmployees) {
            std::string textToSearch = emp.getFirstName();

            // Perform partial text matching search
            if (textToSearch.find(searchText) != std::string::npos) {
                emp.display(); // Display the employee information
                found = true;
            }
        }

        if (!found) {
            std::cout << "No employees found matching the search criteria." << std::endl;
        }
    }

    // Function to search employees by partial middle name
    void Database::searchEmployeesByMiddleName()
    {
        std::string searchText;
        std::cout << "Enter a partial middle name to search for: ";
        std::cin.ignore(); // Clear the newline character
        std::getline(std::cin, searchText);

        bool found = false;

        for (const Employee& emp : mEmployees) {
            std::string textToSearch = emp.getMiddleName();

            // Perform partial text matching search
            if (textToSearch.find(searchText) != std::string::npos) {
                emp.display(); // Display the employee information
                found = true;
            }
        }

        if (!found) {
            std::cout << "No employees found matching the search criteria." << std::endl;
        }
    }

}
