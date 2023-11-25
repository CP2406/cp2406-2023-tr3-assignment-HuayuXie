// Employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

namespace Records {
    const int kDefaultStartingSalary = 30000;

    class Employee {
    public:
        Employee() = default;
        Employee(const std::string& firstName, const std::string& lastName,
                 const std::string& middleName, const std::string& Address);

        // Methods to promote and demote an employee's salary
        void promote(int raiseAmount = 1000);
        void demote(int demeritAmount = 1000);

        // Methods to hire and fire employees
        void hire(); // Hire or rehire an employee
        void fire(); // Fire an employee

        // Method to display employee information to the console
        void display() const;

        // Methods to set and get the first name
        void setFirstName(const std::string& firstName);
        const std::string& getFirstName() const;

        // Methods to set and get the last name
        void setLastName(const std::string& lastName);
        const std::string& getLastName() const;

        // Methods to set and get the employee number
        void setEmployeeNumber(int employeeNumber);
        int getEmployeeNumber() const;

        // Methods to set and get the salary
        void setSalary(int newSalary);
        int getSalary() const;

        // Method to check if the employee is hired
        bool isHired() const;

        // Methods to set and get the middle name
        void setMiddleName(const std::string& middleName);
        std::string getMiddleName() const;

        // Methods to set and get the address
        void setAddress(const std::string& address);
        std::string getAddress() const;

        // Method to edit employee information
        void editEmployee();

        void setLoginId(const std::string& loginId) { mLoginId = loginId; }
        const std::string& getLoginId() const { return mLoginId; }

        void setPassword(const std::string& password) { mPassword = password; }
        const std::string& getPassword() const { return mPassword; }

        void setIsManager(bool isManager) { mIsManager = isManager; }
        bool getIsManager() const { return mIsManager; }

    private:
        std::string mFirstName;         // First name
        std::string mLastName;          // Last name
        std::string mMiddleName;        // Middle name
        std::string mAddress;           // Address
        int mEmployeeNumber = -1;       // Employee number
        int mSalary = kDefaultStartingSalary; // Salary
        bool mHired = false;            // Whether the employee is hired
        std::string mLoginId;
        std::string mPassword;
        bool mIsManager = false;  // true for manager, false for regular employee
    };
}

#endif  // EMPLOYEE_H
