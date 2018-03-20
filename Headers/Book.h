#pragma once

class Book;

#include <map>
#include <string>
#include <cstdint>
#include "Date.h"
#include "Employee.h"
#include "PriorityQueue.h"

class Book
{
private:
	std::string _name;
	bool _isArchived;

	Date _circulationStartDate, _circulationEndDate;

	PriorityQueue<Employee> _empQueue;
	std::map<uint32_t, uint32_t> _retainTimes;
public:
	Book(std::string name);

	void pushEmployee(Employee& e);
	void popEmployee();

	Employee frontEmployee();

	bool isArchived();

	Date getEndDate();
	Date getStartDate();
	std::string getName();

	bool operator==(const Book& rhs) const;
	bool operator<(const Book& rhs) const;
};
