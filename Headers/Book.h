#ifndef BOOK_H
#define BOOK_H

#include "Date.h"
#include "Employee.h"
#include "StringTokenizer.h"
#include "PriorityQueue.h"
#include <string>

class Book
{
private:
	std::string _name;
	bool _isArchived;

	Date _circulationStartDate, _circulationEndDate;
	PriorityQueue<Employee> _empQueue;

public:
	Book(std::string name);

	void pushEmployee(Employee e);
	void popEmployee();

	Employee frontEmployee();

	void setArchived(bool value);
	bool isArchived();

	Date getEndDate();
	Date getStartDate();

	bool operator==(const Book& rhs) const;
};

#endif