#include <iostream>
#include <stdexcept>
#include <exception>
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);

int main()
{
	Database employeeDB;
    Employee& admin = employeeDB.addEmployee("Admin", "User","Admin", "SHANGHAI");
    admin.setLoginId("admin");
    admin.setPassword("admin");
    admin.setIsManager(true);

    Employee& user = employeeDB.addEmployee("Regular", "User","Regular", "BEIJING");
    user.setLoginId("user");
    user.setPassword("user");
    user.setIsManager(false);

    Employee* loggedInEmployee = nullptr;

    

    while (true) {
        std::string loginId, password;
        std::cout << "Login ID: ";
        std::cin >> loginId;
        std::cout << "Password: ";
        std::cin >> password;

        loggedInEmployee = employeeDB.authenticate(loginId, password);

        if (loggedInEmployee == nullptr) {
            break;
        }
        else 
        {
            // Check if the user is an administrator
            if (loggedInEmployee->getIsManager()) {
                std::cout << "Logged in as administrator." << std::endl;
                bool done = false;
                // Display the menu for administrators
                while (!done) {
                int selection = displayMenu();
                switch (selection) {
                case 0:
                    done = true;
                    break;
                case 1:
                    doHire(employeeDB);
                    break;
                case 2:
                    doFire(employeeDB);
                    break;
                case 3:
                    doPromote(employeeDB);
                    break;
                case 4:
                    employeeDB.displayAll();
                    break;
                case 5:
                    employeeDB.displayCurrent();
                    break;
                case 6:
                    employeeDB.displayFormer();
                    break;
                case 7:
                    employeeDB.generateNewDatabase();
                    break;
                case 8:
                    {
                        std::string fileName;
                        std::cout << "Enter the file name to save: ";
                        std::cin >> fileName;
                        employeeDB.saveToFile(fileName); // Save the database to a file
                    }
                    break;
                case 9:
                    {
                        std::string fileName;
                        std::cout << "Enter the file name to load: ";
                        std::cin >> fileName;
                        employeeDB.loadFromFile(fileName); // Load database from a file
                    }
                    break;
                case 10:
                    {
                        std::string firstName, lastName;
                        std::cout << "Enter the first name of the employee you want to edit: ";
                        std::cin >> firstName;
                        std::cout << "Enter the last name of the employee you want to edit: ";
                        std::cin >> lastName;
                        employeeDB.editEmployee(firstName, lastName); // Edit an employee
                    }
                    break;
                case 11:
                    employeeDB.searchEmployees(); // Search for employees
                    break;
                default:
                    cerr << "Unknown command." << endl;
                    break;
                }
            }

            } else {
                std::cout << "Logged in as regular employee." << std::endl;
                // Display the menu for regular employees
                user.display();
            }
        }

    }
    
	

	return 0;
}

int displayMenu()
{
	// Note:
	//		One important note is that this code assumes that the user will
	//		"play nice" and type a number when a number is requested.
	//		When you read about I/O in Chapter 13, you will learn how to
	//		protect against bad input.

    int selection;

    cout << endl;
    cout << "Employee Database" << endl;
    cout << "-----------------" << endl;
    cout << "1) Hire a new employee" << endl;
    cout << "2) Fire an employee" << endl;
    cout << "3) Promote an employee" << endl;
    cout << "4) List all employees" << endl;
    cout << "5) List all current employees" << endl;
    cout << "6) List all former employees" << endl;
    cout << "7) Generate new database" << endl;
    cout << "8) save the database to a file" << endl;
    cout << "9) Load database from a file" << endl;
    cout << "10) Edit an employee" << endl;
    cout << "11) Search for employees" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";
    
	cin >> selection;
    
	return selection;
}

void doHire(Database& db)
{
    string firstName;
    string lastName;
    string middleName;
    string Address;

    cout << "First name? ";
    cin >> firstName;
    cout << "Last name? ";
    cin >> lastName;
    cout << "MiddleName name? ";
    cin >> middleName;
    cout << "Address? ";
    cin >> Address;

    db.logDebug("A new employee has been hired.");
    
    db.addEmployee(firstName, lastName,middleName,Address);
}

void doFire(Database& db)
{
    int employeeNumber;

    cout << "Employee number? ";
    cin >> employeeNumber;

    try {
        Employee& emp = db.getEmployee(employeeNumber);
        emp.fire();
        cout << "Employee " << employeeNumber << " terminated." << endl;
    } catch (const std::logic_error& exception) {
        cerr << "Unable to terminate employee: " << exception.what() << endl;
    }
}

void doPromote(Database& db)
{
    int employeeNumber;
    int raiseAmount;

    cout << "Employee number? ";
    cin >> employeeNumber;
    cout << "How much of a raise? ";
    cin >> raiseAmount;

    try {
        Employee& emp = db.getEmployee(employeeNumber);
        emp.promote(raiseAmount);
    } catch (const std::logic_error& exception) {
        cerr << "Unable to promote employee: " << exception.what() << endl;
    }
}
