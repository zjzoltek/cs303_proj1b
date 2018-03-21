#pragma once

class Book;

#include <map>
#include <string>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include "Date.h"
#include "Employee.h"
#include "PriorityQueue.h"

#define MAX_POSSIBLE_CIRCULATION_TIME 3
#define MAX_POSSIBLE_CIRCULATION_DELAY 3

#define RANDOM_NUMBER(low, high) low + rand() / (RAND_MAX / (high - low + 1) + 1)

class Book
{
private:
	static bool _employee_comparator(Employee * e1, Employee * e2)
	{
		return (e1->getTotalRetainTime() - e1->getWaitTime()) < (e2->getTotalRetainTime() - e2->getWaitTime());
	}

	std::string _name;

	bool _isArchived;
	bool _isFinished;

	Date _circulationStartDate, _circulationEndDate, _currentDate;

	PriorityQueue<Employee*> _empQueue;
	std::map<uint32_t, uint32_t> _retainTimes;

	Employee * _bookUser;
public:
	Book();
	Book(std::string name, Date currentDate);

	void pushEmployee(Employee& e);
	void popEmployee();

	Employee * frontEmployee();
	
	bool isArchived();
	bool isFinished();

	Date getEndDate();
	Date getStartDate();
	size_t getSizeOfWaitlist();

	void setCurrentDate(Date date);
	std::string getName();

	bool operator==(const Book& rhs) const;
	bool operator<(const Book& rhs) const;

	void tick();
};

