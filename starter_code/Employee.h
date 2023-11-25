#pragma once

#include <string>

namespace Records {
	const int kDefaultStartingSalary = 30000;

	class Employee
	{
	public:
		Employee() = default;
		Employee(const std::string& firstName, const std::string& lastName);

		void promote(int raiseAmount = 1000);
		void demote(int demeritAmount = 1000);
		void hire(); // Hires or rehires the employee
		void fire(); // Dismisses the employee
		void display() const;// Outputs employee info to console

		// Getters and setters
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setEmployeeNumber(int employeeNumber);
		int getEmployeeNumber() const;

		void setSalary(int newSalary);
		int getSalary() const;

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
		std::string mFirstName;
		std::string mLastName;
  std::string mMiddleName;        // Middle name
        std::string mAddress;           // Address
		int mEmployeeNumber = -1;
		int mSalary = kDefaultStartingSalary;
		bool mHired = false;
	};
}

